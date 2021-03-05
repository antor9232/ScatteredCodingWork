#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = {  8558673529510264597ULL,  6397304542430528703ULL, 13498212581089139085ULL,  2061824913735069771ULL,  8146993204363747282ULL,  5840460355913911748ULL, 10523439000429835157ULL,  2617135605616059986ULL, 17742029809375957767ULL, 18250198468770364062ULL};
ui64         judgeWSIgnoreHash[] = { 12774580420548436843ULL,  7859881886133452857ULL, 17321159511591805447ULL,  2080964480472619749ULL,  1669850811446265064ULL,  9085105875519766778ULL,  9651047344046850447ULL, 14036379948761057832ULL,  6757013540320703137ULL, 12423235913644397428ULL};
ui64    judgeWS_CaseIgnoreHash[] = { 12774580420548436843ULL,  7859881886133452857ULL, 15227319910907169447ULL, 18114615372148931685ULL, 13813488021090625064ULL,  8922460993094997242ULL, 10456552001218936815ULL, 16253142182683995272ULL, 10494477741243708673ULL, 17138694553534657172ULL};

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
