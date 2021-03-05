
#include<stdio.h>
int main()
{
    int N,q,i,j,f=1,p,cnt=0;
    scanf("%d",&N);
    q=N;
    while(q!=0)
    {
        q=q/10;
        cnt++;
    }
    for(j=1; j<cnt; j++)
    {
        f*=10;
    }
    p=f;
    for(i=1; i<=5; i++)
    {
        printf(" ");
        q=N;
        f=p;
        for(j=1; j<=cnt; j++)
        {
            if(q/f==0)
            {
                if(i==1)
                    printf("*****");
                else if(i==2)
                    printf("*   *");
                else if(i==3)
                    printf("*   *");
                else if(i==4)
                    printf("*   *");
                else if(i==5)
                    printf("*****");
            }
            else if(q/f==1)
            {
                if(i==1)
                    printf("    *");
                else if(i==2)
                    printf("    *");
                else if(i==3)
                    printf("    *");
                else if(i==4)
                    printf("    *");
                else if(i==5)
                    printf("    *");
            }
            else if(q/f==2)
            {
                if(i==1)
                    printf("*****");
                else if(i==2)
                    printf("    *");
                else if(i==3)
                    printf("*****");
                else if(i==4)
                    printf("*    ");
                 else if(i==5)
                    printf("*****");
            }
            else if(q/f==3)
            {
                if(i==1)
                    printf("*****");
                else if(i==2)
                    printf("    *");
                else if(i==3)
                    printf("*****");
                else if(i==4)
                    printf("    *");
                else if(i==5)
                    printf("*****");
            }
            else if(q/f==4)
            {
                if(i==1)
                    printf("*   *");
                else if(i==2)
                    printf("*   *");
                 else if(i==3)
                    printf("*****");
                else if(i==4)
                    printf("    *");
                else if(i==5)
                    printf("    *");
            }
            else if(q/f==5)
            {
                if(i==1)
                    printf("*****");
                else if(i==2)
                    printf("*    ");
                else if(i==3)
                    printf("*****");
                 else if(i==4)
                    printf("    *");
                else if(i==5)
                    printf("*****");
            }
            else if(q/f==6)
            {
                if(i==1)
                    printf("*****");
                else if(i==2)
                    printf("*    ");
                else if(i==3)
                    printf("*****");
                else if(i==4)
                    printf("*   *");
                else if(i==5)
                    printf("*****");
            }
            else if(q/f==7)
            {
                if(i==1)
                    printf("*****");
                else if(i==2)
                    printf("    *");
                else if(i==3)
                    printf("    *");
                else if(i==4)
                    printf("    *");
                else if(i==5)
                    printf("    *");
            }
            else if(q/f==8)
            {
                if(i==1)
                    printf("*****");
                else if(i==2)
                    printf("*   *");
                else if(i==3)
                    printf("*****");
                else if(i==4)
                    printf("*   *");
                else if(i==5)
                    printf("*****");
            }
            else if(q/f==9)
            {
                if(i==1)
                    printf("*****");
                else if(i==2)
                    printf("*   *");
                else if(i==3)
                    printf("*****");
                else if(i==4)
                    printf("    *");
                else if(i==5)
                    printf("*****");
            }
            q-=((q/f)*f);
            f=f/10;
        }
        printf("\n");
    }
    return 0;
}