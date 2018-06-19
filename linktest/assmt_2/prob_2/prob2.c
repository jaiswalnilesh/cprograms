/*DELETE THE OCCURENCE OF WORD "THE"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	unsigned int len,i,j=0;
	char *str;
	str=(char*)malloc(1000);
	str[0]=' ';
	printf("ENTER A STRING\n");
	gets(str+1);
	len=strlen(str);
	realloc(str,len*sizeof(char)+1);

	
	for (i=0,j=0; i<=len;j++)
	{// CHECK FOR THE OCCURENCE OF "THE" / "the"
		
		if((str[i]==' ')&&(str[i+1]=='t' ||str[i+1]=='T')&&(str[i+2]=='h' ||str[i+2]=='H')&&(str[i+3]=='e' ||str[i+3]=='E')&&((str[i+4]==' ')||(str[i+4]=='\0')))
		{
			
			i+=4;// IF THE IS FOUND INCREMENT THE POINER TO END OF THE 
					
		}
		else
		{
			i++;		
		}
	
		str[j]=str[i];//COPY THE VALUE @str[i] to str[j] 
				
	}
	puts(str);
	printf("\n");
	free(str);
	
	
}
	