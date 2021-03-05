// #include<stdio.h>

// int main(){
//     int i;
//     char ch;
//     ch='a';
//     for(i=0;ch!='q';i++){
//         printf("Pass: %d\n",i);
//         ch=getchar();
//        }
//     return 0;
// }

#include <stdio.h>
int main()
{
    char ch;
    ch=10;//Kept a random value which indicate that it is the beginning of the loop
    while (1)
    {
        
        scanf("%c",&ch); //simply use scanf
        if(ch!='q') printf("Try Again\n");
        else break;
    }
    printf("Found Q\n");

    return 0;
}