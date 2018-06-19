/* Program to Convert an Int to a Base 'b' Char Representation */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void main()
{
	void InttoBase(int number,int base,char* result);
	int number,base;
	char* result;
	result=(char*)malloc(10);
	
	//Get Number From The User
	do
	{
		fflush(stdin);
		printf("Enter a number (Maxm 999999) :  ");
		scanf("%d",&number);
	
	}while(number<0 || number>999999);

	//Get Base From The User
	do
	{
		fflush(stdin);
		printf("Enter a base (Maxm 16) :  ");
		scanf("%d",&base);
	
	}while(1>base || base>17);

	InttoBase(number,base,result);//Give call to the funtion for conversion
	puts(result);
} 

/*
*Function to convert a given number in the charecter representation of Base specified
*Parameters : Number to be converted
			  Reference Base
			  String in whish result is to be stored
*Returns	: Void	
*/
void InttoBase(int number,int base,char* result)
{
	char* refer="0123456789ABCDEF";// Declare a reference Array
	int c=0;
	while(number>0)
	  {	
		*result=*(refer+(number%base));//Deivide the number by base and collect the remainder
									   //By refering that Remainder as index to reference Array we'll get the required Char.

		number=number/base;// Reduce the number for further calculations
		result++;
		c++;
	  }
	*result='\0';
	result=result-c;// Place result to its starting position
	result=strrev(result);.// Reverse it since the required String is reverse of the evaluated String.
}
