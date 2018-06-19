/* Program to check whether the given no. can be represented as the sum of two array elements */

#include "stdio.h"
#include "stdlib.h"

void main()
{
	int *arr,i,refer,flag=0,j,k;
	arr=malloc(400);

	i=0;
	printf("Enter Array Elements(-1 to terminate)");
	// Get the array from the user
	do
	{
		fflush(stdin);
		printf("\nEnter the array elment no. %d: ",i);	
		scanf("%d",&arr[i]);
		if(arr[i]<-1 || arr[i]>999999)
		{
			printf("\nEnter a valid no.:");
			i=i-1;
		}
	
	}while(arr[i++] != -1);

	realloc(arr,(i-1)*sizeof(int));
	
	printf("Enter the reference variable : ");
	// Get the Reference Variable
	scanf("%d",&refer);
	
	for(k=0;k<i-2;k++)
	{
		for(j=k+1;j<i-1;j++)
		{//Check whether a sum exists which is equal to reference variable 
			if(refer == (arr[k]+ arr[j]))
			{//If yes Print the sum and set flag to one
				printf("(arr[%d])%d + (arr[%d])%d = %d\n",k,arr[k],j,arr[j],arr[k]+arr[j]);
				flag=1;
			}
		
		}
	}
	if(flag==0)//If no sum is found which is equal to reference variable
		printf("\nSorry Boss");
}


