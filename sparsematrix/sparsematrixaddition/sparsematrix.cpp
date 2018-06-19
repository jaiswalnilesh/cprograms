#include<stdio.h>
#include<malloc.h>
struct sparse
{
	int row,col,value;
	struct sparse* link;
};

void main()
{
	struct sparse *header, *temp, *header1, *header2, *temp1, *temp2;
	int i, count=0;
	
	header1=(struct sparse *)malloc (sizeof(sparse));
	
	printf("Enter the number of rows and columns for first matrix:");
	fflush(stdin);
	scanf("%d %d", &(header1->row), &(header1->col));
	printf("\n");
	printf("Enter the number of values to be entered:");
	fflush(stdin);
	scanf("%d", &(header1->value));
	temp1=header1;

	printf("\n");
	printf("Enter the rows, cols and their values for first matrix:");

	for(i=0; i<header1->value; i++)
	{
		temp1->link=(struct sparse *) malloc (sizeof(sparse));
		temp1=temp1->link;
		fflush(stdin);
		scanf("%d %d %d", &(temp1->row), &(temp1->col), &(temp1->value));
	}
	temp1->link=NULL;

	
	header2=(struct sparse *)malloc (sizeof(sparse));
	header2->row=header1->row;
	header2->col=header1->col;
	
	printf("Enter the values to be entered for second matrix :");
	scanf("%d", &(header2->value));

	temp2=header2;


	printf("\nEnter the rows, cols and their values for second matrix:");

	for(i=0; i<header2->value; i++)
	{
		temp2->link=(struct sparse *) malloc (sizeof(sparse));
		temp2=temp2->link;
		fflush(stdin);
		scanf("%d %d %d", &(temp2->row), &(temp2->col), &(temp2->value));
	}
	temp2->link=NULL;

	printf("\n");
	printf("The first sparse matrix is :");
	
	temp1=header1;
	
	while(temp1)
	{
		printf("\n");
		printf("%3d %3d %3d", temp1->row, temp1->col, temp1->value);
		temp1=temp1->link;
	}
	
	printf("\n");
	printf("The second sparse matrix is :");
	
	temp2=header2;
	
	while(temp2)
	{
		printf("\n");
		printf("%3d %3d %3d", temp2->row, temp2->col, temp2->value);
		temp2=temp2->link;
	}

	temp1=header1->link;
	temp2=header2->link;

	header=(struct sparse *)malloc (sizeof(sparse));
	header->col=header1->col;
	temp=header;

	while(temp1 && temp2)
	{
		while((temp1 && temp2) && ((temp1->row==temp2->row) && (temp1->col==temp2->col)))
		{
			temp->link=(struct sparse *)malloc (sizeof(sparse));
			temp=temp->link;
			temp->row=temp1->row;
			temp->col=temp1->col;
			temp->value=temp1->value + temp2->value;
			temp1=temp1->link;
			temp2=temp2->link;
			count++;
		}
		
		
		while((temp1 && temp2) &&((temp1->row>temp2->row) || ((temp1->row==temp2->row)&& (temp1->col>temp2->col))))
		{
			temp->link=(struct sparse *)malloc (sizeof(sparse));
			temp=temp->link;
			temp->row=temp2->row;
			temp->col=temp2->col;
			temp->value=temp2->value;
			temp2=temp2->link;
			count++;
		}
		
		while((temp1 && temp2) && ((temp1->row<temp2->row) || ((temp1->row==temp2->row)&& (temp1->col<temp2->col))))
		{
			temp->link=(struct sparse *)malloc (sizeof(sparse));
			temp=temp->link;
			temp->row=temp1->row;
			temp->col=temp1->col;
			temp->value=temp1->value;
			temp1=temp1->link;
			count++;
		}
	}
	
	while(temp1)
	{
		temp->link=(struct sparse *)malloc (sizeof(sparse));
		temp=temp->link;
		temp->row=temp1->row;
		temp->col=temp1->col;
		temp->value=temp1->value;
		temp1=temp1->link;
		count++;
	}
	
	while(temp2)
	{
		temp->link=(struct sparse *)malloc (sizeof(sparse));
		temp=temp->link;
		temp->row=temp2->row;
		temp->col=temp2->col;
		temp->value=temp2->value;
		temp2=temp2->link;
		count++;
	}
	
	
	temp->link=NULL;
	
	temp=header;
	header->row=header1->row;
	header->col=header1->col;
	header->value=count;
		
	printf("\n");

	printf("The sparse matrix is :");
	
	printf("\n");
	
	while(temp)
	{
		printf("\n");
		printf("%3d %3d %3d", temp->row, temp->col, temp->value);
		temp=temp->link;
	}

}
		



	                                                                                                          