/* Program to Write a function to compute the number in diff. ways */
#include "stdio.h"
#include "stdlib.h"

void main()
{
	void recur(int n,int i);
	int i,n;
	//Get a nmber from the user
	printf("Enter a No.");
	scanf("%d",&i);

	do
	{// Get the refernce variable
	printf("\nEnter the reference variable(Less than %d)",i);
	scanf("%d",&n);
	}while(n<0 || n>i);

	recur(n,i);
}
/*
*Function to compute the no. in diff. ways 
 in which an int i can be written as sum of two numbers 
 one of which is less then reference 'n'
*Parameters : Integer i, The number which is to be represented
			: Integer n, The reference variable
*Returns	: Void.
*/ 		
void recur(int n,int i)
{
 if(n>=0)
 {
	// Print the number as sum of two numbers.
	 printf("\n%d + %d = %d\n",n,(i-n),i);
	 recur(--n,i);// call the function again decrementing n by one
	 
 }
else
 return;
}