#include "stdio.h"
#include "stdlib.h"
#define N 8

void place(int n,int count,int row,int c);
int getabs(int);
int canexist(int row,int* col);
int rows[N]={0,-1},cols[N]={1,-1};

int getabs(int x)
{
	return ((x>0)? x:-x);
}

void main()
{
	int count=1;
	
	do
	{
		printf("Enter row no.(0-7):");
		scanf("%d",&rows[0]);

		printf("Enter col no.(0-7):");
		scanf("%d",&cols[0]);
		
		if(rows[0]<0 || rows[0]>7 || cols[0]<0 || cols[0]>7)
			printf("Enter valid nos.");

	}while(rows[0]<0 || rows[0]>7 || cols[0]<0 || cols[0]>7 );

	place(N,1,rows[0]+1,0);
	for(count=0;count<N;count++)
	{
		printf("%d %d\n",rows[count],cols[count]);
		
	}
}

void place(int n,int count,int row,int c)
{
	int flag,col;
	if(count==n)
		return;
	else
	{
		if(row==8)
			row=0;
		if(row==-1)
			row=7;
		col=c;
			
		flag=canexist(row,&col);
		if(flag==0)
		{
			rows[count]=row;
			cols[count]=col;
		
			if(count<7)
			{
				rows[count+1]=-1;
				cols[count+1]=-1;
			}
									
			count++;

			place(N,count,++row,0);
			
		}

		else
		{
			count--;
			c=cols[count]+1;
			rows[count]=-1;
			cols[count]=-1;
			place(N,count,--row,c);
		}
	}

}

int canexist(int row,int* col)
{
	int index=0,flag;
	while(*col<N && *col>=0)
	{
		flag=0,index=0;
		while(cols[index] !=-1 )
		{
			if(cols[index]==*col || (getabs(cols[index]-*col))==(getabs(rows[index]-row)))
			{
				flag=1;
				break;
			}
			index++;
		}
			if(flag==1)
				*col=*col+1;
			else
				break;
			
	}
	if(flag==0 && *col<N)
	{
		return 0;
	}
	else
		return 1;
}




