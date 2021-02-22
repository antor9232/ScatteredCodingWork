// from shanto

#include<stdio.h>
#include<string.h>
int strCom(char s1[],char s2[])
{
    int i,j;
    for(i=0,j=0;s1[i] || s2[j];i++,j++)
    {
        if(s1[i]!=s2[j])
            return 0;
    }
    return 1;
}
typedef struct library{
    int id;
    char title[27];
    char genre[27];
    char author[27];
    char language[27];
    int year;
}library;

int main()
{
    int N,T,i,j,n,y;
    char g[27],t[27],a[27],l[27];
    scanf("%d",&N);
    library arr[N],temp;
    for(i=0;i<N;i++)
    {
        scanf("%d %s %s %s %s %d",&arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,&arr[i].year);
    }
    for(i=0;i<N;i++)
    {
        for(j=i;j>0;j--)
        {
            if(arr[j-1].id>arr[j].id)
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else
                break;
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            scanf("%s",g);
            for(i=0;i<N;i++)
            {
                if(strCom(g,arr[i].genre))
                    printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
        else if(n==2)
        {
            scanf("%d",&y);
            for(i=0;i<N;i++)
            {
                if(y==arr[i].year)
                   printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
        else if(n==3)
        {
            scanf("%s",t);
            for(i=0;i<N;i++)
            {
                if(strCom(t,arr[i].title))
                   printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
        else if(n==4)
        {
            scanf("%s",a);
            for(i=0;i<N;i++)
            {
                if(strCom(a,arr[i].author))
                    printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
        else if(n==5)
        {
            scanf("%s",l);
            for(i=0;i<N;i++)
            {
                if(strCom(l,arr[i].language))
                    printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
        else if(n==6)
        {
            scanf("%s %s",a,l);
            for(i=0;i<N;i++)
            {
                if(strCom(a,arr[i].author) && strCom(l,arr[i].language))
                    printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
        else if(n==7)
        {
            scanf("%s %s",a,t);
            for(i=0;i<N;i++)
            {
                if(strCom(a,arr[i].author) && strCom(t,arr[i].title))
                    printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
        else if(n==8)
        {
            scanf("%s %s",a,g);
            for(i=0;i<N;i++)
            {
                if(strCom(a,arr[i].author) && strCom(g,arr[i].genre))
                    printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
        else if(n==9)
        {
           scanf("%s %s",g,l);
            for(i=0;i<N;i++)
            {
                if(strCom(g,arr[i].genre) && strCom(l,arr[i].language))
                    printf("%d %s %s %s %s %d\n",arr[i].id,arr[i].title,arr[i].genre,arr[i].author,arr[i].language,arr[i].year);
            }
        }
    }
    return 0;
}