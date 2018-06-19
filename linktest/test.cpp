#include<stdio.h>
#include<malloc.h>
struct node
{
	char city[5];
	int year;
	struct node *link1, *link2;	
};
int xstrcmp(char*, char*);
void main()
{
	struct node *header1, *temp1, *temp2, *header2, *temp, *temp3;
	void delete1(struct node **, struct node*);
	void y_addnode(struct node **, struct node *);
	void c_addnode(struct node **, struct node *);
	int choice;
	temp3 = NULL;
	
	header1 = NULL;
	header2 = header1 ;
		
	do
	{
		printf("\n");
		printf("1 Want to add the node :\n");
		printf("2 Want to display the Year-wise sorted list :\n");
		printf("3 Want to display the City-wise sorted list :\n");
		printf("4 Want to delete the node :\n\n");
		printf(" Enter your choice :");
		fflush(stdin);
		scanf("%d", &choice);
	switch(choice)
	{
	case 1 :
		
		temp = (struct node *) malloc (sizeof(node));
		printf("Enter the year and the city : ");
		scanf("%d", &(temp->year));
		scanf("%s", &(temp->city));
		y_addnode(&header1, temp);
		c_addnode(&header2, temp);
		break;

	case 2 :
		
		temp1 = header1;
		
		printf("\n Year-wise sorted list is : \n ");
	
		while(temp1)
		{
			printf(" \n %d %s", temp1->year, temp1->city);
			temp1 = temp1->link1;
		}
		break;
	
	case 3 :
		
		temp2 = header2;
		printf("\n City-wise sorted list is : ");
	
		while(temp2)
		{
			printf(" \n %d %s", temp2->year, temp2->city);
			temp2 = temp2->link2;
		}
		break;

	case 4 :
	
		struct node *node1 = (struct node *)malloc(sizeof(node));	
		printf("\n Enter the year and city of the node to be deleted:");
		fflush(stdin);
		scanf("%d", &(node1->year));
		scanf("%s", &(node1->city));
		
		temp1 = header1;
		temp2 = header2;
	
		if( xstrcmp(header2->city, node1->city) == 0 )
		{
			temp3 = header2;
			header2 = header2->link2;
			temp2 = NULL;
		}
	
		if( header1->year == node1->year)
		{
			header1 = header1->link1;
			temp1 = NULL;
		}
		
		if(!temp1 && !temp2)
			free(temp3);

		while(temp1 || temp2)
		{
 			if(temp1->link1 && (temp1->link1->year == node1->year) && xstrcmp(temp1->link1->city, node1->city) == 0)
			{
				temp3 = temp1->link1;
				temp1->link1 = temp1->link1->link1;
				temp1 = NULL;
			}
	
			if(temp2->link2 && (xstrcmp(temp2->link2->city, node1->city) == 0) && temp2->link2->year == node1->year)
			{
				temp3 = temp2->link2;
				temp2->link2 = temp2->link2->link2;
				temp2 = NULL;
			}
	
			if(temp1)
				temp1 = temp1->link1;
			if(temp2)
				temp2 = temp2->link2;

		}
	
		if(temp3)
			free(temp3);
		else 
			printf("\n-------The node is not in the list-------\n ");
		break;
	}
	}
	while (choice ==1 || choice==2 || choice ==3 || choice==4);
}
	 	


void y_addnode(struct node ** f_header1, struct node *f_temp)
{
	struct node *prev = NULL, *temp;
			
	if(*f_header1 == NULL)
	{
		(*f_header1) = f_temp;
		(*f_header1)->link1 = NULL;
	}
	else
	{
		temp = *f_header1 ;
     	while(temp != NULL && (temp->year < f_temp->year))
		{
			prev = temp;
			temp = temp->link1;
		} 
		if(prev == NULL)
		{
			f_temp->link1 = temp; 
			(*f_header1) = f_temp;
		}
		else
		{
			prev->link1 = f_temp;
			f_temp->link1 = temp;					
		}
	}
}
  
void c_addnode(struct node ** f_header2, struct node *f_temp)
{
	struct node *prev = NULL, *temp;
			
	if( *f_header2 == NULL )
	{
		(*f_header2) = f_temp;
		(*f_header2)->link2 = NULL;
	}
	else
	{
		temp= *f_header2 ;
     	while(temp != NULL && ((xstrcmp(temp->city, f_temp->city))==-1))
		{
			prev = temp;
			temp = temp->link2;
		} 
		if(prev==NULL)
		{
			f_temp->link2 = temp; 
			(*f_header2) = f_temp;
		}
		else
		{
			prev->link2 = f_temp;
			f_temp->link2 = temp;
					
		}
	}
}
 
		
int xstrcmp(char* s, char* d)
{
	while(1)
	{
		if(!*s && !*d)
			return 0 ;
		if(*s < *d)
			return -1	 ;
		if(*s > *d)
			return 1 ;
		s++ ;
		d++ ;
	}
}
