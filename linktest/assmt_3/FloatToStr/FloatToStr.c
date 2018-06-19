/* Program to convert the given Float to its String representation */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int IntToStr(char* str,int* no);
void main()
{
	int c,test;
	float no;
	char* str;
    int FloatToStr(char* str,float* no);
	
	str=(char*)malloc(15*sizeof(char));
	
	do
	{
	fflush(stdin);
	printf("Enter any Float:(max five digits) ");
	scanf("%f",&no);
	}while(no<0 || no>99999);

	c=FloatToStr(str,&no);

	printf("The no.is %s \n",str+c);

}


int FloatToStr(char* str,float* no)
{
	char ptr[]="0000";
	int c,d,temp=(int)*no;
	c=IntToStr(str,&temp);
	str=str+strlen(str);
	*no=*no-temp;
	*no=*no*10000;
	temp=(int)*no;
	if(temp==0)
	{
		*(str)='\0';
		return c;
		
	}
	
	else
	{
	*(str)='.';
	str++;
	*(str)='\0';

	d=IntToStr(ptr,&temp);
	strcat(str,(ptr+d));
	return c;
	}
	
}

int IntToStr(char* str,int* no)
{
	 int j=0,temp=*no,c=0;
	 int i=10000;	

	 if(temp==0)
	 {
		 *str='0';
		 *(str+1)='\0';
		 return 0;
	 }
	 else
	 {
		 while (temp !=0)
		 {
			j=temp/i;// Get the respective position digit 
			 *str++=j+48;//convert it to String 
			 temp=temp%i;
			 i=i/10;		
			 c++;
		 }
	 
		*str='\0';
		str=str-c;// Bring the pointer to its Start Position
		c=0;
		while(*(str++) == '0')//Loop to calulate offset 
			c++;
		return c;
	 } 
}