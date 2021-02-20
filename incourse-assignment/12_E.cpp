#include <stdio.h>
typedef long long ll;

typedef struct String4
{
    char s[5];
} String4;
struct String4 sarray[100000];
void strcpy(char *a, char *b){
    int i=0;
    while(1){
         char temp= a[i];
        a[i]= b[i];
        b[i]= temp;
        if(a[i]=='\0') break; 
        i++;
    }
    return;
}

void swap(struct String4 a, struct String4 b)
{
    printf("Ran swap\n");
    struct String4 temp;
    temp = a;
    a = b;
    b = temp;
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
int strcmp(char *a, char *b)
{
    for(int i=0; i<4; i++)
    {
        if(a[i]<b[i]) return -1;
        else if(a[i]>b[i]) return 1;
    }
    return 0;

}


void bubblesort(int n) //Function for implementing bubble sort
{
    n=n-4;
    printf("Ran\n");
    //)

    for (int i = 0; i < n - 1; i++) //Outer Loop
    {
        bool flag = false;                  //to make it more efficient
        for (int j = 0; j < n - 1 - i; j++) //inner loop
        {
            printf("Before: %s %s\n",sarray[j].s,sarray[j + 1].s);
            if (strcmp(sarray[j].s,sarray[j + 1].s)==1) //Comparison
            {                        //Swapping
                strcpy(sarray[j].s,sarray[j + 1].s);
                printf("After %s %s\n",sarray[j].s,sarray[j + 1].s);
                flag = true;
            }
        }
        if (!flag)
            return;
    }
}
int main()
{
    int n = 0;
    struct String4 sarray[100000];
    char str[100000];
    scanf("%s", str);
    int len = strlen(str);
    while (n <= len - 4)
    {
        strcpyt(str, sarray[n].s, n);
        n++;
    }
    bubblesort(len);
    for (int i = 0; i < len - 3; i++)
    {
        printf("%s\n", sarray[i].s);
    }
}