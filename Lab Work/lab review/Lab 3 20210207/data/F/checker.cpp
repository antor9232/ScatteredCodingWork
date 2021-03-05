#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = {  1215935104932383037ULL,  3153879990466204706ULL,  6839867295895415092ULL,  9893077404448919890ULL,  3789427433319913741ULL,  6644713358288520895ULL, 13412119478921964957ULL, 16259070700536769557ULL,  1615986615293896294ULL, 17588786603200846578ULL};
ui64         judgeWSIgnoreHash[] = {  5578792148718661773ULL, 11632776554311748756ULL, 14436425072158752806ULL,  7351657758783378726ULL, 12781114235207702385ULL, 10140352099479830845ULL, 11032971598290086859ULL, 14076847183411338267ULL,  8288631982369472258ULL, 10164899335660761490ULL};
ui64    judgeWS_CaseIgnoreHash[] = {  5578792148718661773ULL, 11632776554311748756ULL, 14436425072158752806ULL,  7351657758783378726ULL, 12781114235207702385ULL, 10140352099479830845ULL, 11032971598290086859ULL, 14076847183411338267ULL,  8288631982369472258ULL, 10164899335660761490ULL};

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
