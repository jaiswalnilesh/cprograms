//program to show the given input number in letters
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	
	long number;
	char *numberToLetter(long number),again='n';
	do
	{
		printf("Enter A Number To Get Printed In Letters(Between 0 and 9999999) : ");
		fflush(stdin);
		scanf("%ld",&number);
		while(number<0 || number >9999999)
		{
			printf("Enter A Valid Number (Between 0 and 9999999) : ");
			fflush(stdin);
			scanf("%ld",&number);
		}
		printf("\n\nThe %ld Is Equivalent To %s",number,numberToLetter(number));
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
Method that returns the string equivalent of the number input
@return char * : returns the string equivalent of the number input
*/
char *numberToLetter(long number)
{
	char *specials[]={"TEN ","ELEVEN ","TWETEL ","THIRTEEN ","FOURTEEN ","FIFTEEN ","SIXTEEN ","SEVENTEEN ","EIGHTEEN ","NINETEEN "};
	char *decimels[]={"TEN", "TWENTY", "THIRTY", "FOURTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};
	char *units[]={" ZERO"," ONE"," TWO"," THREE "," FOUR "," FIVE "," SIX "," SEVEN "," EIGHT "," NINE "};
	char *hundereds[]={"HUNDRED","THOUSAND","LAKH"};
	int divisors[]={100000,1000,100,10,1};
	int quotient,digitCount=0;
	char *number1=(char *)malloc(150*sizeof(char));
	*number1='\0';
	if(number==0)
		strcpy(number1,"ZERO");	
	else
		while(number>0)
		{
			if((quotient=number/divisors[digitCount]) !=0)
			{
				if((digitCount==0)||(digitCount==1)||(digitCount==2))
				{
					if(quotient>=10)
						strcat(number1,decimels[(quotient/10)-1]);
					if(quotient%10!=0)
						strcat(number1,units[(quotient%10)]);
					switch (digitCount)
					{
					case 0:
						strcat(number1," LAKHS ");
						break;
					case 1:
						strcat(number1," THOUSAND ");
						break;
					case 2:
						strcat(number1," HUNDRED ");
						break;
					}
				}
				else if(digitCount==3)
				{
					if(quotient==1)
					{
						strcat(number1,specials[number%(divisors[digitCount])]);
						break;
					}
					else
						strcat(number1,decimels[quotient-1]);
				}
				else if(digitCount==4)
				{
					strcat(number1,units[quotient]);
				}
				number=number%divisors[digitCount];
			}
			digitCount++;
					
		}
	return number1;
}
