#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = {  1997300455212411340ULL, 15110624473976847840ULL,  9660309118160824408ULL, 17081029547695938318ULL,  6160286614842506132ULL,  7979398998057178838ULL, 12532655230347628252ULL,  2160286562842505961ULL,  7107052897870375006ULL,   701812506968890152ULL};
ui64         judgeWSIgnoreHash[] = { 14631333323467477522ULL,  5892288484170220432ULL,  6367407107792640654ULL,  1225301131641951592ULL,  2867384604474322378ULL,  4686496987688995084ULL,  9239753219979444498ULL, 17314128626183873823ULL,  3814150887502191252ULL, 15657880559852066080ULL};
ui64    judgeWS_CaseIgnoreHash[] = {  6622812401652168210ULL,  6348944113766665104ULL,  8963303897120754830ULL, 11663524283536193896ULL,  5463281393802436554ULL,  7282393777017109260ULL, 11835650009307558674ULL,  1463281341802436383ULL,  6410047676830305428ULL, 14970889556503516448ULL};

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
