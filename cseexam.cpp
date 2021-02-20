#include <stdio.h>
// void myf(int x)
// {
//     int i = 0, j = 1, k = 2;
//     for (; i < 5; i++)
//     {
//         for (; k < 5; k++)
//         {
//             for (;j < 5; j++)
//             {
//                 x % k == 0 ? i = 3 : j = 3;
//             }
//             printf("%d%d%d", i, j, k);
//         }
//     }
// }
void dts(char x[], int n)
{
    int i=0; 
    while(n>0){
        x[i++]==n%10+'0';
        n/=3;
    }
    x[i]='\0';
}
void a(int x)
{
    if(x%3==0) a(x-1);
    for (int i=0; i < x; i++)
    {
        for (int j=0; j < i+2; j++)
        {
            for (int k=0;k < j; k++)
            {
                printf("*");
            }
                printf("\n");
           
            
        }
    }
}
int main()
{
//int array[] = {1, 2, 3, 4, 5};
//int array[5] = {1, 2, 3, 4, 5};
    char digit[100];
    int p=100;

    dts(digit,p);

    printf("%s\n",digit);
    // a(5);
    // return 0;
}