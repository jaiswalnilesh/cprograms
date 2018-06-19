#include "stdio.h"
#include "stdlib.h"
#define M 2
#define N 2

void main()
{
		int toFormat(int* arr,int m,int n,int* format);	
		int arr1[M][N],arr2[M][N],format1[20][3],format2[20][3],result[20][3],great,flag=0;
		int i,j,k,l,count1,count2;
		int row[20],col[20],ct=0,temp,flag1;	
			
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				fflush(stdin);
				printf("Enter arr1(%d , %d) : ",i,j);
				scanf("%d",&arr1[i][j]);	 
			
			}
		    printf("\n\n");
		}
		
		printf("\n\n");
		
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				fflush(stdin);
				printf("Enter arr2(%d , %d) : ",i,j);
				scanf("%d",&arr2[i][j]);	 
			
			}
			printf("\n\n");
		}



		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				printf("%d ",arr1[i][j]);
			}
			printf("\n");
		}

		printf("\n\n");

		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				printf("%d ",arr2[i][j]);
			}
			printf("\n");
		}

		printf("\n\n");

		count1=toFormat(&arr1[0][0],M,N,&format1[0][0]);
		count2=toFormat(&arr2[0][0],M,N,&format2[0][0]);

		for(i=0;i<count1;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d ",format1[i][j]);
			}
			printf("\n");
		}

		printf("\n\n");

		for(i=0;i<count2;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d ",format2[i][j]);
			}
			printf("\n");
		}
	
	printf("\n\n");

	if(count1>=count2)
		great=count1;
	else
		great=count2;
	
	if(format1[0][0]>=format2[0][0])
	{
		result[0][0]=format1[0][0];
	}
	else
		result[0][0]=format2[0][0];

	if(format1[0][1]>=format2[0][1])
	{
		result[0][1]=format1[0][1];
	}
	else
		result[0][1]=format2[0][1];

	result[0][2]=0;

	
	k=1;
	for(l=1,i=1;i<great;i++,l++)
	{
		flag=0,flag1=0;
		for(j=1;format2[j][0]<=format1[i][0];j++)
		{
			if(format2[j][0]==format1[i][0] && format2[i][1]==format1[j][1] )
			{
				result[k][0]=format1[i][0];
				result[k][1]=format1[i][1];
				result[k][2]=format1[i][2]+format1[j][2];
				row[ct]=result[k][0];
				col[ct]=result[k][1];
				row[ct+1]=-1;
				col[ct+1]=-1;
				k++;
				flag=1;
				ct++;
			}
				
		}

		if(flag==0)
		{
			for(temp=0;temp<ct;temp++)
			{
				if(row[temp]==format2[l][0] && format2[l][1]==col[temp])
				{
					flag1=1;
					break;
				}
						
			}
			if(i<=count2 && flag1==0)
			{
				result[k][0]=format2[l][0];
				result[k][1]=format2[l][1];
				result[k][2]=format2[l][2];
				k++;

			}
			
			flag1=0;
			for(temp=0;temp<ct;temp++)
			{
				if(row[temp]==format2[i][0] && format2[i][1]==col[temp])
				{
					flag1=1;
					break;
				}
						
			}
			
			if(i<=count1 && flag1==0)
			{
				
				result[k][0]=format1[i][0];
				result[k][1]=format1[i][1];
				result[k][2]=format1[i][2];
				k++;

			}
		}
	}

	for(i=0;i<k;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d ",result[i][j]);
			}
			printf("\n");
		}
}
		

int toFormat(int* arr,int m,int n,int* format)
{
	
	int i,j,k,count=1;
	*(format+0)=M; 
	*(format+1)=N;
	*(format+2)=0;
	k=1;

	
	for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if(*(arr+(i*N)+j) != 0)
				{
					*(format+(k*3)+0)=i;
					*(format+(k*3)+1)=j;
					*(format+(k*3)+2)=*(arr+(i*M)+j);
					k++;
					count++;
				}
			}
		}
	return count;
}

