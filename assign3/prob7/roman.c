//Program to display the ROMAN Equivalent Of A Number
#include<stdio.h>
void main()
{
// It is the array that contains the characters to be displayed for an 
//roman equivalient
	char charsToDisplay[7]={'M','D','C','L','X','V','I'};
//It is the array that contains the actual count of the character that is to be 
//displayed by that much frequency
	int charsCount[7];
//
	int divisors[7]={1000,500,100,50,10,5,1};
	char again='n';
	int count,year,newCount;
	do
	{
		printf("Enter The Year TO Be Displayed In ROMANS : ");
		fflush(stdin);
		scanf("%d",&year);
		while(year<0)
		{
			printf("Enter The Valid Year : ");
			fflush(stdin);
			scanf("%d",&year);
		}
		for(count=0;count<7;count++)
		{
			charsCount[count]=year/divisors[count];
			year%=divisors[count];
		}
		if(charsCount[6]==4)
			count=5;
		for(newCount=0;newCount<count;newCount++)
		{
			while(charsCount[newCount]>0)
			{
				printf("%c",charsToDisplay[newCount]);
				charsCount[newCount]--;
			}
		}
		if(count==5)
			if(charsCount[5]==0)
				printf("IV");
			else
				printf("IX");
		printf("\n\n\t\tWant To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}