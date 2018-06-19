//program to compare given number of characters from source string 

#include<stdio.h>
#include<string.h>


void main()
{
	char again='n',target[20],source[20];
	int count;
	int xstrncmp(char *s,char *t,int count);


	do
	{
		printf("Enter Source String : ");
		fflush(stdin);
		gets(source);
		printf("Enter Target String : ");
		fflush(stdin);
		gets(target);
		printf("Enter Number Of Characters That Are To Be Conpared : ");
		fflush(stdin);
		scanf("%d",&count);
		switch(xstrncmp(source,target,count))
		{
		case 0:
			printf("\n\nString %s IS EQUAL TO String %s",source,target);
			break;
		case 1:
			printf("\n\nString %s IS GREATER THAN String %s",source,target);
			break;
		case -1:
			printf("\n\nString %s IS LESS THAN String %s",source,target);
			break;
		}
		printf("\n\n\t\tDo You Want To Do It Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}

/*
method to compare given number of characters from source string 
to target string.
@param s : target string
@param t : source string
@param count : number of characters to be copied
*/

int xstrncmp(char *s,char *t,int count)
{
	if(count>=0)
		while(*t!='\0' && count-->0)
		{
			if(*s!=*t)
				return (((*s-*t)>0)?1:-1);
			s++;
			t++;
		}
	return 0;
}