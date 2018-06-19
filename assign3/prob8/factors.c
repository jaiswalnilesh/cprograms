//PROGRAM TO GET THE FACTORS OF THE INPUT NUMBER
#include<stdio.h>
void main()
{
	long number;
	int count;
	char again='n';
	do
	{
		printf("Enter the number whose factors are to be determine : ");
		scanf("%ld",&number);
		while(number<0)
		{
			printf("Enter a valid Number : ");
			fflush(stdin);
			scanf("%ld",&number);
		}
		printf("\nFactors for %ld are \n",number);
		for(count=2;count<=number;count++)
		{
			while(number%count ==0)
			{
				printf(" %d  ",count);
				number=number/count;				
			}
		}
		printf("\n\n\t\tDo You Want To Do This Again?(y/n)");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='Y' || again =='y');
}