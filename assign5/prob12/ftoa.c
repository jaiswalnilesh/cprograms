#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char again='n';
	float no;
	char *noStr=(char *)malloc(20*sizeof(char));
	char floatToStr(float n,char *str);	
	do
	{
		printf("Enter The Float Number To Be converted to String : ");
		while(scanf("%f",&no)==0)
		{
			printf("Enter The VALID Float Number To Be converted to String : ");
			fflush(stdin);
		}
		if(floatToStr(no,noStr)=='y')
			printf("The %f in string format is %s ",no,noStr);
		else
			printf("The %f can NOT be stated as STRING",no);		
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
	free(noStr);
}


/*
converts the given float to string
@param n :  float to be converted to string
@param str : string pointer in which the parsed number is to be stored;
@return char : return 'y' if function successful in parsing
			   return 'n' if function in NOT successful in parsing
*/
char floatToStr(float n,char *str)
{
	char ok='y',*p=(char *)malloc(sizeof(char)*6);
	int i,aNum;
	*str='\0';
	aNum=(int)n;
	if(aNum==0)		//case of 0.123
		strcpy(str,"0.");
	else
	{
		i=0;
		p[i++]='.';
		while(aNum>0)
		{
			p[i++]=(aNum%10)+48;
			aNum=aNum/10;
		}
		p[i]='\0'; ////for no 123, p contains 321
		strcpy(str,strrev(p));
	}
	
	//process after decimal point part
	aNum=(int)((n-(int)n)*10000);
	if(aNum==0) // case of 12.0 or 12
	{
		*(str+strlen(str)+1)='\0';
		*(str+strlen(str))='0';
	}
	else
	{
		i=0;
		while(aNum>0)
		{
			p[i++]=(aNum%10)+48;
			aNum=aNum/10;
		}
		p[i]='\0';	//for no 123, p contains 321
		strcat(str,strrev(p));
	}
	//REMOVE TRAILING ZEROS
	for(i=strlen(str)-1;i>0;i--)
		if(str[i]!='0')
		{
			str[i+1]='\0';
			break;
		}
	return ok;
}
