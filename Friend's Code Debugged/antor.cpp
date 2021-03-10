#include <stdio.h>
int hydroxide(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }

    if (s[i - 1] != 72 || s[i - 2] != 79)
        return 0;
    return 1;
}
void reversePrint(int A[], int size)
{
    if (size > 1)
    {
        printf("%d\t", A[size - 1]);
        reversePrint(A, size - 1);
    }
    if (size == 1)
    {
        printf("%d\t", A[0]);
        return;
    }

    return;
}

int main()
{
    /*
    Element for testing hydroxide function
    char s[10000];
    scanf("%s", s);
    printf("%d\n", hydroxide(s));
    */
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    //printf("%d\t" ,A[6]);
    reversePrint(A, 7);
}