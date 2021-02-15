#include<stdio.h>
int inttoarray(long long int n, int arr[])
{
	int i=0;
	while(n>0)
	{
	arr[i]= n%10;
	n=n/10;
	i++;
	}
	return i;
}
int main()
{
	int arr[12];
	int n= inttoarray(11223223, arr);
	for(int i=0; i<n; i++) printf("%d",arr[i]);
	return 0;
}
