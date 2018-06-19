/* Program to store a digonal matrix in a single dimension array */

#include "stdio.h"

void main()
{
	int arr[3][3]={0},result[6];
	int j,i,k=0;
	
	for (i=0;i<3;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("Enter arr(%d , %d) : ",i,j);
			scanf("%d",&arr[i][j]);
			result[k]=arr[i][j];		
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	do
	{
		fflush(stdin);
		printf("Enter the row number of element you wanna access(0-2):");
		scanf("%d",&i);
		printf("Enter the col number of element you wanna access(0-2):");
		scanf("%d",&j);
	}while(i<0||j<0||j>2||i>2);
	
	if(j<=i)
	printf("The NUMBER is %d\n",result[((i*(i+1))/2)+j] );
	else
	printf("The NUMBER is 0\n");
}
