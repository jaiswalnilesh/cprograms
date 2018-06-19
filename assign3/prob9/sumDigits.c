//PROGRAM TO CALCULATE THE SUM OF DIGITS OF THE INPUT NUMBER
#include<stdio.h>
void main()
{
	int sum;
	long number;
	char again='n';
	do
	{
		sum=0;
		printf("Enter A Number Whose Sum Of Digits Is To Be Determine : ");
		fflush(stdin);
		scanf("%ld",&number);
		while(number<0)
		{
			printf("Enter A Valid Number : ");
			fflush(stdin);
			scanf("%ld",&number);
		}
		while(number>0)
		{
			sum+=number%10;
			number/=10;
		}
		printf("Sum Of Digits Of Given Number Is %d\n",sum);
		printf("\n\n\t\tWant To Do Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}