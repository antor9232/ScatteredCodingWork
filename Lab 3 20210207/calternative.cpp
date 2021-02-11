//12
//12
#include <stdio.h>
int len=0;
int bstr[5];

void ArrayOutput(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}
void whattodo(int x)
{
    if (x == 0)
    {
        for (int i = 0; i < len; i++)
        {
            printf("%d", bstr[i]);
        }
    }
    // else if (x % 2 != 0)
    // {
    //     for (int i = 0; i < len; i++)
    //     {
    //         if (bstr[i] == 1)
    //             //whattodo(x-1)
    //             ;
    //         else
    //             printf("%d", bstr[i]);
    //     }
    // }
    // else if (x % 2 == 0)
    // {
    //     for (int i = 0; i < len; i++)
    //     {
    //         if (bstr[i] == 0)
    //             //whattodo(x-1)
    //             ;
    //         else
    //             printf("%d", bstr[i]);
    //     }
    // }
}
int main()
{
    
    char a;
    int i = 0, x;
    while (1)
    {
        scanf("%c", &a);
        if (a == ' ')
            break;
        else if (a == 48)
            bstr[i++] = 0;
        else if (a == 49)
            bstr[i++] = 1;
    }
    // len =i;
    // scanf("%d",&x);
    // ArrayOutput(bstr,i);
    // printf("%d %d",x,len);
    whattodo(x);

    return 0;
}
