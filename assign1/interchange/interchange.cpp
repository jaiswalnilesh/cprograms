#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* link;
};

void main()
{
	int i, node1, node2;
	struct node *header=(struct node *) malloc(sizeof(node));
	struct node* temp, *temp1, *prev;
	header->data=1;
	header->link=NULL;
	
	temp=header;
	
	for(i=2;i<10;i++)
	{
		temp->link=(struct node *)malloc(sizeof(node));
		temp=temp->link;
		temp->data=i;
	}
	temp->link=NULL;
	temp=header;
	
	printf("link list is :\n");
	while(temp!=NULL)
	{
		printf("%3d",temp->data);
		temp=temp->link;
	}

	printf("\n");

	printf("Enter the nodes to be interchanged :");
	printf("\n");
	scanf("%d", &node1);
	scanf("%d", &node2);
	

	/* If nodes entered are not in the list */
	if(node1 > 9 )
		printf("\n First node does not exist\n");
	else
		if(node2 > 9) 
		printf("\n Second node does not exist\n");
	
	if(node1 <= 9  && node2 <= 9)
	{
		if(node2 < node1) /* Second node entered is smaller then interchange both the nodes */
		{
			node2=node1 + node2;
			node1=node2 - node1;
			node2=node2 - node1;
		}

	if(node1==node2) /* If both the nodes entered are equal */
	{
		temp=header;
		printf("link list is :\n");
		
		while(temp!=NULL)
		{
			printf("%3d",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
	else  
	{
		temp=header;
		prev=temp;
	
		for(i=1;i<node1;i++) /* Traverse upto first node */
		{
			prev=temp;
			temp=temp->link;
		}
	
		temp1=temp;

		for(i=node1+1;i<node2;i++) /* Traverse upto second node */
			temp1=temp1->link;
	
		if(node1==1 && node2!=2) /* Node entered first is first node and other is not he adjacent node */
		{
			header=temp1->link;
			prev=temp1->link->link;
			temp1->link->link=temp->link;
			temp->link=prev;
			temp1->link=temp;			
		}
		else
			if(node1==1 && node2==2) /* First node is header nad second is adjacent node */
			{
				prev=temp1->link->link;
				header=temp->link;
				header->link=temp;
				temp->link=prev;
			}
			else
				if(node1!=1 && node2==node1+1) /* Both are adjacent nodes */
				{
					prev->link=temp1->link;
					prev=temp->link->link;
					temp1->link->link=temp;
					temp->link=prev;
				}
				else
				{
					prev->link=temp1->link; /* Both are distinct nodes */
					prev=temp1->link->link;
					temp1->link->link=temp->link;
					temp1->link=temp;
					temp->link=prev;
				} 

			temp=header;
	
		printf("New list is :\n");

		while(temp!=NULL)
		{
			printf("%3d",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}}
}




	