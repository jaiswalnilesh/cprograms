/*
#include "stdio.h"
#include "stdlib.h"
#define N 8
void place(int n,int count,int row,int* rows,int* cols,int iter,int c);
int getabs(int);

int getabs(int x)
{
	return ((x>0)? x:-x);
}

void main()
{
	int rows[8]={0,-1},cols[8]={4,-1},count=1;
	
	place(N,1,0,rows,cols,0,0);

	for(count=0;count<8;count++)
	{
		printf("%d %d\n",rows[count],cols[count]);
	
	
	}
}

void place(int n,int count,int row,int* rows,int* cols,int iter,int c)
{
	int index=0,flag=0,flag2=0,i,col;
	if(count==n)
		return;
	else
	{
		col=0;
		row++;
		if(iter>0)
			col=c+1;
		for(i=0;col<8 && col>0;i++)
		{
		
			flag=0,flag2=0,index=0;
			while(*(cols+index)!=-1)
			{
				if(col==*(cols+index))
				{
					flag=1;
					break;
				}
				index++;
			}
			
			if(flag==1)
				col++;
			else
			{
				index=0;
				while(*(cols+index)!=-1)
				{
					if( getabs(*(cols+index)-col) == getabs(*(rows+index)-row) )					
					{
						flag2=1;
						break;
					}
					index++;
				}
			}

			if(flag2==1)
				col++;
			if(flag2==0 && flag==0)
				break;
			
		}
		
		if(flag==0 && flag2==0 && col<8 && col>0)
		{
			*(rows+count)=row;
			*(cols+count)=col;
			
			*(rows+count+1)=-1;
			*(cols+count+1)=-1;
			count++;
			iter=0;
			
			place(N,count,row,rows,cols,iter,0);
		}

		else
		{
			count--;
			row=row-2;
			c=*(cols+count);
			*(rows+count)=-1;
			*(cols+count)=-1;
			
			iter++;
			place(N,count,row,rows,cols,iter,c);
		}
	}

}
*/