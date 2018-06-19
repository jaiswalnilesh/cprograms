// PROGRAM TO COMPARE 2 STRINGS (CASE INSENSETIVE)
#include<stdio.h>
#include<ctype.h>
void main()
{
	int xStrCaseCmp(char *s1,char *s2);
	char s1[50],s2[50],again='n';
	do
	{
		printf("Enter First Array : ");
		fflush(stdin);
		gets(s1);
		printf("\nEnter Second Array : ");
		fflush(stdin);
		gets(s2);
		switch(xStrCaseCmp(s1,s2))
		{
			case 1:
				printf("String %s Is GREATER THAN %s",s1,s2);
				break;
			case -1:
				printf("String %s Is LESS THAN %s",s1,s2);
				break;
			case 0:
				printf("String %s Is EQUAL TO %s",s1,s2);
				break;
			default:
				printf("Hahaha");
		}
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}
/*
METHOD TO COMPARE 2 STRINGS(CASE INSENSETIVE)
@param s1 : first string to be compared
@param s2 : second string to be compared
@returns :   0 if strings are equal(case insensetive)
			-1 if s1 is less than s2
			 1 if s1 is greater than s2
*/
int xStrCaseCmp(char *s1,char *s2)
{
	int getAbs(int i);
	while(*s1 && *s2)
	{
		if((isalpha(*s1)!=0)&&(isalpha(*s2)!=0)) //if alphabet?
		{
			if(!(((getAbs(*s1-*s2))==32)|| ((*s1-*s2)==0))) //if are alphabets,
												//are they different?
			{
				if(toupper(*s1)>toupper(*s2))
					return 1;
				else if(toupper(*s1)<toupper(*s2))
					return -1;
				else return 0;
			}
		}
		else
			if(*s1-*s2!=0) //if not an alphabet,are they different?
				break;
		s1++;
		s2++;
	}
	if((*s1-*s2)>0)
		return 1;
	else if((*s1-*s2)<0)
		return 1;
	else return 0;
}

int getAbs(int i)
{
	return((i<0)?-i:i);
}
/*int xStrCaseCmp(char *s1,char *s2)
{
	while(*s1 && *s2)
	{
		if((((isalpha(*s1)!=0)&&(isalpha(*s2)!=0))&&(!(((*s1-*s2)==32) || 
			((*s1-*s2)==-32)|| ((*s1-*s2)==0))))||(!(((isalpha(*s1)!=0)&&
			(isalpha(*s2)!=0)))&&(*s1-*s2!=0)))
				break;
		s1++;
		s2++;
	}
	if(*s1>*s2)
		return 1;
	else if(*s1<*s2)
		return -1;
	else return 0;
}*/