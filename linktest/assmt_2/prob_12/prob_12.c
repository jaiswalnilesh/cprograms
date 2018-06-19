# include "stdio.h"
// Program to write a function of string comparision

void main()
{
	
	char str1[50],str2[50];
	int xstrcasecmp(char *s1,char *s2);
	int a;

// Get two inputs from the user	
	
	printf("Enter two strings\n");
	gets(str1);
	gets(str2);
	a = xstrcasecmp(str1,str2);
	printf("\n Function Returns %d\n",a);
	if (a>0)
	{
		printf(" %s > %s \n", str1,str2);
	}

	else 
		if (a<0)
		{
		printf(" %s < %s \n", str1,str2);
		}
		else
			printf("%s = %s\n",str1,str2);

	
}

/*
* Function which cmpares two Strings (case immaterial)
* Parameters : *s1 - First String
			   *s2 - Second String
* Returns	 : +1 if *s1>*s2
			   -1 if *s1<*s2
			    0 if the Strings are Equal.

*/
int xstrcasecmp(char *s1,char *s2)
{
	int i=0,d=0;
	
		while(s1[i]!='\0' && s2[i]!='\0')
		{
			if(!((s1[i]==s2[i]) || (s1[i]==s2[i]+32) || (s1[i]+32==s2[i])))
			{
				d=s1[i]-s2[i];
				break;
			}
			i++;
		}
	
	d=s1[i]-s2[i];

	if(d>0)
		d=1;
	else 
		if(d<0)
			d=-1;
	else
		d=0;
	return d;
} 
