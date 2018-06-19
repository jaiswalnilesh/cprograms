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
	struct node *l1, *l2,  *l3, *header2, *header3;
	int i=0;
	
	header1->nlink=NULL;
	header1->plink=NULL;

	l1=header1;
	
	printf("Enter the node for first list:\n");
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
	header3=header1;
	
	l1=header1;

	header2=(struct node *) malloc(sizeof(node));
	header2->plink=NULL;
	header2->nlink=NULL;
	

	l2=header2;
	printf("Enter the nodes for second list:\n");
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
	while(i<6);

	l2->nlink=NULL;
	
	
	l2=header2;
	
	header3=(struct node *) malloc(sizeof(node));
	header3->plink=NULL;
	header3->nlink=NULL;

	l3=header3;

	while(l1 && l2)
	{
		l3->nlink=(struct node *) malloc(sizeof(node));
		l3->nlink->plink=l3;
		
		if(l1->data < l2->data)
		{
			l3->data=l1->data;
			l1=l1->nlink;
		}
		else
		{
			l3->data=l2->data;
			l2=l2->nlink;
		}
		
		
		l3=l3->nlink;
		
		l3->nlink=NULL;

	}
	while(l1)
	{
		l3->data=l1->data;
		l1=l1->nlink;
		l3->nlink=(struct node *) malloc(sizeof(node));
		l3->nlink->plink=l3;
		l3=l3->nlink;
		l3->nlink=NULL;
	}
		
	while(l2)
	{
		l3->data=l2->data;
		l2=l2->nlink;
		l3->nlink=(struct node *) malloc(sizeof(node));
		l3->nlink->plink=l3;
		l3=l3->nlink;
		l3->nlink=NULL;
	}
	
	
	l1=header1;
	

	printf("\nFirst link list is :\n");
	while(l1->nlink!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->nlink;
	}
	printf("%3d",l1->data);

	printf("\nThe reverse order link list is :\n");
	while(l1!=NULL)
	{
		printf("%3d", l1->data);
		l1=l1->plink;
	}
	
	printf("\n");


	l2=header2;

	printf("\n");
	printf("Second link list is :\n");
	while(l2->nlink!=NULL)
	{
		printf("%3d",l2->data);
		l2=l2->nlink;
	}
	
	printf("%3d",l2->data);

	printf("\nThe reverse order link list is :\n");
	while(l2!=NULL)
	{
		printf("%3d", l2->data);
		l2=l2->plink;
	}
	
	l3=header3;
	
	printf("\nThe ordered link list is :\n");

	while(l3->nlink!=NULL)
	{
		printf("%3d",l3->data);
		l3=l3->nlink;
	}
	
	printf("\n");


	printf("\nThe reverse order link list is :\n");
	l3=l3->plink;
	while(l3!=NULL)
	{
		printf("%3d",l3->data);
		l3=l3->plink;
	}
	printf("\n");
}

