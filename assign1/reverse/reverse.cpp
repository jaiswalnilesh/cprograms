#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
void main()
{
	int i;
	struct node *header;
	header=(struct node*) malloc (sizeof(node));
	struct node *temp1,*temp2,*temp3;
	header->data=1;
	temp1=header;

	for(i=2;i<9;i++)
	{
		temp1->link=(struct node *) malloc (sizeof(node));
		temp1=temp1->link;
		temp1->data=i;
	}
	temp1->link=NULL;
	

    temp1=header;

	while(temp1!=NULL)
	{
		printf("%3d",temp1->data);
		temp1=temp1->link;
	}
	
	temp1=header;
	temp2=header->link;
	
	while(temp2!=NULL)
	{
		temp3=temp2->link;
		temp2->link=temp1;
		temp1=temp2;
		temp2=temp3;
	}
	
	header->link=NULL;
	header=temp1;

	printf("\n");

	while(temp1!=NULL)
	{
		printf("%3d",temp1->data);
		temp1=temp1->link;
	}
}