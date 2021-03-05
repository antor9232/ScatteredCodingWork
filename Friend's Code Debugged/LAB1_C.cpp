//Abdullah Ibne Hanif Arean
//main problem behind white space error is you have to print one blank space intentionally before each line
//Added some spaces before any line starting
//100% Passed
#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    printf(" ");
    if(N==0)
        printf("*****\n *   *\n *   *\n *   *\n *****");
    else if(N==1)
        printf("    *\n     *\n     *\n     *\n     *");
    else if(N==2)
        printf("*****\n     *\n *****\n *    \n *****");
    else if(N==3)
        printf("*****\n     *\n *****\n     *\n *****");
    else if(N==4)
        printf("*   *\n *   *\n *****\n     *\n     *");
    else if(N==5)
        printf("*****\n *    \n *****\n     *\n *****");
    else if(N==6)
        printf("*****\n *    \n *****\n *   *\n *****");
    else if(N==7)
        printf("*****\n     *\n     *\n     *\n     *");
    else if(N==8)
        printf("*****\n *   *\n *****\n *   *\n *****");
    else if(N==9)
        printf("*****\n *   *\n *****\n     *\n *****");
    printf("\n");
    return 0;
}
