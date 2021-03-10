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
        printf("%d\n", A[0]);
        return;
    }

    return;
}
int array[100];
int len = 0;
void rpd(int number)
{
    if (number == 0)
    {
        return;
    }
    array[len++] = number % 10;
    rpd(number / 10);
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
    /*
    Element for testing reversePrint function
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    reversePrint(A, 7);
    */
    int num;
    printf("Give An Integer\n");
    scanf("%d", &num);
    rpd(1234567);
    printf("From last to first\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("From first to last\n");
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d\n", array[i]);
    }
}