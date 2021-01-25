#include<stdio.h>

void getinputandmakearray(char arr[8][8])
{
    int n=8;
    char temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c",&temp);
            printf("%d",arr[i][j]);
            
        }
        
        
    }
    

}
void arrayoutput(char arr[8][8]){
    int n=8;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d",arr[j][i]);
        }
        printf("\n");
        
    }

}
int main()
{

    char arr[8][8];
    getinputandmakearray(arr);
    arrayoutput(arr);
    
}
/*
B.KAB...
P..P...K
P.R.P...
......Q.
...2..R.
........
.P...P..
........
*/