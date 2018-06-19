//program to find the substring in a given string


#include<stdio.h>
#include<string.h>

void main()
{
	char again='n',str1[20],str2[20];
	int result;
	int xstrstr(char *str1,char *str2);
	do
	{
		printf("Enter The Source String : ");
		fflush(stdin);
		gets(str1);
		printf("Enter The Target String That Is To Be Checked As The Substring Of The Source String: ");
		fflush(stdin);
		gets(str2);

		if((result=xstrstr(str1,str2))!=-1)
			printf("\n\n%s Starts in %s From %d",str2,str1,result);
		else
			printf("\n\n%s Does Not Contain %s.Sorry!!",str1,str2);
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
}


/*
Method that finds the substring
@param str1 : source string
@param str2 : target string

@return int : returns the start location of target string in source string 
			  else returns -1;

*/
int xstrstr(char *str1,char *str2)
{
	int len1=strlen(str1),len2=strlen(str2),i,j;
	char flag;
	if(len2>len1)
		printf("Str2 %s Not Found In Str1 %s",str2,str1);
	else
	{
		for(i=0;i<len1;i++)
		{
			flag='y';
			for(j=0;j<len2;j++)
			{
				if(str1[i+j]!=str2[j]) //if any character don't 
									   //match further,break that loop
				{
					flag='n';
					break;
				}
			}
			if(flag=='y') //if flag value doesn't become 'n' in above for 
					//loop means all characters match,hence return i
				return i;
		}
	}
	return -1; //no substring is there
}