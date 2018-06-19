// program to print the given number in words
#include <stdio.h>

void main()
{
	int num=-1,temp,count;

	int ref[]={1000000,100000,10000,1000,100,10,1};

	int result[7];

	char *OneToNine[]={"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
	char *TenToNineteen[]={"Ten","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};

	char *TwentyToNinty[]={"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninty "};
	

	while (num>9999999 || num<0)
	{
		printf("Enter any +ve number(max five digit)  ");
		fflush(stdin);
		scanf("%d",&num);
		if(num>9999999 || num<0)
		{
			printf("Enter a valid value\n");
		}
	
	}

	temp=num;
// Sggrigate the digits 
	for (count=0; count<7;count++)
	{
		result[count]=num/ref[count];
		num=num%ref[count];
		
	}
    
// Check for Duplates AND call appropriate Arrays to print the words. 

	if(result[0]!=0 || result[1]!=0)
	{
		if(result[0]==1)
		{
			printf("%s ",TenToNineteen[result[1]]);
		}
		else
		{
			printf("%s ",TwentyToNinty[result[0]]);
			if(result[1]!=0)
				printf("%s ",OneToNine[result[1]]);
		}
		printf("Lack ");
	}

	if(result[2]!=0 || result[3]!=0)
			
	{
		if(result[2]==1)
		{
			printf("%s ",TenToNineteen[result[3]]);
		}
		else
		{
			printf("%s ",TwentyToNinty[result[2]]);
			if(result[3]!=0)
				printf("%s ",OneToNine[result[3]]);
		}
		printf("Thousand ");
		
	}
	
	if(result[4]!=0)
	printf("%s Hundred ",OneToNine[result[4]]);

	if(result[5]!=0 || result[6]!=0)
			
	{
		if(result[5]==1)
		{
			printf("%s ",TenToNineteen[result[6]]);
		}
		else
		{
			printf("%s ",TwentyToNinty[result[5]]);
			if(result[6]!=0)
				printf("%s ",OneToNine[result[6]]);
		}
		
	}

	printf("\n");		
}


