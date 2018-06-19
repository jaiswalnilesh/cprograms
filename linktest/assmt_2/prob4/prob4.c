/*TO COUNT THE NUMBER OF OCCURENCES OF ANY TWO VOWELS IN SUCCESSION IN A LINE OF TEXT */
#include <stdio.h>
#include <string.h>
void main()
{
	unsigned int i,j,k,count=0;
	char str[80];
	char vowels[]={'A','E','I','O','U'};

	printf("ENTER A STRING\n");
	gets(str);

	for (i=0; i<=strlen(str)-1;i++)
	{
		for(j=0;j<5;j++)
		{
			if(str[i]==vowels[j] || str[i]==vowels[j]+32)
			{
				for(k=0;k<5;k++)
					if(str[i+1]==vowels[k] || str[i+1]==vowels[k]+32)
					{
						count=count+1;
					}
			}
		}
	}

	printf("Number of occurence of two vowels is %d\n", count);
}
	