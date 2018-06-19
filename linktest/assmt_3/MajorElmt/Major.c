/* Program to find the majority element of the given array */

#include "stdio.h"
#include "stdlib.h"

void main()
{
	int *arr,i,flag=0,count=0,j,k;
	arr=malloc(400);

	i=0;
	printf("Enter Array Elements(-1 to terminate)");
	// Get the Array Elements from the user
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
	
	// Check for the majority Element
	for(j=0;j<((i-1)/2);j++)
	{
		count=0;// Reset count for every iteration
		for(k=0;k<(i-1);k++)
		{
			if(arr[j]==arr[k])
				count++;// Cont the no. of times variable is appering in the Array.
		}
		//if the variable occurs more then the limit specified it is the majority elment.   
		if(count>(i-1)/2)
		{
			printf("Majority Element is %d\n",arr[j]);
			flag=1;// Set fla gto one if u find a majority Element
			break;
		}
	}
	if(flag==0)// IF flag is zero there is no majority element
		printf("Sorry Boss\n");
}


