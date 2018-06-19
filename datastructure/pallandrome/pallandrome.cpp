#include<stdio.h>
#include<malloc.h>
struct node
{
	char c;
	struct node *link;
};
void main()
{
	void push(struct node **, char);
	char pop(struct node **);
	struct node *header, *temp;
	header = NULL;
	char stg[10];
	int i;
	
	
	printf("Enter the string :");
	scanf("%s", &stg);

 	for(i = 0; stg[i] != 'C'; i++)
	{
		push(&header, stg[i]);
	}
	
	i++;

	temp = header;

 	while(stg[i])
	{
		if(stg[i] != pop(&header))
			break;
		i++; 
	}

	if(stg[i] == NULL && header == NULL)
		printf("The string is a pallondrome\n");
	else
		printf("The string is not a pallondrome\n");
}

void push(struct node **f_header, char data)
{
	struct node *temp;

	temp = (struct node *) malloc (sizeof(node));
	temp->c = data;
	temp->link = *f_header;
	*f_header = temp;
}
	


char pop(struct node **f_header)
{

	struct node *temp;
	char var;
	temp = *f_header;
	var = temp->c;
	*f_header = temp->link;
	free(temp);
	return(var);
	
}

		 
			

