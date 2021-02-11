//12
//12
//12
//12
//12
#include<stdio.h>
int bstr[5];
int len=0, k=0;
int arr[1000005];
int inttoarray(char in[], int bstr[])
{
	int i=0;
	while(in[i]!='\0')
	{
	if(in[i]==48) bstr[i]=0;
	if(in[i]==49) bstr[i]=1;
	//if(in[i]==48) bstr[i]=1;

	}
	return i;
}
void whattodo(int x){
    if(x==0) 
    {for(int i=0; i<len;i++) {arr[k++]=bstr[i];}}
    else if(x%2!=0) {
        for(int i=0; i<len;i++)
        {
            if(bstr[i]==1) whattodo(x-1);
            else {arr[k++]=bstr[i];}
        }
    }
    else if(x%2==0) 
    {
        for(int i=0; i<len;i++)
        {
            if(bstr[i]==0) whattodo(x-1);
            else {arr[k++]=bstr[i];}
        }
    }
}
int main()
{
	char in[5];
    int x;
    scanf("%s %d", in,&x);
    len= inttoarray(in,bstr);
    whattodo(x);
    
    for (int i = k-1; i >=0; i--)
    {
        printf("%d",arr[i]);
    }
   
    printf("\n");

    return 0;
}
