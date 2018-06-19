#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
void main()
{
	struct node *header=(struct node *) malloc (sizeof(node));
	struct node *temp, *temp1;
	int i=0;
	
	header->link=NULL;
	temp=header;
	
	/* Create the list */
	
	printf("Enter the values for list:");
	scanf("%d",&(temp->data));
	do
	{
		temp->link=(struct node *)malloc(sizeof(node));	
		temp=temp->link;
		scanf("%d",&(temp->data));
		temp->link=NULL;
		i++;
	}
	while(i<9);
	
	temp->link=NULL;
	

	temp=header;

	printf("\n Linked list is :\n");
	
	while(temp!=NULL)
	{
		printf("%3d",temp->data);
		temp=temp->link;
	}	

	
	printf("\nAfter deleting second node, the new linked list is :\n");

	temp=header;

	/* Delete the second node */
	
	while(temp)
	{
		temp1=temp->link;
		temp->link=temp->link->link;
		free(temp1);
		temp=temp->link;
	}

	temp=header;

	while(temp!=NULL)
	{
		printf("%3d",temp->data);
		temp=temp->link;
	}

	printf("\n");
}