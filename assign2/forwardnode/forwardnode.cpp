#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *nlink, *plink;
};

void main()
{
	struct node *header, *temp, *temp1;
	int pos, n;
	header=(struct node*) malloc(sizeof(node));

	header->data=1;
	header->plink=NULL;
	header->nlink=NULL;
	temp=header;

	for(int i=2;i<=10;i++)
	{
		temp->nlink=(struct node *) malloc(sizeof(node));
		temp->nlink->plink=temp;
		temp=temp->nlink;
		temp->data=i;
	}
	temp->nlink=NULL;
	temp=header;

	printf("The linked list is :\n");

	while(temp->nlink!=NULL)
	{
		printf("%3d",temp->data);
		temp=temp->nlink;
	}
	printf("%3d",temp->data);
	
	printf("\n");

	printf("The reverse order link list is :\n");

	while(temp!=NULL)
	{
		printf("%3d", temp->data);
		temp=temp->plink;
	}

	
	
	printf("\nEnter the node which is to be moved :\n");
	scanf("%d",&n);
	printf("\nEnter the position by which node  is to be moved :");
	printf("\n");
	scanf("%d",&pos);
	
	if(n+pos > 10)
		printf("The position does not exist\n");
	else
	{
		if(pos!=0)
		{
			temp=header;
			if(n==1)
			{
				header=temp->nlink;
				header->plink=NULL;
			}
			else
			{
				for(i=1;i<n;i++)
					temp=temp->nlink;
	
				temp->plink->nlink=temp->nlink;
				temp->nlink->plink=temp->plink;
			}

			temp1=temp->nlink;
		
			for(i=1;i<pos;i++)
				temp1=temp1->nlink;
		
			temp->nlink=temp1->nlink;
			temp1->nlink=temp;
			temp->plink=temp1;
			temp->nlink->plink=temp;
		}

		temp=header;
		printf("\nThe changed link list is :");

		while(temp->nlink!=NULL)
		{
			printf("%3d",temp->data);
			temp=temp->nlink;
		}
		printf("%3d",temp->data);
		printf("\n");

		printf("\nThe reverse order link list is :");

		while(temp!=NULL)
		{
			printf("%3d", temp->data);
			temp=temp->plink;
		}
		printf("\n");
	}
	
}
