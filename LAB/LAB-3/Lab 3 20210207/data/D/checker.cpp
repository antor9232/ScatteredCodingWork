#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = { 11867723164334796869ULL, 10133781176599961240ULL,  2765311913758806223ULL, 15700610786258571779ULL,  2132709354927440311ULL, 11072042172987591419ULL, 10108714727165984952ULL,   136786758904617274ULL,  1482593199205852877ULL, 15540131204752023438ULL};
ui64         judgeWSIgnoreHash[] = { 12859191635617275567ULL,   657222141943212960ULL,  6091045951021668505ULL,  8275829786588338157ULL,  5833804686293289881ULL,  5577903993195897305ULL,  9543622236641114388ULL, 13966026992202284418ULL,  1524146615310927577ULL,  8985021801750135750ULL};
ui64    judgeWS_CaseIgnoreHash[] = {  3512720380228657391ULL,  2766108550006662400ULL,  4413546103467674361ULL,  2718270365503783917ULL, 18011964654344865081ULL,  6797017247990278265ULL,  2005572831136508148ULL,  2050336059748905570ULL,  8061700896340335257ULL, 13413879015223967526ULL};

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
