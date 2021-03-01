#include<stdio.h>

int main()
{
    int a;
    int *p;
    p = &a;
    a=5;
    printf("%d\n",p);
    printf("%d\n",a);
   // printf("%p\n",*a);
    //printf("%d\n",&a);
    printf("%d\n",*p);
    printf("%d\n",&a);
    *p=12;
    printf("%d\n",*p);
    printf("%d\n",&a);
    int b=20;
    *p=b;
    printf("%d\n",p);
    // printf("%d\n",a);
   // printf("%p\n",*a);
    //printf("%d\n",&a);
    printf("%d\n",*p);
    
    p= &b;
    printf("%d\n",p);
    //pointer arithmatic
    printf("Address of p is %d\n",p); 
    printf("Size of integer is %d bytes\n", sizeof(int));
    printf("Address of p is %d\n",p+1);
    

}