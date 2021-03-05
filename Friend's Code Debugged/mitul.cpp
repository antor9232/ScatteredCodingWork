#include<stdio.h>
int main(){
    int a,b;
    char garbage,ch;
    printf("Do you want to: \n");
    
    //Method 1
    //No need of grabaage as you gave a newline character
    printf("Add: a, Substract:s, Multuply:m, or Divide:d ?\n");

    
    //Method 2
    //if you didnot gave a newline character in previous printf you would have need one
    //printf("Add: a, Substract:s, Multuply:m, or Divide:d ?\n");
    //scanf("%c",&garbage);


    scanf("%c",&ch);

    printf("Enter 1st number:\n ");
    scanf("%d",&a);
    printf("Enter 2nd number:\n");
    scanf("%d",&b);
    if(a>b){
    if(ch=='a') printf("%d",a+b);
    if(ch=='s') printf("%d",a-b);
    if(ch=='m') printf("%d",a*b);
    if(ch=='d') printf("%d",a/b);}
    else{
        if(ch=='a') printf("%d",a+b);
        if(ch=='s') printf("%d",b-a);
        if(ch=='m') printf("%d",a*b);
        if(ch=='d') printf("%d",a/b);

    }
    printf("\n");
    return 0;


}