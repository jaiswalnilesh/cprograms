#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *link;
};

void main()
{
	struct node *header, *temp, *temp1, *prev;
	int pos, n;
	header=(struct node*) malloc(sizeof(node));

	header->data=1;
	header->link=NULL;
	temp=header;

	for(int i=2; i<=10; i++)
	{
		temp->link=(struct node *) malloc(sizeof(node));
		temp=temp->link;
		temp->data=i;
	}
	temp->link=NULL;
	temp=header;

	printf("The linked list is :\n");

	while(temp!=NULL)
	{
		printf("%3d", temp->data);
		temp=temp->link;
	}
	
	printf("\n");
	
	
	printf("Enter the node which is to be moved :\n");
	scanf("%d",&n);
	printf("\nEnter the position by which node  is to be moved :");
	printf("\n");
	scanf("%d", &pos);

	if(n + pos > 10) /* If node does not exist */
		printf("The node does not exist");
	else
	{
		if(pos != 0)
		{
			prev=temp=header;
		
			if(n==1)
				header=temp->link;

			for(i=1;i<n;i++)
			{
				prev=temp;
				temp=temp->link;
			}

			prev->link=temp->link;
	
			temp1=temp->link;
	
			for(i=0;i<pos;i++)
			{
				prev=temp1;
				temp1=temp1->link;
			}
			prev->link=temp;
			temp->link=temp1;
		}
	

		temp=header;
		printf("The changed link list is :");

		while(temp!=NULL)
		{
			printf("%3d",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}
