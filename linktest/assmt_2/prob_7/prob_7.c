/*TO REPLACE CONSC. BLANKSPACES WITH ONE IN THE STRING*/
#include <stdio.h>
#include <string.h>
void main()
{
	unsigned int i,j,k=0,spaceFound=0;
	char str[80];

	printf("ENTER A STRING\n");
	gets(str);

	for (i=0,k=0; i<=strlen(str);i++)
	{
		spaceFound=0;
		
		if(!((str[i]==' ' && str[i+1]==' ')))	//KEEP THE STRING AS IT IS IF no consec. spaces are there.
		{
			str[k]=str[i];
			k++;
		}

	
	}
	
puts(str);

}
	