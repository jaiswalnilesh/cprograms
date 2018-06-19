//PROGRAM TO PRINT ARMSTRONG NUMBERS BETWEEN 1 AND 500
#include<stdio.h>
#include<math.h>
void main()
{
	int sum=0,count,count1;
	printf("Following is the list of the Armstrong Numbers Upto 500\n");
	for(count=1;count<=500;count++)
	{
		count1=count;
		while(count1>0)
		{
			sum=sum+(int)(pow(count1%10,3));
			count1/=10;
		}
		if(sum==count)
			printf(" %d ",count);
		sum=0;
	}
	printf("\n");
}