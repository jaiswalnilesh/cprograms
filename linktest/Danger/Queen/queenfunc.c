#include "stdio.h"
#include "stdlib.h"
#define N 8

char place(int n,int count,int row,int c);
int getabs(int);
int canexist(int row,int* col);
int rows[N]={0,-1},cols[N]={1,-1};//Declare arrays which com=ntain indexes of previosly placed queens globally  

/*Function to get absolute of an Integer
 *Parameters : Accepts an integer.
 *Returns	 : Absolute value of the Integer
*/
int getabs(int x)
{
	return ((x>0)? x:-x);
}

void main()
{
	char done;
	int count=1;
	do
	{//get the index of first queen from the user
		printf("Enter row no.(0-7)):");
		scanf("%d",&rows[0]);

		printf("Enter col no.(0-7)):");
		scanf("%d",&cols[0]);
		
		if(rows[0]<0 || rows[0]>(N-1) || cols[0]<0 || cols[0]>(N-1))
			printf("Enter valid nos.\n");

	}while(rows[0]<0 || rows[0]>(N-1) || cols[0]<0 || cols[0]>(N-1) );

	done=place(N,1,rows[0]+1,0);//call the function to place the rest of the queens.
	if(done=='y')
	for(count=0;count<N;count++)
	{
		printf("%d %d\n",rows[count],cols[count]);
	
	
	}
}
/*
* Function which places all the queen by calling itself again and again 
* Parameters 1:Integer to indicate the dimention of square matrix
*			 2:Integer representing count of queens place.(How many queens are placed)
*			 3:Row number in which queen has to be placed.
*			 4:Column number to start checking whether queen can be placed or not.	   		
* Returns   : char indicating whether queens can be placed or not  
*/
char place(int n,int count,int row,int c)
{
	int flag,col;
	if(count==n)//check whether all the queens ar placed or not
		return 'y';
	else
	{
		if(row==8)//if row is 8th whis is impossible make row =0
			row=0;
		if(row==-1)// else if row =-1 whih is impossible make row=7
			row=7;
		col=c;//start cheking from cth col.
			
		flag=canexist(row,&col);//check the flag whether the queen can be placed in that row or not.
		if(flag==0)//if flag==0 ..it means queen can be placed in (row, col) position..
		{//place the queen
			rows[count]=row;
			cols[count]=col;
		
			if(count<7)// if all queens are placed don't store any -1s.
			{
				rows[count+1]=-1;
				cols[count+1]=-1;
			}
									
			count++;

			place(N,count,++row,0);//call the function again to place the queen in the next row.
			
		}

		else
		{// if the queen can not be placed in this row..
			count--;// decrement count
			row=row-1;//go to previous row
			c=cols[count]+1;//check from the column where the queen is already placed
			rows[count]=-1;//change indexes 
			cols[count]=-1;
			if(count !=0)
				place(N,count,row,c);//call the function again to replace the queen in previous row.
			else
			{
				printf("Queens can not be placed");
				return 'n';
			}
		}
	}

}
/*
*Function that takes the row and col add. as input and checks in which col in that row the queen can be placed.
* Parameters 1: Integer representing the row no.
*			 2: Integer pointer pointing to col no. from where checking should start. 
* Returns	  : Returns integer indicating whether the queen can be placed in that row or not.
*/
int canexist(int row,int* col)
{
	int index=0,flag;//take an index and a flag.
	while(*col<N && *col>=0)
	{
		flag=0,index=0;
		while(cols[index] !=-1 )//check till the count
		{
			if(cols[index]==*col || (getabs(cols[index]-*col))==(getabs(rows[index]-row)))
			{//if any quuen is already placed in that col or that place is in digonal with some of the queens placed then break;
				flag=1;
				break;
			}
			else
			index++;// if not index++
		}
			if(flag==1)//if the specified col is not valid go to next column.
				*col=*col+1;
			else
				break;//and if the col is valid break 
			
	}
	if(flag==0 && *col<N)// if flafg is zero for some valid col return 0
	{
		return 0;
	}
	else
		return 1;// else queen can not be placed in the specified row.
}




