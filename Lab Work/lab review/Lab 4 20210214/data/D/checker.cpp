#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = {  9295038859540861966ULL,  9928130199436080308ULL, 17202805381831161185ULL, 17380948014362841530ULL, 12181193619528460377ULL,  4651382316940194437ULL,  1203292746234523813ULL,  6693710541991614551ULL, 13184968840499585162ULL, 11254878428026423631ULL,  8147025217388139577ULL,  8676483144828050367ULL, 10511971823243273972ULL,  8876742178330732870ULL,  7494993972959665207ULL,  3620495748523615806ULL,  1513851444017012157ULL, 10766118676909109191ULL, 18436961157273602454ULL, 11750202758157158126ULL};
ui64         judgeWSIgnoreHash[] = {  2489702933561204076ULL, 11438448319956307814ULL,  9931721153134741563ULL, 10832877424522084324ULL,  1972694260214308199ULL, 11767413541417655635ULL, 10136216145876117265ULL, 13642897229527121619ULL, 15430903241420923698ULL, 10634096055430324233ULL, 15228955487291202731ULL, 16101655745608470357ULL,  9391451796908334302ULL, 14147518808602736036ULL,  9574064754668592765ULL, 12349931380816826174ULL,  4129023768285466273ULL, 17222812218461374573ULL, 16979516584791336194ULL,  7172460000100567368ULL};
ui64    judgeWS_CaseIgnoreHash[] = {  9252665083311343660ULL,  8184475090958780262ULL,  1848312735687494395ULL, 16802960834594775748ULL, 15793303748303456999ULL, 13514327064197082163ULL, 14029449805706020209ULL,  6640531730942747827ULL,  6089969741933206642ULL, 13850053905432481417ULL, 13493084989072438251ULL, 11456903258982243349ULL, 18206772959590783166ULL,  6383045182029635620ULL, 14167483831673974173ULL, 13766883935298211550ULL, 16475614790378131105ULL,  3601777559200420365ULL, 17588143385654151362ULL,  3366814748282530664ULL};

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
