/* Program to create an link list and do many possible operations on it */
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"

char forwardNode(struct Node **first,struct Node **last,char* str,int factor);
void deleteList(struct Node **first);
void addNode(struct Node**,struct Node **last,char* str);
char delNode(struct Node**,struct Node**,char* str);
void delete2nd(struct Node **first, struct Node** last);
char interchange(struct Node **first,struct Node **last,char* str1,char* str2);
void RevList(struct Node **First);
void revList(struct Node**,struct Node**);

int count=1;

struct Node
{
	char* name;
	struct Node *Next;
	struct Node *Prev;
};

void main()
{
	int i=0,operation;
	char done,*str,*str1,*str2;
	struct Node *first=NULL,*temp=NULL,*last=NULL;

	do
	{
		fflush(stdin);
        printf("\nEnter 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 for following operations !!\n 1) Display List \n 2) Add element to the list\n 3) Delete element from the list \n 4) Forward node \n 5) Interchange Nodes \n 6) Delete Every Second Element \n 7) Reverse List \n any other key to exit\n");
 		if(scanf("%d",&operation)==0)
		{
			exit(0);
		}


		switch (operation)
		{
			case 1:
				{
					printf("\n\t");
					temp=first;
					if(temp==NULL)
						printf("No Elements in the List\n");
					else while(temp!= NULL)
					{
						printf("  %s",temp->name);
						temp=temp->Next;
					}
					
					printf("\nList from last to first:\n");
					printf("\n\t");
					temp=last;
					if(temp==NULL)
						printf("No Elements in the List\n");
					else while(temp!= NULL)
					{
						printf("  %s",temp->name);
						temp=temp->Prev;
					}
					printf("\n");
					break;
				}
			case 2:
				{
					fflush(stdin);
					printf("Enter NAME to be added  :");
					str=malloc(100);
					scanf("%s",str);
					addNode(&first,&last,str);
					printf("\t\tAdded!!\n\n");
					break;
				}

			case 3:
				{
					//str1=(char*)malloc(12);
					printf("\n\nIf u wanna delete some node enter the element of that node:");
					count=1;
					do
					{	if(count==0)
							printf("Enter a valid String:");
						fflush(stdin);
						count=scanf("%s",str);
					}while(count==0);
					 
					done=delNode(&first,&last,str);
					if(done=='y')
						printf("\t\tdeleted!\n");
					else
						printf("\t\tName is not present in the list\n");
					
					break;
				}
				
			case 4:
				{
					str=(char*)malloc(12);
					printf("Enter Node Name:\n");
					scanf("%s",str);
					printf("Enter Factor");
					while(scanf("%d",&count)==0 || count<0 )
					{
						printf("\nEnter valid no.\n");
					}
					done=forwardNode(&first,&last,str,count);
					if(done=='y')
					{
						printf("done");
					}
					else
					{
						printf("Failed\n");
					}
					break;
				}

			case 5:
				{
					str1=(char*)malloc(12);
					str2=(char*)malloc(12);
					printf("Enter Node Name:\n");
					scanf("%s",str1);
					printf("Enter another Node Name:\n");
					scanf("%s",str2);
					done=interchange(&first,&last,str1,str2);
					if(done=='y')
					{
						printf("done\n");
					}
					else
					{
						printf("Failed\n");
					}
					break;
										
				}
			case 6:
				{
					delete2nd(&first,&last);
					break;
				}
			case 7:
				{
					revList(&first,&last);
					break;
				
				}
			default:
				exit(1);
		}
	fflush(stdin);
	printf("Press any key..............");
 	_getch();
	}while(operation>0);
	deleteList(&first);
}


/*
* Function addNode to add a Node to the given List at appropriate position.
*	Parameters: Accepts the header of the list in which node is to be added.
*			  : Accepts the String which is to be added in the node.
*	Returns	  : Void.
*/

