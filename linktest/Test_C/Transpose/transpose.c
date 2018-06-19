/*Program to create transpose of a matrix given in sparse format */

#include "stdio.h"
#include "stdlib.h"
#define M 5
#define N 5

void main()
{
	
		int arr[M][N],format[20][3];
		int i,j,k,count=1;
		
		format[0][0]=M; 
		format[0][1]=N;
		format[0][2]=0;
		k=1;
			
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				fflush(stdin);
				printf("Enter arr(%d , %d) : ",i,j);
				scanf("%d",&arr[i][j]);	 

				if(arr[i][j] != 0)
				{
					format[k][0]=i;
					format[k][1]=j;
					format[k][2]=arr[i][j];
					k++;
					count++;
				}
			}
		}	

		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		
		printf("\n\n");
		
		for(i=0;i<count;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d ",format[i][j]);
			}
			printf("\n");
		}
	
	printf("\n\n");
	{
		for(i=1;i<count;i++)
		{
			j=format[i][0];
			format[i][0]=format[i][1];
			format[i][1]=j;
		
		}
		
		for(i=1;i<count;i++)
		{
			for(j=i+1;j<count;j++)
			{
				if(format[i][0]>format[j][0])
				{
					k=format[i][0];
					format[i][0]=format[j][0];
					format[j][0]=k;

					k=format[i][1];
					format[i][1]=format[j][1];
					format[j][1]=k;										

					k=format[i][2];
					format[i][2]=format[j][2];
					format[j][2]=k;					
					

				}
						
			}
			
		}

	for(i=0;i<count;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d ",format[i][j]);
			}
			printf("\n");
		}

 
	}

}

