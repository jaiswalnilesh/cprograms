#include "stdio.h"
#include "stdlib.h"
#define M 3
#define N 3

void main()
{
		int toFormat(int* arr,int m,int n,int* format);	
		void addSparse(int* arr1,int* arr2,int* ans);	
		int arr1[M][N]/*={0,0,4,9,9,0,0,0,1}*/,arr2[M][N]/*={0,0,2,0,3,0,6,0,3}*/,format1[20][3],format2[20][3],result[20][3];
		int i,j,count1,count2;
				
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

		count1=toFormat(arr1,M,N,format1);
		count2=toFormat(arr2,M,N,format2);

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
	addSparse(format1,format2,result);

	for(i=0;i<=result[0][2];i++)
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
	*(format+2)=k-1;
	return count;
}

void addSparse(int* arr1,int* arr2,int* ans)
{
	int a1,a2,i,count=1;

	a1=1;//*(arr1+2);
	a2=1;
		
	
	for(i=0;i<(*(arr1)*(*(arr1+1)));i++)
	{
		if(a1>(*(arr1+2)) || a2>(*(arr2+2)))
		{
			if(a1>*(arr1+2))
			{
				while(a2<=*(arr2+2))
				{
					*(ans+(count*3))=*(arr2+(a2*3));
					*(ans+(count*3)+1)=*(arr2+(a2*3)+1);
					*(ans+(count*3)+2)=*(arr2+(a2*3)+2);
					a2++;
					count++;
				}
			}
			else
			{
				while(a1<=*(arr1+2))
				{
					*(ans+(count*3))=*(arr1+(a1*3));
					*(ans+(count*3)+1)=*(arr1+(a1*3)+1);
					*(ans+(count*3)+2)=*(arr1+(a1*3)+2);
					a1++;
					count++;
				}
			}
		break;
		
		}

		
			if((*(arr1+(a1*3)) == *(arr2+(a2*3)))&&((*(arr1+(a1*3)+1) == *(arr2+(a2*3)+1))))
			{
				*(ans+(count*3))=*(arr1+(a1*3));
				*(ans+(count*3)+1)=*(arr1+(a1*3)+1);
				*(ans+(count*3)+2)=*(arr1+(a1*3)+2)+*(arr2+(a2*3)+2);
				a1++;
				a2++;
				count++;
			}
			else 
			{
				if( ((*(arr1+a1*3)) > (*(arr2+a2*3)))||((((*(arr1+a1*3)) == (*(arr2+a2*3))))&&(((*(arr1+a1*3+1)) > (*(arr2+a2*3+1))))))
				{
					
					*(ans+(count*3))=*(arr2+(a2*3));
					*(ans+(count*3)+1)=*(arr2+(a2*3)+1);
					*(ans+(count*3)+2)=*(arr2+(a2*3)+2);
					a2++;
					count++;
					

				}
				else
				{
					
					*(ans+(count*3))=*(arr1+(a1*3));
					*(ans+(count*3)+1)=*(arr1+(a1*3)+1);
					*(ans+(count*3)+2)=*(arr1+(a1*3)+2);
					a1++;
					count++;
				}
			}
		
		
	}

	*(ans+2)=count-1;
	if(*(arr1)>=*(arr2))
		*(ans)=*arr1;
	else
		*ans=*arr2;
	if(*(arr1+1)>=*(arr2+1))
		*(ans+1)=*(arr1+1);
	else
		*(ans+1)=*(arr2+1);
	

}