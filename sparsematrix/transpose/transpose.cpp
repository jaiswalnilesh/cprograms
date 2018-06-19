#include<stdio.h>
#include<malloc.h>
struct sparse
{
	int row,col,value;
	struct sparse* link;
};

void main()
{
	struct sparse  *header, *temp;
	int i, count=0;
	
	header=(struct sparse *)malloc (sizeof(sparse));
	
	printf("Enter the number of rows and columns for first matrix:");
	fflush(stdin);
	scanf("%d %d", &(header->row), &(header->col));
	printf("\n");
	printf("Enter the number of values to be entered:");
	fflush(stdin);
	scanf("%d", &(header->value));
	temp=header;

	printf("\n");
	printf("Enter the rows, cols and their values for first matrix:");

	for(i=0; i<header->value; i++)
	{
		temp->link=(struct sparse *) malloc (sizeof(sparse));
		temp=temp->link;
		fflush(stdin);
		scanf("%d %d %d", &(temp->row), &(temp->col), &(temp->value));
	}
	temp->link=NULL;

	

	printf("The sparse matrix is :");
	
	temp=header;
	
	while(temp)
	{
		printf("\n");
		printf("%3d %3d %3d", temp->row, temp->col, temp->value);
		temp=temp->link;
	}
	printf("\n");
	
	temp=header;

	while(temp)
	{
		temp->row = temp->row + temp->col;
		temp->col = temp->row - temp->col;
		temp->row = temp->row - temp->col;
		temp=temp->link;
	}

	temp=header;

	printf("Transpose of the sparse matrix is :\n");
	while(temp)
	{
		printf("\n");
		printf("%3d %3d %3d", temp->row, temp->col, temp->value);
		temp=temp->link;
	}
	printf("\n");
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         	
	

                                                                