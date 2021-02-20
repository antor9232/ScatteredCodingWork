#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = { 10099732340385330763ULL, 16432569029966155880ULL,   121960862130235876ULL, 12468854466282909059ULL, 11277493995538778476ULL,  9808079301977747991ULL, 10069418102400328056ULL,  7509051164462813681ULL,  1790772628347262429ULL,  1488942701126907244ULL};
ui64         judgeWSIgnoreHash[] = { 11525114163627133047ULL,  7263095915669911826ULL,  9997995361185596436ULL, 16353161383773878925ULL, 16931974688409441852ULL,   971828174077241753ULL,  1048700413847724142ULL, 14510612612399097283ULL,  2815813226674310017ULL, 10463869471181888126ULL};
ui64    judgeWS_CaseIgnoreHash[] = { 11525114163627133047ULL,  7263095915669911826ULL,  9997995361185596436ULL, 16353161383773878925ULL, 16931974688409441852ULL,   971828174077241753ULL,  1048700413847724142ULL, 14510612612399097283ULL,  2815813226674310017ULL, 10463869471181888126ULL};

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
