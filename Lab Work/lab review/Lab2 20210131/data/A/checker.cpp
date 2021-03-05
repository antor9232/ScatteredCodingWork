#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = { 16120507809699776678ULL,  9907153096525375818ULL,  9278173598851966858ULL,  1549390293429717198ULL,  9278173598851966858ULL,  5596025639280909898ULL, 12940637710535201162ULL, 10655876279287624522ULL, 17411991785271859862ULL, 10603867138347918858ULL};
ui64         judgeWSIgnoreHash[] = { 17172821638148579168ULL, 18001822285941207528ULL,  1128313172264111552ULL, 15697264385028770696ULL,  1128313172264111552ULL,  5912610878954902856ULL,   130309442058941568ULL, 15475700353592285352ULL,  6256065018738633296ULL, 16778301577186059120ULL};
ui64    judgeWS_CaseIgnoreHash[] = { 17172821638148579168ULL, 18001822285941207528ULL,  1128313172264111552ULL, 15697264385028770696ULL,  1128313172264111552ULL,  5912610878954902856ULL,   130309442058941568ULL, 15475700353592285352ULL,  6256065018738633296ULL, 16778301577186059120ULL};

bool isWS(char c){
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

ui64 findHash(char filename[], int flag = ACTUAL){
    FILE *fp = fopen(filename,"r");
    ui64 p = 1000000007;
    char c;
    ui64 hash = 0, coeff = 1;
    while((c = fgetc(fp))!=EOF){
        if(isWS(c) && (flag & WSIG))continue;
        if(isalpha(c) && (flag & CSIG)) c = tolower(c);
        hash += (c * coeff);
        coeff *= p;
    }
    fclose(fp);
    return hash;
}

void check(int cs){
    int i;
    ui64 scHash;
    for(i = 1; i <= cs; i++){
        char file[100],infile[100],stsfile[100];
        sprintf(file,"%d.out",i);
        sprintf(infile,"%d.in",i);
        sprintf(stsfile,"%d.status",i);
        printf("Case %d: ",i);
        FILE *fp;
        int flag = 0;
        if((fp = fopen(infile, "r")) == NULL) flag = 1;
        if(flag) printf("Input File Missing!!!\n");
        else{
            FILE *stsfp = fopen(stsfile, "r");
            char sts[100];
            fgets(sts, 100, stsfp);
            if(strncmp(sts, "TLE", 3) == 0) printf("Time Limit Exceeded\n");
            else if(strncmp(sts, "timeout", 7) == 0) printf("Run Time Error\n");
            else if(strncmp(sts, "+Accepted", 8) == 0) printf("*********************PASSED***********************\n");
            else {
                scHash = findHash(file);
                if(scHash == judgeActualHash[i-1])printf("*********************PASSED***********************\n");
                else{
                    scHash = findHash(file, WSIG);
                    if(scHash == judgeWSIgnoreHash[i-1])printf("White Space Error\n");
                    else{
                        scHash = findHash(file, WSIG | CSIG);
                        if(scHash == judgeWS_CaseIgnoreHash[i-1])printf("Upper/Lower Case Error\n");
                        else printf("Failed\n");
                    }
                }
            }
        }
    }
}
int main(){
	check(10);
	return 0;
}
