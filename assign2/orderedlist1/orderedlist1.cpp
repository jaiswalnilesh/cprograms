#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node	*nlink, *plink;
};

void main()
{
	struct node *header1 =(struct node *) malloc(sizeof(node));
	struct node *l1, *l2,  *l3, *header2, *header3, *temp, *prev;;
	int i=0;
	header1->plink=NULL;
	header1->nlink=NULL;

	l1=header1;
	
	printf("Enter the node for first list:");
	scanf("%d",&(l1->data));
	do
	{
		l1->nlink=(struct node *)malloc(sizeof(node));	
		l1->nlink->plink=l1;
		l1=l1->nlink;
		scanf("%d",&(l1->data));
		l1->nlink=NULL;
		i++;
	}
	while(i<4);
	i=0;

	l1->nlink=NULL;
	l1=header1;
	header3=header1;

	printf("\nFirst link list is :\n");
	while(l1!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->nlink;
	}
	
	printf("\n");
	l1=header1;

	
	
	header2=(struct node *) malloc(sizeof(node));
	header2->plink=NULL;
	header2->nlink=NULL;

	l2=header2;
	printf("Enter the nodes for second list:");
	scanf("%d",&(l2->data));
	
	do
	{
		l2->nlink=(struct node *)malloc(sizeof(node));
		l2->nlink->plink=l2;
		l2=l2->nlink;
		scanf("%d",&l2->data);
		l2->nlink=NULL;
		i++;
	}
	while(i<4);
	l2->nlink=NULL;
	
	l2=header2;

	printf("\n");
	printf("Second link list is :\n");
	while(l2!=NULL)
	{
		printf("%3d",l2->data);
		l2=l2->nlink;
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
			temp=temp->nlink;
		}
		
		temp->plink->nlink=l2;
		l2->plink=temp->plink;
		
		if(temp != NULL)
		{
			l2 = temp ;
			temp = prev->nlink->nlink ;
			prev = prev->nlink ;
		}
		
	}
	if(prev)
	{
		prev->nlink = l2 ;
		l2->plink=prev;
	}


	
	temp=header3;
	
	printf("\nThe ordered link list is :\n");

	while(temp->nlink!=NULL)
	{
		printf("%3d",temp->data);
		temp=temp->nlink;
	}
	printf("%3d",temp->data);
	
	printf("\n");



	printf("\nThe reverse of order link list is :\n");

	while(temp!=NULL)
	{
		printf("%3d",temp->data);
		temp=temp->plink;
	}
	printf("\n");
}
