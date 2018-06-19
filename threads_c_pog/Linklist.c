#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} LLIST;

LLIST *list_add(LLIST **p, int i) 
{
	if (p == NULL)
		return NULL;
		
	LLIST *n = malloc(sizeof(LLIST));
	if (n == NULL)
		return NULL;
	
	n->next = *p;
	*p = n;
	n->data = i;
	return *p;
}

void list_print(LLIST *n)
{
	if (n == NULL){
		printf("List is empty\n");
	} 
	while (n != NULL)
	{
		printf("print %p %p %d\n", n, n->next, n->data);
		n = n->next;
	}
}

LLIST **list_search(LLIST **n, int i)
{
	if (*n == NULL)
		return NULL;
	
	while (*n != NULL)
	{
		if ((*n)->data == i)
		{
			return n;
		}
		n = &(*n)->next;
	}
	return NULL;
	
}

void list_remove(LLIST **p)
{
	if (p != NULL && *p !=NULL) 
	{
		LLIST *n = *p;
		*p = (*p)->next;
		free(n);
	}
	
}

int main (void)
{
	LLIST *n = NULL;
	list_add(&n, 1);
	list_add(&n, 2);
	list_add(&n, 3);
	list_add(&n, 4);
	list_add(&n, 5);
	
	list_print(n);
	
	return 0;
}