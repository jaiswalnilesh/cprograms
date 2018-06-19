#include "stdio.h"
#include "stdlib.h"

int gcd(int x, int y);
void main()
{
	int num1,num2;
	printf("Enter two numbers(>0) :");
	while(scanf("%d %d",&num1,&num2)==0 || num1==0 || num2==0 )
	{
		printf("Enter valid numbers :\n");
	}
	
	printf("GCD of %d and %d = %d\n",num1,num2,gcd(num1,num2));

}

int gcd(int x, int y)
{
	if(x<y)
		return(gcd(y,x));
	else if(x%y==0 && y<=x)
		return y;
	else
		return gcd(y,x%y);

}