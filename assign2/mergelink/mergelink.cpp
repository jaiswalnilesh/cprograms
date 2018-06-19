#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *nlink, *plink;
};

void main()
{
	int i;
	struct node *header1=(struct node *) malloc(sizeof(node));
	struct node *l1, *header2, *header3;
	header1->data=1;
	header1->plink=NULL;
	header1->nlink=NULL;

	l1=header1;
	
	for(i=3;i<8;i+=2)
	{
		l1->nlink=(struct node *)malloc(sizeof(node));
		l1->nlink->plink=l1;
		l1=l1->nlink;
		l1->data=i;
	}
	l1->nlink=NULL;
	l1=header1;
	header3=header1;

	printf("First link list is :\n");
	while(l1->nlink!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->nlink;
	}
	
	printf("%3d",l1->data);
	
	printf("\nReverse of first link list is :\n");
	while(l1!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->plink;
	}
	

	
	
	l1=header1;

	header2=(struct node *) malloc(sizeof(node));
	header2->data=2;
	header2->plink=NULL;
	header2->nlink=NULL;

	struct node *l2=header2;
	
	for(i=4;i<9;i+=2)
	{
		l2->nlink=(struct node *)malloc(sizeof(node));
		l2->nlink->plink=l2;
		l2=l2->nlink;
		l2->data=i;
	}
	l2->nlink=NULL;
	
	l2=header2;

	printf("\n");
	printf("Second link list is :\n");
	while(l2->nlink!=NULL)
	{
		printf("%3d",l2->data);
		l2=l2->nlink;
	}
	printf("%3d",l2->data);

	printf("\n");
	printf("Reverse of second link list is :\n");
	while(l2!=NULL)
	{
		printf("%3d",l2->data);
		l2=l2->plink;
	}
	
	l2=header2;

	while(l1 && l2)
	{
		header1=l1->nlink;
		header2=l2->nlink;
		l1->nlink=l2;
		l2->plink=l1;
				
		if(header1)
		{
			l2->nlink=header1;
			l2->nlink->plink=l2;
		}
		
		l1=header1;
		l2=header2;
	}
	
	l1=header3;
	printf("\nThe merged link list is :\n");

	while(l1->nlink!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->nlink;
	}
	printf("%3d",l1->data);
	printf("\n");

	printf("\nThe Reverse of link list is :\n");

	while(l1!=NULL)
	{
		printf("%3d",l1->data);
		l1=l1->plink;
	}
	printf("\n");
}

