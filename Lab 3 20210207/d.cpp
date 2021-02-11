//12
//12
//12
#include <stdio.h>

int strlen(char x[])
{
    int count = 0;
    int i = 0;
    while (x[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

int main()
{
}