void addNode(struct Node** first,struct Node **last,char* str)
{
	struct Node *temp;
	struct Node *temp1,*prev;
	
	temp=*first;
	// Create a NODE
	temp1=(struct Node*)malloc(sizeof(struct Node));//allocate Memory to the Node
	temp1->Next=NULL;
	temp1->Prev=NULL;
	temp1->name=(char*)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp1->name,str);//Copy the perticular String in the Node.

	if(*first==NULL)
	{	
		*first=temp1;// If no first Node make our Node as first node
		*last=temp1;
	}

	else
	{
		if(strcmp(temp->name,str)==0 || strcmp(temp->name,str)>0)
		{//if the Node has to fit at the very first position change the appropriate pointers to do so.
			temp1->Next=*first;
			(*first)->Prev=temp1;
			*first=temp1;
		}
		else
		{
			//Else find the appropriate position of the Node Compairing its String(Element) with already present List Elements.
			while(temp!=NULL && (strcmp(temp->name,str))<0 )
			{
				prev=temp;
				temp=temp->Next;
			}
			//Fit the node at the found Position
		   	prev->Next=temp1;
			temp1->Prev=prev;
			temp1->Next=temp;
			if(temp!=NULL)
				temp->Prev=temp1;
			if(temp==NULL)
				*last=temp1;
		}
	}
}

/*
*Function to find and delete a node from the given List
*	Parameters : Struct Pointer indicating the List Header
			   : Name of the Node which has to be deleted from the List.
*	Returns	   : Char indicating successfull deletion.
*/
char delNode(struct Node** first,struct Node** last,char* str)
{
	struct Node *temp=*first,*prev;
	if(temp==NULL)//If no Elements in the List return that Deletion is not possible.
		return 'n';
	if(strcmp(temp->name,str)==0)
	{//If the Node is at the Start position delete the node and change the Header of the List.
		*first=temp->Next;
		(*first)->Prev=NULL;
		free(temp);	
		return 'y';

	}
	else
	{//Else traverse till the required Node
		while(strcmp(temp->name,str)!=0)
		{
			prev=temp;
			temp=temp->Next;
			if(temp==NULL)
			{//If node not found return 'n';
				return 'n';		
			}
		}
		// if the Node is found delete Node and change the appropriate Pointers.
		prev->Next=temp->Next;
		free(temp);
		temp=prev->Next;
		if(temp!=NULL)
			temp->Prev=prev;
		if(temp==NULL)
			*last=prev;
		return 'y';
	}

}
/*
* Function to Delete every Second Element of the List
*	Parameters: Accepts Header of the List on which the Operation is to be Performed.
*	Returns   : Void.
*/
void delete2nd(struct Node **first,struct Node** last)
{
	struct Node *temp=*first,*prev;
	char count=1;//Declare a Count

	while(temp !=NULL)
	{
		if(count%2==0)
		{//IF the Node is Even delete it and change the appropriate Pointers.
			if(temp->Next==NULL)
				*last=prev;
			prev->Next=temp->Next;
			if(temp->Next!=NULL)
				 temp->Next->Prev=prev;
			free(temp);
			temp=prev;
			count=0;
		}
		prev=temp;
		temp=prev->Next;
		count++;
		
	}

}

