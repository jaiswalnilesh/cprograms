//PROGRAM TO PRINT THOSE NUMBERS WHICH CAN BE STATED AS THE SUM OF 
//2 NUMBERS OF WHICH ONE NUMBER SHOULD ALWAYS BE LESS THAN A 
//SPECIFIED NUMBER

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main()
{
	char again='n';
	int *intString;
	int no,n,i;	
	void getNumbers(int no,int n,int *intString);


	do
	{
		printf("Enter The Number That Is To Be specified As The Sum Of Two Numbers : ");
		fflush(stdin);
		while(scanf("%d",&no)==0) // will give input as integer
		{
			printf("Enter The VALID Number: ");
			fflush(stdin);
		}
		printf("Enter The Value Of n (That Is That Number Than which At Least One Numbers Should Be Less) : ");
		fflush(stdin);
		while(scanf("%d",&n)==0)
		{
			printf("Enter The VALID Value Of n: ");
			fflush(stdin);
		}
		intString=(int *)malloc(n*2*sizeof(char));
		getNumbers(no,n,intString);


		for(i=0;i<2*n;i+=2)
		{
			printf("\n\t%d = %d + %d ",no,intString[i],intString[i+1]);
		}
		
		printf("\n\n\t\tDo You Want To Do It Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}



/*
Recursive Method to Get All Those Couples Whose Sum Is equal To 
The Specified Number
@param no : Number That Is Input From The User
@param n : The Number By Which At Least One Number Off The Couple Must Be Less
@param intString : Integer Pointer In Which The Result Is To Be Stored
*/
void getNumbers(int no,int n,int *intString)
{
	static int i=0; // to keep track of the array index.
	if(n>0)
		getNumbers(no,--n,intString); //decrement the n
	else
		return; //in terminating case ... do nothing
	intString[i++]=n;
	intString[i++]=(no-n);
}