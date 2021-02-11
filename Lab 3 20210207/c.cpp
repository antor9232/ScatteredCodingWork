//12
//12
//12
//12
#include<stdio.h>
int bstr[5],len;
int inttoarray(char in[], int bstr[])
{
	int i=0;
	while(in[i]!='\0')
	{
	if(in[i]==48) bstr[i]=0;
	if(in[i]==49) bstr[i]=1;
	
	}
	return i;
}
void whattodo(int x){
    if(x==0) 
    {for(int i=0; i<len;i++) { printf("%d", bstr[i]);}}
    else if(x%2!=0) {
        for(int i=0; i<len;i++)
        {
            if(bstr[i]==1) whattodo(x-1);
            else printf("%d", bstr[i]);
        }
    }
    else if(x%2==0) 
    {
        for(int i=0; i<len;i++)
        {
            if(bstr[i]==0) whattodo(x-1);
            else printf("%d", bstr[i]);
        }
    }
}
int main()
{
	char in[5];
    int x;
    scanf("%s %d", in,&x);
    int len= inttoarray(in,bstr);
    whattodo(x);
   
    printf("\n");

    return 0;
}
