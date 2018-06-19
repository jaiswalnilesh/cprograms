#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* link;
};

void main()
{
	int i;
	struct node *header1=(struct node *) malloc(sizeof(node));
	struct node *l1, *l2, *header3, *header2;
	header1->data=1;
	header1->link=NULL;

	l1=header1;
	
	/* First list */
	
	for(i=3;i<8;i+=2)
	{
		l1->link=(struct node *)malloc(sizeof(node));
		l1=l1->link;
		l1->data=i;
	}
	l1->link=NULL;
	l1=header1;
	header3=header1;

	printf("First link list is :\n");
	while(l1!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->link;
	}
	
	l1=header1;

	header2=(struct node *) malloc(sizeof(node));
	header2->data=2;
	header2->link=NULL;

	l2=header2;
	
	/* Second list entered */
	for(i=4;i<9;i+=2)
	{
		l2->link=(struct node *)malloc(sizeof(node));
		l2=l2->link;
		l2->data=i;
	}
	l2->link=NULL;
	
	l2=header2;

	printf("\n");
	printf("Second link list is :\n");
	while(l2!=NULL)
	{
		printf("%3d",l2->data);
		l2=l2->link;
	}
	
	l2=header2;

	while(l1 && l2)
	{
		header1=l1->link;
		header2=l2->link;
		l1->link=l2;
		
		if(header1)
			l2->link=header1;
		
		l1=header1;
		l2=header2;
	}
	
	l1=header3;
	printf("\nThe merged link list is :\n");

	while(l1!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->link;
	}
	printf("\n");
}

