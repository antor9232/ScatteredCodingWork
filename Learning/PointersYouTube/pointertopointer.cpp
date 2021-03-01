#include<stdio.h>
int main()
{
    int x=5;
    int* p;
    p=&x;
    int** q;
    q=&p;
    int*** r;
    r=&q;
    printf("Value of x=%d and Address of X=%p/%d\n",x,&x,&x);
    printf("P=%p\nQ=%p\nR=%p\n",p,q,r);
    printf("P=%d\nQ=%d\nR=%d\n",p,q,r);
    printf("P Value =%d\nQ Value =%d\nR Value =%d\n",*p,**q,***r);




    return 0;
}