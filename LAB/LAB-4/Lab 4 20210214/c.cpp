#include<stdio.h>
int pos[100005]={0};

void solveq1(int var)
{
    if(pos[var]==0) return;
    else
    {

    }

}
void solveq2()
{

}
void solveq3()
{

}
int main()
{
    int n,k=0;
    scanf("%d",&n);
    while(k<=n)
    {
        int temp;
        scanf("%d",&temp);
        if(temp==0) {
            k++;
        }
        else pos[temp]=k;


    }
    int testcase;
    scanf("%d",&testcase);
    while(testcase--)
    {
        int q;
        scanf("%d",&q);
        if(q==1)
        {
            int var;
            scanf("%d",&var);
            solveq1(var);

        }
        else if(q==2)
        {

        }
        else{

        }
    }
}