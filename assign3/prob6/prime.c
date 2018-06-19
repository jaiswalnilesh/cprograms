//PROGRAM to check whether the number entered is prime or not
#include<stdio.h>
#include<math.h>
void main()
{
	long number;
	char again='n';
	int checkForPrime(long number);
	do
	{
		printf("Enter the number to be checked as prime or not : ");
		scanf("%ld",&number);
		while(number<0)
		{
			printf("Enter A Valid Number");
			fflush(stdin);
			scanf("%ld",&number);
		}
		if(checkForPrime(number)==1)
			printf("Number %ld is a prime number",number);
		else
			printf("Number %ld is NOT a prime number",number);
		printf("\n\n\t\tDo You Want To Enter A Number Again?(y/n)");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}
/**
method that checks whether the specified number is prime or not
@param number : the number that is to be checked
@ratuens int : returns 1 if number is prime
		0 if number is not a prime number
*/
int checkForPrime(long number)
{
	int root,divisor;
	if(number==2 || number==1)
		return 1;
	else if(number%2==0)
		return 0;
	else
	{
		root=(int)sqrt(number);
		for(divisor=3;divisor<=root;divisor+=2)
			if(root%divisor==0)
				return 1;
		return 0;
	}
}