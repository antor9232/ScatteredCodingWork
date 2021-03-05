#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = { 10169426447220794115ULL, 15150196828545850890ULL, 13001907872575972229ULL,  6370335364031771293ULL, 12918652330241734109ULL,  4840366899441669462ULL,  7698778564917694954ULL, 14446246365437853765ULL,  6189657173220721238ULL, 16916950862783389448ULL, 13464369558061849724ULL,  9109969682510404643ULL, 10299301026000316473ULL, 15161036645277825200ULL, 11311701386425279890ULL,  1156745020272805814ULL,  8521627984037963366ULL,  2549669676950500832ULL, 11092801176342068525ULL, 12579593709593096873ULL};
ui64         judgeWSIgnoreHash[] = { 10153303173134642681ULL, 16369702687684457950ULL,  2009209119528192675ULL, 17832879061372774537ULL,   704195460451943407ULL, 10648665019658402006ULL,   653002135639921714ULL, 14243182764178592437ULL, 17358899650420150412ULL,  9123707186349204842ULL, 15190926168126134738ULL, 17795026042226400951ULL,  9421084737741506751ULL, 12575249957866026776ULL,   473085823682520778ULL, 10635646715843694388ULL,  1716919991147999800ULL, 15616764167682432348ULL,  6483026591043924129ULL, 17182669925538512059ULL};
ui64    judgeWS_CaseIgnoreHash[] = { 10153303173134642681ULL, 16369702687684457950ULL,  2009209119528192675ULL, 17832879061372774537ULL,   704195460451943407ULL, 10648665019658402006ULL,   653002135639921714ULL, 14243182764178592437ULL, 17358899650420150412ULL,  9123707186349204842ULL, 15190926168126134738ULL, 17795026042226400951ULL,  9421084737741506751ULL, 12575249957866026776ULL,   473085823682520778ULL, 10635646715843694388ULL,  1716919991147999800ULL, 15616764167682432348ULL,  6483026591043924129ULL, 17182669925538512059ULL};

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
	check(20);
	return 0;
}
