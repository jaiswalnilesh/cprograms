//TO ADD TWO NUMBERS USING RECURSION
#include<stdio.h>
void main()
{
	int num1,num2;
	char again='n';
	int doAdd(int num1,int num2);
	do
	{
		num1=-1;num2=-1;
		printf("Enter The FIRST Numbers To Be Added : ");
		fflush(stdin);
		scanf("%d",&num1);
		while(num1<0)
		{
			printf("Enter a valid FIRST number : ");
			fflush(stdin);
			scanf("%d",&num1);
		}
		printf("\nEnter The SECOND Numbers To Be Added : ");
		fflush(stdin);
		scanf("%d",&num2);
		while(num2<0)
		{
			printf("Enter a valid SECOND number : ");
			fflush(stdin);
			scanf("%d",&num2);
		}
		printf("\n\nResult of Operation %d + %d is %d \n",num1,num2,doAdd(num1,num2));
		printf("\n\n\t\tDo You Want To Input Again?(y/n)");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
The Method that does the addition
@param num1 : the first number to be added.
@param num2 : the second number to be added.
@return int : returns the addition of the given 2 number
*/
int doAdd(int num1,int num2)
{
	if(num2>0)
		num1=doAdd(++num1,--num2);
	return num1;
}