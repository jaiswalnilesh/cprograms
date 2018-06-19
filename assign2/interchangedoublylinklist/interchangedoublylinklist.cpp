
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *nlink, *plink;
};

void main()
{
	int i, node1, node2;
	struct node *header=(struct node *) malloc(sizeof(node));
	struct node* temp, *temp1, *prev;
	header->data=1;
	header->nlink=NULL;
	header->plink=NULL;
	
	temp=header;
	
	for(i=2;i<10;i++)
	{
		temp->nlink=(struct node *)malloc(sizeof(node));
		temp->nlink->plink=temp;
		temp=temp->nlink;
		temp->data=i;
	}
	temp->nlink=NULL;
	temp=header;
	
	printf("link list is :\n");
	while(temp->nlink!=NULL)
	{
		printf("%3d",temp->data);
		temp=temp->nlink;
	}

	printf("%3d", temp->data);



	printf("\n");

	printf("The reverse of the link list is :");

	while(temp!=NULL)
	{
		printf("%3d", temp->data);
		temp=temp->plink;
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
		printf("nlink list is :\n");
		
		while(temp!=NULL)
		{
			printf("%3d",temp->data);
			temp=temp->nlink;
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
			temp=temp->nlink;
		}
	
		temp1=temp;

		for(i=node1+1;i<node2;i++) /* Traverse upto second node */
			temp1=temp1->nlink;
	
		if(node1==1 && node2!=2) /* Node entered first is first node and other is not he adjacent node */
		{
			header=temp1->nlink;
			header->plink=NULL;
			temp->nlink->plink=header;
			prev=temp1->nlink->nlink;
			prev->plink=temp;
			temp->plink=temp1;
			temp1->nlink->nlink=temp->nlink;
			temp->nlink=prev;
			temp1->nlink=temp;			
		}
		else
			if(node1==1 && node2==2) /* First node is header nad second is adjacent node */
			{
				prev=temp1->nlink->nlink;
				header=temp->nlink;
				header->plink=NULL;
				header->nlink=temp;
				temp->plink=header;
				prev->plink=temp;
				temp->nlink=prev;
			}
			else
				if(node1!=1 && node2==node1+1) /* Both are adjacent nodes */
				{
					prev->nlink=temp1->nlink;
					temp1->nlink->plink=prev;
					prev=temp->nlink->nlink;
					temp1->nlink->nlink=temp;
					temp->plink=temp->nlink;
					temp->nlink=prev;
					prev->plink=temp;
				}
				else
				{
					prev->nlink=temp1->nlink; /* Both are distinct nodes */
					temp1->nlink->plink=prev;
					prev=temp1->nlink->nlink;
					temp1->nlink->nlink=temp->nlink;
					temp->nlink->plink=temp1->nlink;
					temp1->nlink=temp;
					temp->nlink=prev;
					prev->plink=temp;
					temp->plink=temp1;
					temp->nlink->plink=temp;
				} 

			temp=header;
	
		printf("New list is :\n");

		while(temp->nlink!=NULL)
		{
			printf("%3d",temp->data);
			temp=temp->nlink;
		}
		printf("%3d",temp->data);
		
		printf("\n");

		printf("The reverse of the link list is :\n");

	while(temp!=NULL)
	{
		printf("%3d", temp->data);
		temp=temp->plink;
	}
	}}
	printf("\n");
}




	




