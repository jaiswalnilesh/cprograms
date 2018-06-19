//PROGRAM TO DISPLAY FIRST 25 ELEMENTS OF A FIBONACCI SERIES
#include<stdio.h>


void main()
{
	int count = 25 - 2 ;
	int prev1 = 1, prev2 = 2;

	printf("The first 25 Numbers of the Fibonacci series are\n");

	printf("\n\n1) %d \n2) %d",prev1,prev2);

	for( ; count > 0 ; count-- )
	{
		printf("\n%d) %d ",26-count,prev1+prev2);
		prev2=prev1+prev2;
		prev1=prev2-prev1;
	}

	printf("\n");
}