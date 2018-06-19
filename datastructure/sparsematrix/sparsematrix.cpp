#include<stdio.h>
#include<malloc.h>
struct sparse
{
	int row, col, data;
	struct sparse *rlink, *clink;	
};

void main()
{
	struct sparse *header, *temp;
	header = (struct sparse*) malloc (sizeof(sparse)); 
	static int arr[5][5], i, j, count = 0;
	void addnode(struct sparse **, struct sparse *);

	header->rlink = NULL;
	header->clink = NULL;
	printf("Enter the number of rows :");
	scanf("%d", &(header->row));
	
	printf("\nEnter the number of cols :");
	scanf("%d", &(header->col));

	printf("\nEnter the values :");

	for(i=0; i < header->row; i++)
	{
		for(j=0; j < header->col; j++)
			scanf("%d", &arr[i][j]);
	}

	for(i=0; i < header->row; i++)
	{
		for(j=0; j < header->col; j++)
		{
			if(arr[i][j] != 0)
			{
				temp = (struct sparse *) malloc (sizeof(sparse));
				count++;
				temp->row = i;
				temp->col = j;
				temp->data = arr[i][j];
				addnode(&header, temp);
			}
		}
	}
			
	header->data = count;	
	temp = header;
		
	
	
		printf("\n Row-wise sorted list is : \n ");
	
		while(temp)
		{
			printf(" \n %d %d %d", temp->row, temp->col, temp->data);
			temp = temp->rlink;
		}
		
		temp = header;
		
		printf("\n Column-wise sorted list is : ");
	
		while(temp)
		{
			printf(" \n %d %d %d", temp->row, temp->col, temp->data);
			temp = temp->clink;
		}
				
}
	 	



void addnode(struct sparse ** f_header, struct sparse *f_temp)
{
	struct sparse *prev = NULL, *temp;
			
	if((*f_header)->rlink == NULL)
	{
		(*f_header)->rlink = f_temp;
		(*f_header)->rlink->rlink = NULL;
	}
	else
	{
		temp = (*f_header)->rlink ;
     	while(temp != NULL && (((temp->row < f_temp->row) || ((temp->row == f_temp->row ) && (temp->col < f_temp->col)))))
		{
			prev = temp;
			temp = temp->rlink;
		} 
		if(prev == NULL)
		{
			f_temp->rlink = temp; 
			(*f_header)->rlink = f_temp;
		}
		else
		{
			prev->rlink = f_temp;
			f_temp->rlink = temp;					
		}
	}
  
	if((*f_header)->clink == NULL)
	{
		(*f_header)->clink = f_temp;
		(*f_header)->clink->clink = NULL;
	}
	else
	{
		temp = (*f_header)->clink ;
     	while(temp != NULL && ((temp->col < f_temp->col) || ((temp->col == f_temp->col) && (temp->row < f_temp->row))))
		{
			prev = temp;
			temp = temp->clink;
		} 
		if(prev == NULL)
		{
			f_temp->clink = temp; 
			(*f_header)->clink = f_temp;
		}
		else
		{
			prev->clink = f_temp;
			f_temp->clink = temp;					
		}
	}
} 
		
