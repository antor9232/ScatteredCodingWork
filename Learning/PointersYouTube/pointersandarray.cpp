#include <stdio.h>
int SumOfElement(int A[])
{
    int i, sum=0;
    int size = sizeof(A)/sizeof(A[0]);
    printf("SOE - Sizeof A= %d, size of A[0]=%d", sizeof(A),sizeof(A[0]));
    for(int i=0; i<size; i++)
    {
        sum+=A[i];
    }
    return sum;
}
int main()
{
    int A[] = {2, 4, 5, 8, 1};
    
    int total = SumOfElement(A);
    printf("%d\n",total);
    printf("Main - Sizeof A= %d, size of A[0]=%d\n", sizeof(A),sizeof(A[0]));
    // int i;
    // int *p =A;
    // //A++;//Invalid;
    // p++;//valid
    // p--;
    // for (i = 0; i < 5; i++)
    // {
    //     printf("Address = %d", &A[i]);
    //     printf("  Address = %d", *(p+i) + i);
    //     printf("\n");
    // }
}