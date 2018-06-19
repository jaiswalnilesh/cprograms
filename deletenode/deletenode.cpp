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
	void addnode(struct node **, struct node *);
	void addnode1(struct node **, struct node *);
	int i = 0;
	
	
	header1 = NULL;
	header2 = header1 ;
		
	do 
	{
		temp = (struct node *) malloc (sizeof(node));
		printf("Enter the year and the city : ");
		scanf("%d", &(temp->year));
		scanf("%s", &(temp->city));
		addnode1(&header1, temp);
		addnode(&header2, temp);
		i++;
	}
	while(i<5);

	temp1 = header1;
	temp2 = header2;
	
	printf("\n Year-wise sorted list is : \n ");
	
	while(temp1)
	{
		printf(" \n %d %s", temp1->year, temp1->city);
		temp1 = temp1->link1;
	}
	
	printf("\n City-wise sorted list is : ");
	
	while(temp2)
	{
		printf(" \n %d %s", temp2->year, temp2->city);
		temp2 = temp2->link2;
	}
	

	struct node *node1 = (struct node *)malloc(sizeof(node));	
	printf("\n Enter the year of the node to be deleted:");
	fflush(stdin);
	scanf("%d", &(node1->year));
	fflush(stdin);
	printf("\n Enter the city of the node to be deleted :");
	scanf("%s", &(node1->city));

	node1->link1 = NULL;
	node1->link2 = NULL;
	
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
		if(temp1 && (temp1->link1->year == node1->year) && xstrcmp(temp1->link1->city, node1->city) == 0)
		{
			temp3 = temp1->link1;
			temp1->link1 = temp1->link1->link1;
			temp1 = NULL;
		}

		if(temp2 && (xstrcmp(temp2->link2->city, node1->city) == 0) && temp2->link2->year == node1->year)
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
	
	if(!temp1 && !temp2)
		free(temp3);

	temp1 = header1;
	temp2 = header2;

	while(temp1)
	{
		printf(" \n %d %s", temp1->year, temp1->city);
		temp1 = temp1->link1;
	}
	
	printf("\n City-wise sorted list is : \n\n ");
	while(temp2)
	{
		printf(" \n %d %s", temp2->year, temp2->city);
		temp2 = temp2->link2;
	}
}

 

void addnode1(struct node ** f_header1, struct node *f_temp)
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
  
void addnode(struct node ** f_header2, struct node *f_temp)
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