/*
* Function to Free all the Memory allocated to the List
*	Parameters : Header of the List whose Nodes are to be deleted.
*	Returns    : Void.
*/
void deleteList(struct Node **first)
{
	struct Node *temp;
	while(*first!=NULL)
	{//Traverse till the end of the list deleting the Nodes
		temp=(*first)->Next;
		free(*first);
		*first=temp;
	}
}
/*
* Function to forward a node by the given Factor
*	Parameters: Accepts Header of the List on which tje operation has to be performed.
*			  : Accepts the Node name which has to be Forwarded\
*			  : Accepts the factor by which the Node is to be forewarded.
*	Returns	  : Char indicating whether the node has been forwarded successfully or Not.
*/
char forwardNode(struct Node **first,struct Node **last,char* str,int factor)
{
	struct Node *temp=*first,*prev,*prev1,*temp1=temp;
	if(temp==NULL)//if No elements in the list return unsuccessful
		return 'n';
	if(strcmp(temp->name,str)!=0)
	{//Traverse the list to find the required Node
		while(temp!=NULL && strcmp(temp->name,str)!=0)
		{
			prev=temp;
			temp=temp->Next;
			if(temp==NULL)
			{//If node is not found till the end of the List return unsuccessful
				return 'n';		
			}
		}

		//prev->Next=temp->Next;//Prev will contain the prev Node pointer of the required Node.
		temp1=temp;// temp and temp1 will contain the Node pointer 
	}
		
		for(;factor>=0;factor--)
		{//if Node is found traverse the resat of the list till the given factor.
			if(temp1==NULL)
				return 'n';

			prev1=temp1;
			temp1=temp1->Next;
		}
		//if(factor!=0 && temp1==NULL)//and if factor is greater then the remaining Nodes in the list return unsuccessful.
		//	return 'n';
		
		{//insert the node at the found position.
					
			if(strcmp((*first)->name,str)==0)
			{//if it is the first element make neccesory changes for the header of the list
			*first=temp->Next;
			(*first)->Prev=NULL;
			//The required Node will be in temp.
			}
			else
			{
				prev->Next=temp->Next;//Prev will contain the prev Node pointer of the required Node.
				temp->Next->Prev=prev;
				//temp1=temp;// temp and temp1 will contain the Node pointer 
			}

			prev1->Next=temp;
			temp->Prev=prev1;
			temp->Next=temp1;
			if(temp1!=NULL)
				temp1->Prev=temp;
			else
				*last=temp;

			return 'y';
		}
}
/* Function to interchange two elements of a given List.
*	Parameters: Accepts Struct Pointer indicating Header of the List on which OPeration has to be Performed.
*			  : Node1 Name which has to be interchanged with Node2 
*			  :	Node2 Name which has to be interchanged with Node1
*	Returns	  : Char indicating successful interchange.
*/
char interchange(struct Node **first,struct Node** last,char* str1,char* str2)
{//Find the first Node whose previous node pointer will be in " prev " and self pointer in "temp"
	struct Node *temp=*first,*prev,*temp1=*first,*prev1,*temp3;

	if(temp==NULL)
		return 'n';
	if(strcmp(temp->name,str1)==0)
	{//if it is the first node Make prev=NULL
		temp=*first;
		prev=NULL;
	}
	else
	{//Else find the Node in the List
		while(temp!=NULL && strcmp(temp->name,str1)!=0)
		{
			//prev=temp;
			temp=temp->Next;
			if(temp==NULL)
			{
				return 'n';		
			}
		}
		
	}

//Find the Second Node whose previous node pointer will be in " prev1 " and self pointer in "temp1"	
	if(strcmp(temp1->name,str2)==0)
	{//If it is the first Node which we are searching for.. make prev1=NULL
		temp1=*first;
		prev1=NULL;
	}
	else
	{//Else Find the Node in the List
		while(temp1!=NULL && strcmp(temp1->name,str2)!=0)
		{
			//prev1=temp1;
			temp1=temp1->Next;
			if(temp1==NULL)
			{
				return 'n';		
			}
		}

	}

	prev1=temp1->Prev;
	prev=temp->Prev;
	
	if(prev1==prev)
	{//IF both Nodes are pointing to same Node return unsuccessful.
		printf("\n\nOOPs!! you have given the same node names to interchange\n\n ");
		return 'n';
	
	}

	if(temp1==*last || temp==*last)
	{
		if(temp1==*last)
			*last=temp;
		else
			*last=temp1;
	}

		temp3=temp->Next;
		if(prev1==temp)
		{
			temp->Next=temp1->Next;
			temp->Prev=temp1;
			temp1->Prev=prev;

			if(temp1->Next!=NULL)
				temp1->Next->Prev=temp;
			temp1->Next=temp;
			temp1->Prev=prev;
			if(prev!=NULL)
				prev->Next=temp1;
		}
		else if(prev==temp1)
		{
			temp1->Next=temp->Next;
			temp1->Prev=temp;
			temp->Prev=prev1;

			if(temp->Next!=NULL)
				temp->Next->Prev=temp1;
			temp->Next=temp1;
			temp->Prev=prev1;
			if(prev1!=NULL)
				prev1->Next=temp;
		}

		else
		{
			if(temp1->Next!=NULL)
				temp1->Next->Prev=temp;
			if(temp->Next!=NULL)
				temp->Next->Prev=temp1;	

		prev1->Next=temp;//make prev of second node pointing to first Node.
		temp->Prev=temp1->Prev;
		prev->Next=temp1;//make prev of first node pointing to second node.
		temp1->Prev=prev;
		temp3=temp->Next;//Store Next of first Node
		temp->Next=temp1->Next;//make next of second node as next of first node
		temp1->Next=temp3;//store next of first node into next of second node.
		}
	

	/*
	if(prev1!=NULL && prev!=NULL)
	{//if none of the nodes is pointing to first Node interchange them 
		if(temp1->Next!=NULL)
			temp1->Next->Prev=temp;
		if(temp->Next!=NULL)
			temp->Next->Prev=temp1;
		
		prev=temp->Prev;
		prev1->Next=temp;//make prev of second node pointing to first Node.
		temp->Prev=temp1->Prev;
		prev->Next=temp1;//make prev of first node pointing to second node.
		temp1->Prev=prev;
		temp3=temp->Next;//Store Next of first Node
		temp->Next=temp1->Next;//make next of second node as next of first node
		temp1->Next=temp3;//store next of first node into next of second node.
		return 'y';
		//and u'll see the nodes have been interchanged.
	}
	else 
	{//if one of the nodes is pointing to the Head Node. 
		if(prev==NULL)
		{//if first Node is pointing to Head Node. 
		
			temp1->Next->Prev=temp;
			temp->Next->Prev=temp1;
			prev1->Next=temp;//make prev of second node pointing to first node.
			temp->Prev=prev1;
			temp3=temp->Next;//store next of head node in temp3.
			temp->Next=temp1->Next;
			temp1->Next=temp3;//store next of head node into next of second node 
			temp1->Prev=NULL;
			*first=temp1;//Make Second node as the header
			return 'y';
		}
		else if(prev1==NULL)
		{//if second node is pointing to the Head Node....do the same as above but this time for second node.
			temp1->Next->Prev=temp;
			temp->Next->Prev=temp1;
			prev->Next=temp1;
			temp3=temp1->Next;
			temp1->Next=temp->Next;
			temp->Next=temp3;
			*first=temp;
			temp->Prev=prev1;
			temp1->Prev=prev;
			return 'y';
		}
	}
	*/

	return 'n';
}
/*
*Function to reverse the given List
*	Parameters : Accepts the Header of the list which has to be reversed
*	Returns	   : Void.
*/
void RevList(struct Node **First)
{
	struct Node *temp=*First,*tNext;
	if(*First!=NULL)//Do if there are Elements in the List
	{
		tNext=(*First)->Next;

		while(temp->Next != NULL)
		{//put every Node forward one by one to get the reverse List.  
			temp->Next = tNext->Next;
			tNext->Next = *First;
			*First= tNext;	
			tNext = temp->Next;
		}
	}
}

void revList(struct Node** first,struct Node** last)
{
	struct Node *temp,*last1;
	*last=*first;
	last1=NULL;
	while(*first!=NULL)
	{
		temp=last1;
		last1=*first;
		*first=(*first)->Next;
		last1->Next=temp;
		last1->Prev=*first;
	}

	*first=last1;
}