//program to copy given number of characters from source string 
//to target string

#include<stdio.h>
#include<string.h>

void main()
{
	char again='n',str1[20],str2[20];
	int count;
	void xstrncpy(char *s,char *t,int count);

	do
	{
		printf("Enter Source String : ");
		fflush(stdin);
		gets(str2);

		printf("Enter Target String : ");
		fflush(stdin);
		gets(str1);

		printf("Enter Number Of Characters That Are To Be Copied : ");
		fflush(stdin);
		scanf("%d",&count);

		xstrncpy(str1,str2,count);

		printf("\n\nThe Copied String Is %s",str1);

		printf("\n\n\t\tDo You Want To Do It Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
method to copy given number of characters from source string 
to target string.
@param s : target string
@param t : source string
@param count : number of characters to be copied
*/
void xstrncpy(char *s,char *t,int count)
{
	if(count>=0)
	{
		while(*t!='/0' && count>0)
		{
			*s++=*t++;
			count--;
		}
		*s='\0';
	}
}