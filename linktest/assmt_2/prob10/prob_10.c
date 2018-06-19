/* Program to find the SADDLE POINT in the given matrix */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int row,cols,i,j,k,saddlePt=0,flag,small,col_small;
	int matrix[10][10];

	printf("\nEnter no.of rows:");
	scanf("%d",&row);

	printf("\nEnter no.of columns:");
	scanf("%d",&cols);

    for (i=0;i<row;i++)
	{
		printf("\n");
		for(j=0;j<cols;j++)
		{
			printf("( %d X %d ) :",i,j);
			fflush(stdin);
			scanf("%d",&matrix[i][j]);
		}
	}
		
	
	for(i=0;i<row;i++)
	{
		small=matrix[i][0];
		col_small=0;
		for(j=1;j<cols;j++) // Checking The Smallest element in the ith Row.
		{
			if(small>matrix[i][j])
			{
				small=matrix[i][j];
				col_small=j;
			}
		}
		flag=0;
		for(k=0;k<row;k++)// Checking if the smallest in row is greatest in the coloumn or not. 
		{
			
			if(small<matrix[k][col_small])
			{
				flag=1;// Set flag if the no. "small" is not a saddle point.
				break;		
			}
			
		
		}
		if(flag==0)
		{
			printf("Saddle point of the given array is %d\n",small);
			saddlePt=1;
		}
				
	}
	if(saddlePt==0)
		printf("No saddle Pt.\n");
}

