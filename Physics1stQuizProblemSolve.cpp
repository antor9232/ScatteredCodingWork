#include<stdio.h>

int main()
{
	double A, B, T,P,p1,t1,t2,p2;
	printf("let's Find A and B.Give consequent P1, T1, P2, T2\n");
	scanf("%lf %lf %lf %lf",&p1,&t1,&p2,&t2);
	A =(p1*t2 - p2*t1)/(t2- t1); 
	B = (p1-p2)/(t1-t2);
	printf("A==%5lf   B==%5lf\n",A,B);
	int t=5;
	while(t--)
	{
		char ch, ch2;
		printf("What do you want? T or P! Give anything else for exit\n");
		scanf("%c %c",&ch2,&ch);
		//printf("%c %c\n", ch2, ch);
		if(ch=='T') 
		{	 
			printf("Give Pressure P\n");
			scanf("%lf",&P);
			printf("T=== %lf\n",(P-A)/B);
		}
		else if(ch=='P')
		{
			printf("Give Temperature T\n");
			scanf("%lf",&T);
			printf("P=== %lf\n",(A+ B*T));

		}
		else return 0;
	}
	return 0;
}
