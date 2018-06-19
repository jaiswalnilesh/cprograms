#include<stdio.h>
#include<malloc.h>
struct array
{
	int elemts;
	struct array *link;
};
void main(void)
{
	struct array* header, *temp, *prev;
	header = (struct array*) malloc(sizeof(array));
	header->link = NULL;
	temp = header;
	
	int i, n = 10, num = 3, inc, j, k, span, y;

	printf("\n Enter the elements of array :\n");

	for(i = 0; i < 10; i++)
	{
		scanf("%d", &(temp->elemts));
		temp->link = (struct array*) malloc(sizeof(array));
		temp = temp->link;
		temp->link = NULL; 
	}
	
	/*printf("\nEnter the increments :\n");
	
	for(i = 0; i < 3; i++)
		scanf("%d", &incr[i]);


	for(inc = 0; inc < num; inc++)
	{
		span = incr[inc];
		for(j = span; j < n; j++)
		{
			y = array[j];
			
			for(k = j-span; k >= 0 && y < array[k]; k -= span)
 				array[k + span] = array[k];

			array[k + span] = y;
		}
	}*/

	temp = header;

	printf("\nThe list is : \n");

	while(temp->link)
	{
		printf("%3d", temp->elemts);
		temp = temp->link;
	}
	printf("\n");
}

	