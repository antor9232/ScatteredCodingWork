#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = { 12122920307453757163ULL,  4367634819145682422ULL, 10809104552206317994ULL,  9223573252459628847ULL,  5223573197459628659ULL, 16436736111701196529ULL, 12223573296459629008ULL, 16878205760761831808ULL, 13436736065701196353ULL, 13668381151189185238ULL, 17974067210874030453ULL,  6346800641060185958ULL, 13760607610596800115ULL,  3626350880111424628ULL, 14222318454865616213ULL, 16977735026586091445ULL,  2586030496150249684ULL, 14513972218662426754ULL,  3353327265692993700ULL, 13477751386228619809ULL};
ui64         judgeWSIgnoreHash[] = {  8830018297085573409ULL,  1074732808777498668ULL,  7516202541838134240ULL, 16106512646580899785ULL, 12106512591580899597ULL, 13143834101333012775ULL,   659768616871348330ULL, 13585303750393648054ULL, 10143834055333012599ULL, 17884288042227357484ULL,  3743230028202651083ULL, 10562707532098358204ULL, 17434392794892679597ULL,  7300136064407304110ULL, 17896103639161495695ULL, 17532551881816505387ULL,  6259815680446129166ULL, 18187757402958306236ULL,  7027112449988873182ULL, 17151536570524499291ULL};
ui64    judgeWS_CaseIgnoreHash[] = {  8830018297085573409ULL,  1074732808777498668ULL,  7516202541838134240ULL, 16106512646580899785ULL, 12106512591580899597ULL, 13143834101333012775ULL,   659768616871348330ULL, 13585303750393648054ULL, 10143834055333012599ULL, 17884288042227357484ULL,  3743230028202651083ULL, 10562707532098358204ULL, 17434392794892679597ULL,  7300136064407304110ULL, 17896103639161495695ULL, 17532551881816505387ULL,  6259815680446129166ULL, 18187757402958306236ULL,  7027112449988873182ULL, 17151536570524499291ULL};

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
