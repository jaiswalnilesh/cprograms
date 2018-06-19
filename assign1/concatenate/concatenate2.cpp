#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};

void main()
{
	int i=0;
	struct node *header1=(struct node *) malloc(sizeof(node));
	struct node	*temp1, *temp2, *header2;
	header1->link=NULL;

	temp1=header1;
	/* for first list */
	printf("Enter the node for first list:");
	scanf("%d",&(temp1->data));
	do
	{
		temp1->link=(struct node *)malloc(sizeof(node));	
		temp1=temp1->link;
		scanf("%d",&(temp1->data));
		temp1->link=NULL;
		i++;
	}
	while(i<4);
	
	i=0;

	temp1->link=NULL;
	
	temp1=header1;
	printf("\nFirst link list is :\n");
	while(temp1!=NULL)
	{
		printf("%3d",temp1->data);
		temp1=temp1->link;
	}

	/* End of first list */
	
	printf("\n");
	temp1=header1;

	/* Second list */
	header2=(struct node *) malloc(sizeof(node));
	header2->link=NULL;

    temp2=header2;
	printf("Enter the nodes for second list:");
	scanf("%d",&(temp2->data));
	
	do
	{
		temp2->link=(struct node *)malloc(sizeof(node));
		temp2=temp2->link;
		scanf("%d",&temp2->data);
		temp2->link=NULL;
		i++;
	}
	while(i<4);
	temp2->link=NULL;
	
	temp2=header2;

	printf("\n");
	printf("Second link list is :\n");
	while(temp2!=NULL)
	{
		printf("%3d",temp2->data);
		temp2=temp2->link;
	}
	
	
	/* Second list ends */

	temp1=header1;
	
	while(temp1->link!=NULL)/* Take first list to the end */
		temp1=temp1->link;

	temp1->link=header2; /* Set the link of the last node to the start of second list */
	temp1=header1;

	printf("\n");

	printf("The concatenated list is :");
	while(temp1!=NULL)
	{
		printf("%3d",temp1->data);
		temp1=temp1->link;
	}
	printf("\n");

}