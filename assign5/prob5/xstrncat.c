//PROGRAM TO CONCAT A STRING TO ANOTHER STRING UPTO A COUNT

#include<stdio.h>
#include<string.h>
void main()
{
	char again='n',target[20],source[20];
	int count;
	void xstrncat(char *s,char *t,int count);
	do
	{
		printf("Enter Source String : ");
		fflush(stdin);
		gets(source);
		printf("Enter Target String : ");
		fflush(stdin);
		gets(target);
		printf("Enter Number Of Characters That Are To Be Concatinated : ");
		fflush(stdin);
		scanf("%d",&count);
		xstrncat(target,source,count);
		printf("\n\nThe Concatinated String Is %s",target);
		printf("\n\n\t\tDo You Want To Do It Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
METHOD TO CONCAT A STRING TO ANOTHER STRING UPTO A COUNT
@param s : The Target String that is the string on which the 
	concatination is done
@param t : The string which is concatinated that is the string whose 
	characters are copied at the end of first string
@param count : the number of characters to be copied.If count is 
	more than the string length of t,then whole string is copied
*/
void xstrncat(char *s,char *t,int count)
{
	if(count>=0)
	{
		while(*s++);
		s--;
		while((*s++=*t++) && --count>0);			;
		*s='\0';
	}
}