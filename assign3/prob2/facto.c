//PROGRAM TO CALCULATE FACTORIAL OF A NUMBER
#include<stdio.h>
void main()
{
	int number;
	char again='n';
	long fact(int num);
	do
	{
		printf("Enter the number of which factorial is to be determined");
		scanf("%d",&number);
		while(number<0)
		{
			printf("Enter The Valid Number : ");
			fflush(stdin);
			scanf("%d",&number);
		}
		printf("The factorial of %d is %ld\n",number,fact(number));
		printf("\n\n\t\tDo You Want to Enter Again?(y/n)");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='Y' || again =='y');
}

/*
METHOD THAT CALCULATES THE FACTORIAL
@param num : the number whoise factorial is to be determined.
@return long : returns the factorial
*/
long fact(int num)
{
	int i;
	long result=1;
	for(i=1;i<=num;i++)
		result*=i;
	return result;
}