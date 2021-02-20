#include<stdio.h>
#include<math.h> //Preprocessor for acos(), cos() function

int main()
{
	int h, a, b;
	double pi= acos(-1.00000);//getting the output of pi
	scanf("%d %d %d",&h,&a,&b);
	double ar= (pi/180.00)*a;
	double br= (pi/180.00)*b;
	double ans= (0.50*h*h*sin(ar+br))/(cos(ar)*cos(br));
	printf("%.6lf\n",ans);
	return 0;
}
