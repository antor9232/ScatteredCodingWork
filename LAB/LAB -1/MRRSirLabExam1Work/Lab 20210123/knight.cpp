#include<stdio.h>

int MAX(int a, int b)
{
  return a>b?a:b;
}
int isin(int a, int b)
{
  if(a>=0 && a<8)
    {
      if(b>=0 && b<8) return 1;
      else return 0;
    }
  else return 0;
}

int main()
{
  int maxres=-1, restemp;
  int ides=7, jdes=7;
  //printf("%d\n",isin(3,9));
  int arr[8][8];
  for(int i=0; i<8; i++)
    {
      for(int j=0;j<8;j++)
	{
	  scanf("%d",&arr[i][j]);
	}
    }
  printf("%d %d\n",ides, jdes);
  printf("%d\n",arr[ides][jdes]);
  for(int i=2; i>=-2;i--)
    {
      if(i==0) continue;
      int itemp= ides+i;
      
      for(int j=2; j>=-2; j--)
	{
	  if(j==0 || i==j || ((-1)*i)==j) continue;
	  int jtemp = jdes+j;
	  if(!isin(itemp,jtemp)) continue; 
	  restemp = arr[itemp][jtemp];
	  maxres = MAX(restemp,maxres);
	  
	}
    }
  
  printf("%d\n",maxres);
  return 0;
}
/*
1 2 3 4 0 0 0 0 
0 0 0 0 0 0 1 2 
2 4 5 2 0 0 0 1
1 2 3 4 5 0 0 0
1 2 3 0 0 0 2 3
2 3 4 0 0 0 1 1 
1 1 1 3 0 6 7 9
2 3 0 9 6 8 0 11

 */
