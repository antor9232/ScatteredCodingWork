//Abdullah Ibne Hanif Arean
//Abdullah Ibne Hanif Arean
//Santo your code was okay but you did not acknowledged one newline which was given after each line
//So you have to take 9 char in a row including a "\n" not 8
#include<stdio.h>
int main()
{
  char chess[8][9];//changed this line, made it 9 from 8
    int i,j,s1,s2,pts,mx=0;
    for(i=0;i<8;i++)
    {
      for(j=0;j<9;j++)//changed this line, made it 9 from 8
        {
            scanf("%c",&chess[i][j]);
            if(chess[i][j]=='2')
            {
                s1=i;
                s2=j;
            }
        }
    }
    char p1=chess[s1-2][s2-1];
    char p2=chess[s1-2][s2+1];
    char p3=chess[s1+2][s2-1];
    char p4=chess[s1+2][s2+1];
    char p5=chess[s1-1][s2-2];
    char p6=chess[s1-1][s2+2];
    char p7=chess[s1+1][s2-2];
    char p8=chess[s1+1][s2+2];
    if(s1>=2)
    {
        if(s2>=1)
        {
            if(p1=='.')
                pts=0;
            else if(p1=='P')
                pts=1;
            else if(p1=='B')
                pts=3;
            else if(p1=='R')
                pts=3;
            else if(p1=='K')
                pts=5;
            else if(p1=='Q')
                pts=8;
            else if(p1=='A')
                pts=10;
        }
        if(mx<pts)
            mx=pts;
        if(s2<7)
        {
           if(p2=='.')
                pts=0;
            else if(p2=='P')
                pts=1;
            else if(p2=='B')
                pts=3;
            else if(p2=='R')
                pts=3;
            else if(p2=='K')
                pts=5;
            else if(p2=='Q')
                pts=8;
            else if(p2=='A')
                pts=10;
        }
        if(mx<pts)
            mx=pts;
    }
    if(s1<6)
    {
        if(s2>=1)
        {
            if(p3=='.')
                pts=0;
            else if(p3=='P')
                pts=1;
            else if(p3=='B')
                pts=3;
            else if(p3=='R')
                pts=3;
            else if(p3=='K')
                pts=5;
            else if(p3=='Q')
                pts=8;
            else if(p3=='A')
                pts=10;
        }
        if(mx<pts)
            mx=pts;
        if(s2<7)
        {
           if(p4=='.')
                pts=0;
            else if(p4=='P')
                pts=1;
            else if(p4=='B')
                pts=3;
            else if(p4=='R')
                pts=3;
            else if(p4=='K')
                pts=5;
            else if(p4=='Q')
                pts=8;
            else if(p4=='A')
                pts=10;
        }
        if(mx<pts)
            mx=pts;
    }
    if(s1>=1)
    {
        if(s2>=2)
        {
            if(p5=='.')
                pts=0;
            else if(p5=='P')
                pts=1;
            else if(p5=='B')
                pts=3;
            else if(p5=='R')
                pts=3;
            else if(p5=='K')
                pts=5;
            else if(p5=='Q')
                pts=8;
            else if(p5=='A')
                pts=10;
        }
        if(mx<pts)
            mx=pts;
        if(s2<6)
        {
           if(p6=='.')
                pts=0;
            else if(p6=='P')
                pts=1;
            else if(p6=='B')
                pts=3;
            else if(p6=='R')
                pts=3;
            else if(p6=='K')
                pts=5;
            else if(p6=='Q')
                pts=8;
            else if(p6=='A')
                pts=10;
        }
        if(mx<pts)
            mx=pts;
    }
    if(s1<7)
    {
        if(s2>=2)
        {
            if(p7=='.')
                pts=0;
            else if(p7=='P')
                pts=1;
            else if(p7=='B')
                pts=3;
            else if(p7=='R')
                pts=3;
            else if(p7=='K')
                pts=5;
            else if(p7=='Q')
                pts=8;
            else if(p7=='A')
                pts=10;
        }
        if(mx<pts)
            mx=pts;
        if(s2<6)
        {
           if(p8=='.')
                pts=0;
            else if(p8=='P')
                pts=1;
            else if(p8=='B')
                pts=3;
            else if(p8=='R')
                pts=3;
            else if(p8=='K')
                pts=5;
            else if(p8=='Q')
                pts=8;
            else if(p8=='A')
                pts=10;
        }
        if(mx<pts)
            mx=pts;
    }
    printf("%d\n",mx);
    return 0;
}
