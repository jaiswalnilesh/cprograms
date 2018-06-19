//PROGRAM TO CONVERT A STRING TO FLOAT

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


void main()
{
	char again='n',floatString[20];
	float *floatNumber=(float *)malloc(sizeof(float));
	char myatof(char *floatString,float *floatNumber);
	do
	{
		printf("Enter The Number: ");
		fflush(stdin);
		gets(floatString);
		
		if(myatof(floatString,floatNumber)=='y')
			printf("\n\tThe Float Number %s is Equivalent To String %f",floatString,*floatNumber);

		else
			printf("\n\tTHE FLOAT NUMBER %s CANNOT BE CONVERTED To STRING ",floatString);;
		

		printf("\n\n\t\tDo You Want To Do It Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);

	}while(again=='y' || again=='Y');

	free(floatNumber);
}

/*
Method to convert a string to float number
@param floatNumber : String that is to be converted to float
@param floatString : Parced float number is stored in this float pointer

@returns char : 'y' if input string is a valid float number
				'n' otherwise
*/

char myatof(char *floatString,float *floatNumber)
{
	int i=1;
	*floatNumber=0;

	//PRE DECIMAL POINT PART
	while((*floatString!='.')&&(*floatString))
	{
		if(!(isdigit(*floatString))) //if not a digit,return error
			return 'n';
		else
			*floatNumber=((*floatNumber)*10)+((*floatString++)-48);
	}
	//if string is ended then return success.(case of int as float)
	if(*floatString=='\0')
		return 'y';
	//POST DECIMAL POINT PART
	else
	{
		while(*(++floatString))
		{
			if(!(isdigit(*floatString)))
				return 'n';
			*floatNumber+=(((*floatString)-48)/
					((float)(i*=10)));
		}
	}
	return 'y';
}
