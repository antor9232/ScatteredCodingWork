#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = {  4602584292901737583ULL,  4602584292901737583ULL,  4602584292901737583ULL,  4602584292901737583ULL,  4602584292901737583ULL, 15657818616409179960ULL,  4602584292901737583ULL,  4602584292901737583ULL,  4602584292901737583ULL,  4602584292901737583ULL};
ui64         judgeWSIgnoreHash[] = {  7339777964526727625ULL,  7339777964526727625ULL,  7339777964526727625ULL,  7339777964526727625ULL,  7339777964526727625ULL, 10748290617815418462ULL,  7339777964526727625ULL,  7339777964526727625ULL,  7339777964526727625ULL,  7339777964526727625ULL};
ui64    judgeWS_CaseIgnoreHash[] = {  7339777964526727657ULL,  7339777964526727657ULL,  7339777964526727657ULL,  7339777964526727657ULL,  7339777964526727657ULL, 13533195263280644382ULL,  7339777964526727657ULL,  7339777964526727657ULL,  7339777964526727657ULL,  7339777964526727657ULL};

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
