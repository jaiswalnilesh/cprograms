/*TO DELETE THE VOWELS PRESENT IN THE STRING*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
	unsigned int i,j,k=0,len;
	char *str;
	str=
	char vowels[]={'A','E','I','O','U'};

	printf("ENTER A STRING\n");
	gets(str);
	len=strlen(str);
	for (i=0,k=0; i<=len;i++)
	{
		for(j=0;j<5;j++)
		{
		
			if(!((str[i]==vowels[j] || str[i]==vowels[j]+32)))
			{
					str[k]=str[i];
					k++;
				
			}
		}
			
	}
	
puts(str);

}
	