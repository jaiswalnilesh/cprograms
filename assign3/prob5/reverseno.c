//PROGRAM TO REVERSE THE NUMBER
#include<stdio.h>
void main()
{
	long number,number1,revNo=0;
	char again='n';
	do
	{
		printf("Enter The Number Whose Reverse Number Is To Be Checked : ");
		fflush(stdin);
		scanf("%ld",&number);
		while(number<0)
		{
			printf("Enter A Valid Number : ");
			fflush(stdin);
			scanf("%ld",number);
		}
		number1=number;
		while(number1>0)
		{
			revNo=revNo*10+(number1%10);
			number1/=10;
		}
		if(number==revNo)
			printf("Both The Numbers Are Same!!!!!\n");
		else
			printf("Both The Numbers Are NOT Same!!!!!\n");
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}
