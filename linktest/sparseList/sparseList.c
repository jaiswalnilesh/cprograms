/* Program to represent a Sparse Matrix in Link List in both row wise and column wise */

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#define M 3
#define N 3

struct Node
{
	int row;
	int col;
	int data;
	struct Node *RowNext;
	struct Node	*ColNext;

};

void addNode(struct Node**, struct Node**,int,int,int);
void deleteList(struct Node **first);

void main()
{
	struct Node *r,*c,*temp;
	int arr1[M][N];
	int i,j;
	r=c=NULL;
	
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
	
	//printf("\n\n");
	
	
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
			if(arr1[i][j] !=0)
				addNode(&r,&c,i,j,arr1[i][j]);
		}
		
	}

	temp=(struct Node*)malloc(sizeof(struct Node));
	
	temp->ColNext=c;
	temp->RowNext=r;
	r=temp;
	c=temp;
	temp->row=M;
	temp->col=N;
	temp->data=0;
	
	
/* Codes for Displaying the list */
	
	printf("\n\tRow Wise");
	temp=r;
	while(temp!=NULL)
	{
		printf("\n\t %d   %d   %d  \n",temp->row,temp->col,temp->data);
		temp=temp->RowNext;
	}
	
	printf("\n\n");

	printf("\n\tCol Wise");
	temp=c;
	while(temp!=NULL)
	{
		printf("\n\t %d   %d   %d  \n",temp->row,temp->col,temp->data);
		temp=temp->ColNext;
	}
	
	deleteList(&r);

}

/*
* Function to Free all the Memory allocated to the List
*	Parameters : Header of the List whose Nodes are to be deleted.
*	Returns    : Void.
*/
void deleteList(struct Node **first)
{
	struct Node *temp;
	while(*first!=NULL)
	{//Traverse till the end of the list deleting the Nodes
		temp=(*first)->RowNext;
		free(*first);
		*first=temp;
	}
}

void addNode(struct Node** first1, struct Node** first2,int row_no,int col_no,int element)
{
	char* str;
	struct Node  *temp1=*first1,*temp2=*first2,*prev,*temp;

	temp=(struct Node*)malloc(sizeof(struct Node));
	str=(char*)malloc(20);
	
	temp->RowNext=NULL;
	temp->ColNext=NULL;

	temp->row=row_no;
	temp->col=col_no;
	temp->data=element;

	if(temp1==NULL)
	{
		*first1=temp;
		*first2=temp;
	}
	else
	{
		while(temp1->RowNext!=NULL)
		{
			temp1=temp1->RowNext;
		}

		temp1->RowNext=temp;
		
		if(temp2->col>temp->col)
		{
			temp->ColNext=*first2;
			*first2=temp;
		}
		else
		{
			while(temp2!=NULL && temp2->col<=temp->col)
			{
				prev=temp2;
				temp2=temp2->ColNext;
			}
			prev->ColNext=temp;
			temp->ColNext=temp2;
		}
		
	
	}
}
