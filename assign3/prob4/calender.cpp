//PROGRAM THAT PRINTS THE 1 ST JAN DAY ON A SPECIFIED YEAR
#include<stdio.h>
void main()
{
	 int year;
	 long days;
	 char again='n';
	 long getDays(int year);
	 do
	 {
		 printf("Enter the year of which the 1 st Jan Day is to be calculated : ");
		 fflush(stdin);
		 scanf("%d",&year);
		 while(year<1899)
		 {
			 printf("Enter A Year More Than 1899 : ");
			 fflush(stdin);
			 scanf("%d",&year);
		 }
		 days=getDays(year);
		 switch(days%7)
		 {
		 case 0:
			 printf("Day on 1 Jan %d is MONDAY",year);
			 break;
		 case 1:
			 printf("Day on 1 Jan %d is TUESDAY",year);
			 break;
		 case 2:
			 printf("Day on 1 Jan %d is WEDNESDAY",year);
			 break;
		 case 3:
			 printf("Day on 1 Jan %d is THURSDAY",year);
			 break;
		 case 4:
			 printf("Day on 1 Jan %d is FRIDAY",year);
			 break;
		 case 5:
			 printf("Day on 1 Jan %d is SATERDAY",year);
			 break;
		 case 6:
			 printf("Day on 1 Jan %d is SUNDAY",year);
			 break;
		 default:
			 printf("Day on 1 Jan %d is ???",year);
		 }
		 printf("\n");
		 printf("Do You Want to enter Again?(y/n)");
		 fflush(stdin);
		 scanf("%c",&again);
	 }while(again=='y' || again=='Y');
}
/**
METHOD THAT CALCILATES THE NUMBER OF DAYS IN BETWEEN THE YEAR SPECIFIED AND YEAR 1900
IT TAKES CARE OF THE LEAP YEARS ALSO.
@return long : returns the number of days in between the year specified and the year 1900
*/
long getDays(int year)
{
	int getLeapYearsInBetn(int year);
	return ((year-1900)*365+getLeapYearsInBetn(year));
}
/**
METHOD TO CALCULATE THE NUMBER OF LEAP YEARS BETWEEN THE YEAR SPECIFIED AND YEAR 1900
@return int : returns the numbr of leap years between the year specified and year 1900
*/
int getLeapYearsInBetn(int year)
{
	int count=0;
	for(;year>=1900;year--)
	{
		if((year%4==0 && !(year%100==0)) || (year%100==0 && year%400==0))
		{
			count++;
		}
	}
	return count;
}