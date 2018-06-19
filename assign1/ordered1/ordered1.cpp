#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* link;
};

void main()
{
	struct node *header1 =(struct node *) malloc(sizeof(node));
	struct node *l1, *header3, *l3, *temp, *prev;;
	int i=0;
	
	header1->link=NULL;

	l1=header1;
	
	printf("Enter the node for first list:");
	scanf("%d",&(l1->data));
	do
	{
		l1->link=(struct node *)malloc(sizeof(node));	
		l1=l1->link;
		scanf("%d",&(l1->data));
		l1->link=NULL;
		i++;
	}
	while(i<4);
	i=0;

	l1->link=NULL;
	l1=header1;
	header3=header1;

	printf("\nFirst link list is :\n");
	while(l1!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->link;
	}
	
	printf("\n");
	l1=header1;

	struct node *header2;
	
	header2=(struct node *) malloc(sizeof(node));
	header2->link=NULL;

	struct node* l2=header2;
	printf("Enter the nodes for second list:");
	scanf("%d",&(l2->data));
	
	do
	{
		l2->link=(struct node *)malloc(sizeof(node));
		l2=l2->link;
		scanf("%d",&l2->data);
		l2->link=NULL;
		i++;
	}
	while(i<4);
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
	
	if(l1->data > l2->data)
	{
		temp=l1;
		l1=l2;
		l2=temp;
	}
	
	header3=l1;

	temp=l1;

	while(temp && l2)
	{
		while((temp && l2) && l2->data > temp->data)
		{
			prev=temp;
			temp=temp->link;
		}
		prev->link= l2 ;
		if(temp != NULL)
		{
			l2 = temp ;
			temp = prev->link->link ;
			prev = prev->link ;
		}
		
	}
	if(prev)
		prev->link = l2 ;


	
	temp=header3;
	
	printf("\nThe ordered link list is :\n");

	while(temp!=NULL)
	{
		printf("%3d",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
