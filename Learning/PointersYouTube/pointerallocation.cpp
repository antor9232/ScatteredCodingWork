#include<stdio.h>
//Why one data type needs one specific address?
//For Dereferencing purpose and accesing/ modifying values we store such way
int main()
{
    int a=1025;
    int *p;
    p= &a;
    printf("Size of integer is %lud bytes\n", sizeof(int));
    printf("Address =%p , value= %d\n",p+1,*(p+1));
    char *p0;
    p0 =(char*)p;
    printf("Size of integer is %lud bytes\n", sizeof(char));
    printf("Address =%p , value= %d\n",p0+1,*(p0+1));

    return 0;
}