#include<stdio.h>

typedef struct Book
{
    int id, year;
    char title[30], genre[30], author[30], language[30];
} Book;

int strComp(char a[],char b[])
{
    int i,j;
    for(i=0,j=0;a[i] || b[j];i++,j++)
    {
        if(a[i]!=b[j])
            return 0;
    }
    return 1;
}

int main()
{
    int N, T, i, j, n, y;
    char gen[30], tit[30],aut[30],lang[30];
    Book barray[10000],temp;

    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s %s %s %s %d", &barray[i].id, barray[i].title, barray[i].genre, barray[i].author, barray[i].language, &barray[i].year);
    }

    return 0;
}

/*
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
*/