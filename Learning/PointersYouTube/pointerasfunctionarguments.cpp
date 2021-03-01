#include<stdio.h>

void IncreamentCallbyValue(int a)//formal argument
{
    a= a+1;
   // printf("Adress of variable a in increament = %p\n",&a);
}
void  IncreamentCallbyReference(int *p)
{
    *p = *p +1;
}
int main()
{
    int a;
    a=10;
    IncreamentCallbyValue(a);//actual argument
    printf("a=%d\n",a);
    IncreamentCallbyReference(&a);
    //printf("Adress of variable ain main function = %p\n",&a);
    printf("a=%d\n",a);
}