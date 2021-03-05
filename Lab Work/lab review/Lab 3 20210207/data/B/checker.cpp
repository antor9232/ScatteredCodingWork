#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = { 16073931990339416977ULL, 16376838043192633384ULL, 12642269563757580508ULL, 15691023183727134988ULL, 11279228056450969225ULL,  8598434812312810512ULL,  1578235165140532451ULL, 13576165102513262236ULL, 10226649212065827939ULL,  4332646691044297497ULL};
ui64         judgeWSIgnoreHash[] = {  2101057780465103877ULL, 18059272043490320118ULL,  2214470872501100308ULL, 18087641397200529784ULL,  5650003244450084329ULL, 10310069350704895588ULL,  7545420712576490451ULL,  5035308490391948772ULL, 11736916059524590949ULL, 16825485819523016551ULL};
ui64    judgeWS_CaseIgnoreHash[] = {  2101057780465103877ULL, 18059272043490320118ULL,  2214470872501100308ULL, 18087641397200529784ULL,  5650003244450084329ULL, 10310069350704895588ULL,  7545420712576490451ULL,  5035308490391948772ULL, 11736916059524590949ULL, 16825485819523016551ULL};

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
