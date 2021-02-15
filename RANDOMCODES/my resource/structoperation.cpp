#include<stdio.h>

int strlen(char *s)
{
    int i=0, count=0;
    while(s[i++]!='\0') count++;

    return count;
}

int main()
{
    char string[100];
}