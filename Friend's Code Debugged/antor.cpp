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
int main()
{
    char s[10000];
    scanf("%s", s);
    printf("%d\n", hydroxide(s));
}