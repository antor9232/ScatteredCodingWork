#include<stdio.h>

int strlen(char x[])
{
	int count=0;
	int i=0;
	while(x[i]!='\0') {count++;i++;}
	return count;
}

void strcpy(char x[], char y[])
{
	int len= strlen(x);
	for(int i=0; i<len;i++)\
	{
		y[i]=x[i];
	}
}
void strcpyn(char x[], char y[], int n, int m)
{


	int len= strlen(x);
	if(m>len) {y[0]= '\0'; return;}
	int j=0;
	for(int i=m; i<n && i<len;i++)\
	{
		y[j]=x[i];
		j++;
		if(x[i]=='\0') break;
	}
}

void strCat(char x[], char y[], char z[])
{
	int n= strlen(x);
	int m= strlen(y);
	int i=0, j=0, k=0;
	for(i; i<n;i++){ z[k]= x[i]; k++;}
	for(j; j<m+1; j++){ z[k] = y[j]; k++;}

}

void strRev(char x[])//Did not worked
{
	int len= strlen(x);
	printf("%d",len);
	int i=0;
	int bound = len/2;
	for(int i=0; i< bound ; i++)
	{
		char temp;
		temp= x[i];
		x[i]= x[len-i];
		x[len-1] = temp;
	}
}

int strcmp(char x[], char y[])
{
	int n= strlen(x);
	int m = strlen(y);
	int i=0;
	while(1)
	{
		if(x[i]> y[i]) return 1;
		if(y[i]>x[i]) return 0;
		i++;
	}
}
int main()
{
	int n, m;
	char x[100], y[100], z[100];
	scanf("%s %s",x,y);
	//strRev(x);
	printf("%d\n",strcmp(x,y));
}
