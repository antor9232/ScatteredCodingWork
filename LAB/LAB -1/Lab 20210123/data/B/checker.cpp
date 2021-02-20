#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = {  5366905256211195063ULL,  8061757362175982718ULL,  1293918122712819656ULL, 18277967651011946522ULL,  3190110164523121406ULL, 15795222770933334407ULL,  2237678310861664085ULL,  5624173495041344855ULL, 14713988640535735194ULL, 11816232032102427029ULL};
ui64         judgeWSIgnoreHash[] = {  2961109149704702229ULL,  1066227234723646894ULL, 13397545001874145254ULL,  5914131866892934260ULL,  1320582836990147564ULL, 10882796665947362529ULL, 13974245990449213257ULL,  6835315889794060641ULL, 18103354434858923754ULL, 14546987707307005561ULL};
ui64    judgeWS_CaseIgnoreHash[] = {  2961109149704702229ULL,  1066227234723646894ULL, 13397545001874145254ULL,  5914131866892934260ULL,  1320582836990147564ULL, 10882796665947362529ULL, 13974245990449213257ULL,  6835315889794060641ULL, 18103354434858923754ULL, 14546987707307005561ULL};

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
