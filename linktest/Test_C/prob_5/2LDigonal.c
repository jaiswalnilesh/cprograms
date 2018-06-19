/* Program to make a marix using two lower digonal matrix */

#include "stdlib.h"
#include "stdio.h"

void main()
{
	int arr1[3][3]={0},arr2[3][3]={0},arr3[3][4]={0};
	int count,j,i=1;
	
		for (count=0;count<3;count++)
		{
			for(j=0;j<=count;j++)
			{
				printf("Enter arr1(%d , %d) : ",count,j);
				scanf("%d",&arr1[count][j]);
			
			}
		}
	printf("\n\n");		
		for (count=0;count<3;count++)
		{
			for(j=0;j<=count;j++)
			{
				printf("Enter arr2(%d , %d) : ",count,j);
				scanf("%d",&arr2[count][j]);
			
			}
		}
	
//logic starts
	for(count=0;count<3;count++)
	{
		for(j=0;j<4;j++)
		{
			if(j<=count)
				arr3[count][j]=arr1[count][j];
			else
				arr3[count][j]=arr2[j-1][count];
		}
	}
//logic ends

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",arr1[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",arr2[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",arr3[i][j]);
		}
		printf("\n");
	}


}

