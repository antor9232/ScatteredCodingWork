#include<stdio.h>
void printnumberstar(int n)
{
	if(n==0)      {printf("*****\n*   *\n*   *\n*   *\n*****\n"); return;}
	else if(n==1) {printf("    *\n    *\n    *\n    *\n    *\n"); return;}
	else if(n==2) {printf("*****\n    *\n*****\n*    \n*****\n"); return;}
	else if(n==3) {printf("*****\n    *\n*****\n    *\n*****\n"); return;}
	else if(n==4) {printf("*   *\n*   *\n*****\n    *\n    *\n"); return;}
	else if(n==5) {printf("*****\n*    \n*****\n    *\n*****\n"); return;}
	else if(n==6) {printf("*****\n*    \n*****\n*   *\n*****\n"); return;}
	else if(n==7) {printf("*****\n    *\n    *\n    *\n    *\n"); return;}
	else if(n==8) {printf("*****\n*   *\n*****\n*   *\n*****\n"); return;}
	else if(n==9) {printf("*****\n*   *\n*****\n    *\n*****\n"); return;}
}

int main()
{
	int n;
	scanf("%d",&n);
	printnumberstar(n);
	return 0;
}
