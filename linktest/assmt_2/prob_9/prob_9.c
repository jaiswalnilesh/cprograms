/* Program to Find the MODE in the given array */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	unsigned int count=0;
	char again;
	int *DataArr,mode;
	int findMode(int *arr ,int arr_count);
	do
	{
		printf("Enter elments of array(0 to stop)");
		DataArr=(int*)malloc(1000);
		do
		{
			printf("\nEnter the number :");
			fflush(stdin);
			scanf("%d",&DataArr[count++]);

		}while(DataArr[count-1]!=0);
		
		realloc(DataArr,(count-1)*sizeof(int)+1);

		mode = findMode(DataArr,count-1);

		if(mode ==0)	
			printf(" NO Mode");	
		else
			printf("Mode of the given Array is %d", mode);
				
		printf("\t\tDO U WANNA REPEATE (y/n):");
		scanf("%c",&again);

	}while(again=='y' || again=='Y');

}

/*
*Function to find the mode of the given Array.
*Parameters : 1) Base Address of the Array
			  2) Number of Elements in the Given Array
*return		: 0 if mode is not there
			  Else Mode of the given Array.
*/			  
int findMode(int *arr ,int arr_count)
{
	int i,j=0,count,count1=0,mode,flag=0;
	for (i=0;i<arr_count;i++)
	{
		if(arr[i]!=mode)
		{
			count=1;
			for(j=0;j<arr_count;j++)
			{
				if(i==j)
					continue;
				if(arr[i]==arr[j])
				count++;
			
			}
		
			if((count==count1))
			{
			   flag=1;
			}
			else
			if(count>count1)
			{
				count1=count;
				mode=arr[i];
				flag=0;
				if(count>arr_count/2)
					break;
			}
		}
	}
		if(flag==1)
			mode=0;

		return mode;
				
}



