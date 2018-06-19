//PROGRAM TO CALCULATE THE POWER OF THE MANTISA BY EXPONENT
#include<stdio.h>
void main()
{
	int mantisa,exponent;
	long power(int mantisa,int exponent);
	char again='n';
	do
	{
		printf("\nEnter the Number of which the power is to be raised : ");
		scanf("%d",&mantisa);
		while(mantisa<0)
		{
			printf("Please Enter A Valid Number : ");
			fflush(stdin);
			scanf("%d",&mantisa);
		}
		printf("\nEnter the Number by which the power is to be raised : ");
		scanf("%d",&exponent);
		while(exponent<0)
		{
			printf("Please Enter A Valid Number : ");
			fflush(stdin);
			scanf("%d",&exponent);
		}
		printf("\n\n%d raised to power %d is %ld\n",mantisa,exponent,power(mantisa,exponent));
		printf("Do You Wish To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/**
METHOD THAT RETURNS THE POWER OF A NUMBER
@param mantisa : the number which is to be raised
@param exponent : the number by which the number is to be raised
@return long : returns the (MANTISA raised to poewer EXPONENT)
*/
long power(int mantisa,int exponent)
{
	long result=1;
	for(;exponent>0;exponent--)
		result*=mantisa;
	return result;
}