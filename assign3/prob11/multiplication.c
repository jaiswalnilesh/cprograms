//PROGRAM TO MULTIPLY TWO NUMBERS ITERATELY
#include<stdio.h>
void main()
{
	int num1,num2;
	char again='n';
	long doMul(int num1,int num2);
	do
	{
		num1=-1;num2=-1;
		printf("Enter The FIRST Number To Be Multiplied : ");
		fflush(stdin);
		scanf("%d",&num1);
		while(num1<0)
		{
			printf("Enter a valid FIRST number : ");
			fflush(stdin);
			scanf("%d",&num1);
		}
		printf("\nEnter The SECOND Numbers To Be Multiplied : ");
		fflush(stdin);
		scanf("%d",&num2);
		while(num2<0)
		{
			printf("Enter a valid SECOND number : ");
			fflush(stdin);
			scanf("%d",&num2);
		}
		printf("\n\nResult of Operation %d * %d is %d \n",num1,num2,doMul(num1,num2));
		printf("\n\n\t\tDo You Want To Input Again?(y/n)");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
FUNCTION THAT DOES THE ITERATIVE MULTIPLICATION
@param num1 : first number to be multiplied
@param num2 : Second number to be multiplied
@return long : returns the product of the given 2 numbers.
*/
long doMul(int num1,int num2)
{
	long result=0;
	for(;num2>0;num2--)
		result+=num1;
	return result;
}