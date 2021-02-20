#include <stdio.h>

typedef long long ll;
int len = 0;

typedef struct String4
{
    char s[5];
} String4;
struct String4 sarray[1000000];

int strcmp(char *a, char *b)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] < b[i])
            return -1;
        else if (a[i] > b[i])
            return 1;
    }
    return 0;
}
void strcpy(char *a, char *b)
{
    int i = 0;
    while (1)
    {
        char temp = a[i];
        a[i] = b[i];
        b[i] = temp;
        if (a[i] == '\0')
            break;
        i++;
    }
    return;
}

int strlen(char *s)
{
    int i = 0, count = 0;
    while (s[i++] != '\0')
        count++;

    return count;
}
void strcpyt(char *smain, char *scopy, int t)
{
    int j = 0;
    for (int i = t; i < t + 4; i++)
    {
        scopy[j++] = smain[i];
    }
    scopy[j] = '\0';
}
int main()
{
    int n = 0;
    struct String4 sarray[1000000];
    char str[100000];
    scanf("%s", str);
    int len = strlen(str);
    while (n <= len - 4)
    {
        strcpyt(str, sarray[n].s, n);
        n++;
    }
    //Sorting The Array of Strings!
    int i, j, count = len - 4;
    char temp[5];
    for (i = 0; i <= count; i++)
        for (j = i + 1; j <= count; j++)
        {
            if (strcmp(sarray[i].s, sarray[j].s) > 0)
            {
                strcpy(temp, sarray[i].s);
                strcpy(sarray[i].s, sarray[j].s);
                strcpy(sarray[j].s, temp);
            }
        }

    for (int i = 0; i < len - 3; i++)
    {
        printf("%s\n", sarray[i].s);
    }
    return 0;
}