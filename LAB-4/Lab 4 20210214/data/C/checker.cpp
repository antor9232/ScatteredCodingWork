#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = { 18073433300775532192ULL,  8607731206798265402ULL,  8036429008875412706ULL, 17736920270850133932ULL, 11679991116682549370ULL,  6329999447087681636ULL,  8641892835956625225ULL, 13756913959425484839ULL, 14696255926387485939ULL, 10029994581090287724ULL,  1503150974778609709ULL,  4900991659872304290ULL,  9115682032616703530ULL, 16067102052866967220ULL,  6696333118415612918ULL,  6329984261769214157ULL, 14217566447017566717ULL, 15481315988878663645ULL, 11821362567256924253ULL, 10995662618709232559ULL};
ui64         judgeWSIgnoreHash[] = { 15678122740403655412ULL, 12876399693206465886ULL, 16467108989674347792ULL, 13805300778004780432ULL,  9756301115935376676ULL, 15087619192135329448ULL,  1211900553059810275ULL,  3232328201140911997ULL,  5857617798899963831ULL,  2656812117620467858ULL, 17043910334963392331ULL,  8509448509648557668ULL, 15507625227350829290ULL, 11346824651978493082ULL, 13706538769366544090ULL,  9461755378993812867ULL, 13140830119022211821ULL, 14858029404052906769ULL, 16385709267487491025ULL, 17606041056729371207ULL};
ui64    judgeWS_CaseIgnoreHash[] = { 15678122740403655412ULL, 12876399693206465886ULL, 16467108989674347792ULL, 13805300778004780432ULL,  9756301115935376676ULL, 15087619192135329448ULL,  1211900553059810275ULL,  3232328201140911997ULL,  5857617798899963831ULL,  2656812117620467858ULL, 17043910334963392331ULL,  8509448509648557668ULL, 15507625227350829290ULL, 11346824651978493082ULL, 13706538769366544090ULL,  9461755378993812867ULL, 13140830119022211821ULL, 14858029404052906769ULL, 16385709267487491025ULL, 17606041056729371207ULL};

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
