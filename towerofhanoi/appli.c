/* this is a simple hello world program */

#include <cyg/kernel/kapi.h>
#include "diary.h"
//#include <stdio.h>

#define NTHREADS 1
#define STACKSIZE 4096

static cyg_handle_t thread[NTHREADS];

static cyg_thread thread_obj[NTHREADS];
static char stack[NTHREADS][STACKSIZE];

static void alarm_prog( cyg_addrword_t data );
void test_alarm_func(cyg_handle_t alarmH, cyg_addrword_t data);
int add();
int sub();
int mul();
int div1();
int diary();
DIARY *header = NULL;

int main(void)

{
 
 cyg_addrword_t data;
 int x;
 while(1)
 {
   fflush(stdout);
   diag_printf("eCos enSys version -1.0\n");
   diag_printf("\n\nHello, enSys world!\n");
   diag_printf("\n----- MENU-------\n");
   diag_printf("\n 1.-> ALARM\n");
   diag_printf("\n 2.-> CALCULATOR\n");
   diag_printf("\n 3.-> DIARY\n");
   fflush(stdin);
  fflush(stdin);
   scanf("%d",&x); 
   //diag_printf("YOU have entered :");
 
   switch(x)
   {
      case 1:
      {
	  alarm_prog( data);
	  break;
      }
      case 2:
      {
	  int  value;
 
	  diag_printf("1.ADDITION\n");
	  diag_printf("2.SUBSTRACTION\n");
	  diag_printf("3.MULTIPLICATION\n");
	  diag_printf("4.DIVISION\n");
  
	  fflush(stdin);
	  scanf("%d",&value); 

	  switch(value)
	  {
	       case 1:
		 add();
		 break;

	       case 2:
		 sub();
		 break;

               case 3:
		 mul();
		 break;

               case 4:
		 div1();
		 break;		
	  }
	  //continue;
	   break;
      } // case 2
      // continue;
   
      case 3:
	diary();
	break;
   } // end of main switch
   continue;
 }// end of while
}// end of main

int add()
{
  int a, b,c;
	diag_printf("Enter Two  No.\n");
	fflush(stdin);
	scanf("%d %d",&a,&b );
	c=a+b;
	diag_printf("Addition of %d & %d is %d \n",a ,b, c);
       
}
int mul()
  {
	    int m, n,q;
	    diag_printf("\nEnter two no:\n");
	    fflush(stdin);
	    m=0;
	    n=0;	
    scanf("%d %d",&m ,&n);
	    q = (m) * (n);
	    diag_printf("\nMultiplication of %d & %d is %d\n",m,n,q);
       
  }	   
 int sub()
	{
	  int x, y,z;
	  diag_printf("Enter the two No\n.");
	  fflush(stdin);
	  scanf("%d %d",&x ,&y);
	  z=x-y;
	  diag_printf("\nSubstraction of %d & %d is %d \n",x,y,z); 
 
	}

 int div1()
   {
     int u,v,w;
     diag_printf("Enter two No.\n");
     fflush(stdin);
     scanf("%d %d",&u ,&v);
     w = (u)/(v);
     diag_printf("\nDivision of %d & %d is %d\n",u,v,w);
   }
   

/* test_alarm_func() is invoked as an alarm handler, so
   it should be quick and simple.  in this case it increments
   the data that is passed to it. */


int diary()
{
       //char another ;
       int another;
       //DIARY *header;
	
	while(1)
	{
	  diag_printf("\nEnter 1 to Update Address Book\n");
	  diag_printf("\nEnter 2 to get available addresses \n ");
	  diag_printf("\nEnter 3 to sort Address\n ");
	  fflush(stdin);
	  scanf("%d",&another);
		
	  switch(another)
	    {
	    case 1:
	      create(&header);
	      break;
			
	    case 2:
	      disply(header);
	      break;
	    case 3:
	      qSort(&header);
	      break;
	      }
		//diag_printf("\n\nwanna continue (y/n)");
	  // fflush(stdin);
		 //scanf("%c",&another);
		 //if(another == 'n' || another == 'N')
		 break;
	}
}	/* end of main	*/


void create(DIARY **first)
{
	DIARY *temp;
	int no=1;
	temp = (*first);
	if((*first) != NULL)
	{
		while(temp->next != NULL)
			temp = temp->next;
	}
	
	while(no)
	{
		if((*first) == NULL)
		{
			(*first) = (DIARY *)malloc(sizeof(DIARY));
			temp = (*first);
		}
		else
		{
			temp->next = (DIARY *)malloc(sizeof(DIARY));
			temp  = temp->next;
		}
		fflush(stdin);
		diag_printf("\nEnter the name :\n");
		fflush(stdin);
		scanf("%s",temp->name);
		fflush(stdin);
		diag_printf("\nEnter the Phone Number :\n");
		
		fflush(stdin);

		scanf("%d",&temp->ph_num);
		
		fflush(stdin);

		diag_printf("\nEnter Email_address :\n");

		fflush(stdin);

		scanf("%s",temp->email_addr);

		diag_printf("\nEnter the City :\n");

		fflush(stdin);

		scanf("%s",temp->city);

		temp->next = NULL;

		diag_printf("\n MORE Operation: 1 :: EXIT:0  \n");

		fflush(stdin);
		scanf("%d",&no);
	}

}

void disply(DIARY *first)
{
 int n;
n =0;	

diag_printf("\nADDRESSES\n:");

while(first!= NULL && n==0)
	{

		diag_printf("\n Name     ::  %s",first->name);
		diag_printf("\n Phone No ::  %d", first->ph_num);
		diag_printf("\n City     ::  %s", first->city);
		diag_printf("\n Email ID::   %s",first->email_addr);
		diag_printf("\n******************************\n");
		first =first->next;
		diag_printf("Press 0 to continue.....");

		fflush(stdin);
		scanf("%d",&n);
		
	}
	
}	/*	end of the disply function.	*/




/*	Function for Quick sort..	*/
void qSort(DIARY **first1)
{
	DIARY *cTemp;
	int iCount=0;

	cTemp = (*first1);
	while(cTemp != NULL)
	{
		iCount++;
		cTemp = cTemp->next;
	}
	
	
	sort(&(*first1), 1, iCount);
}


void sort(DIARY **first, int begin, int end)
{
	int down=1, up, init, flag=1, k;
	DIARY *temp, *temp1, *temp2;
	temp = (*first);
	k = begin;
	init = end;
	/* bring the temp to the key position..	*/
	while(down != begin)
	{
		temp = temp->next;
		down++;
	}
	temp1 = temp;
	temp2 = temp;
	
	/*	Travers the complete file for sorting..	*/
	for(down = begin; down <= end; down++)
	{
		if(flag)
		{
			/*	Move the up variable to its appropriate position...	*/
			for(up = init; up > begin; up--)
			{
				/* bring the temp2 to up position..	*/
				while(k != init)
				{
					temp2 = temp2->next;
					k++;
				}
				
				k = begin;
				if((strcmp(temp2->name, temp->name) <= 0)) 
				{
					/*	if condition satisfies then set the init for next iteration..	*/
					init = up-1;
					break;
				}
				else
				{
     /*	decrement the init to reach the proper node..*/
					
				  temp2 = temp;
					init--;
				}
			}
			flag=0;
		}

		/*	Move the down to the next node to get the down..	*/
		temp1 = temp1->next;

		/*	check if the down element is greter than the key element..	*/
		if((strcmp(temp1->name, temp->name) > 0) && (down < up))
		{
			swap(&(*first),temp1,temp2);
			flag = 1;
			/*	bring the temp1 & temp2 to its original index..	*/
			temp1 = temp2;
			temp2 = temp;
		}
	
		/* if up & down crossed each other	*/
		if(up <= down || (down == end-1))
		{

			/*	if the up element is equal to the key element then dont swap the nodes..	*/
		  if(((strcmp(temp2->name, temp->name) == 0)) && (down < up))
				break;

			swap(&(*first), temp, temp2);
			break;
		}
	}
	
	/*	call the function once again if there is subarray on leftside of the key element...	*/
	if(down >= (begin+1))
		sort(&(*first), begin, down);
	/*	call the function once again if there is subarray on rightside of the key element...	*/
	if(up <= (end-2))
		sort(&(*first), down+1, end);	

}	/*	end of the qsort function..	*/


/* Function to swap the nodes....	*/
void swap(DIARY ** first, DIARY *temp, DIARY * temp1)
{
	DIARY * move, * check1, * check2;
	move = (*first);
	while(move != NULL)
	{
		if(temp == (*first))
			break;
		
		check1 = move;
		move = move->next;
		if(move == temp)
			break;
	}
	move = (*first);
	while(move != NULL)
	{
		if(temp1 == (*first))
			break;

		check2 = move;
		move = move->next;
		if(move == temp1)
			break;
	}
	if(temp == temp1)
		return;
	if(temp == (*first) )
	{
		(*first) = temp1;
		/* for first & second node..	*/
		if(temp == (*first) && (temp1 == temp->next))
		{
			temp->next = temp1->next;
			temp1->next = temp;
			return;
		}
		else
		{
			check2->next = temp;
			check1 = temp->next;
			temp->next = temp1->next;
			temp1->next = check1;
			return;
		}

	}
	else
	{
		/*	if adjucent node & neither of a node is first node..	*/
		if(temp1 == temp->next)
		{
			/*	if temp is before temp1..	*/
			if(temp1 = temp->next)
			{
				check1->next = temp1;
				temp->next = temp1->next;
				temp1->next = temp;
				return;
			}
		}
		else
		{
			/*	if nodes are not adujcent & not first	*/
			check1->next = temp1;
			check2->next = temp;
			check2 = temp1->next;
			temp1->next = temp->next;
			temp->next = check2;
			return;
		}
	}
}	




static void alarm_prog(cyg_addrword_t data)
{
    cyg_handle_t test_counterH, system_clockH, test_alarmH;
  cyg_tick_count_t ticks;
  cyg_alarm test_alarm;
  int  ctime ,atime;

    unsigned how_many_alarms = 0, prev_alarms = 0, tmp_how_many;

  system_clockH = cyg_real_time_clock();
  cyg_clock_to_counter(system_clockH, &test_counterH);
  cyg_alarm_create(test_counterH, test_alarm_func,
		   (cyg_addrword_t) &how_many_alarms,
		   &test_alarmH, &test_alarm);
  cyg_alarm_initialize(test_alarmH, cyg_current_time()+200, 100);
  
  /* get in a loop in which we read the current time and
    diag_print it out, just to have something scrolling by */

 
    diag_printf("\nEnter Time for Alarm Call::8888:\n");
   
    fflush(stdin);
    scanf("%d", &atime);

    diag_printf("\n Enter current time::8888:\n");
    scanf("%d", &ctime);
 
    ticks = cyg_current_time();
   
    if(ctime >= 1200 || ctime <= 2400)
      {
	if(ctime ==1200 || ctime == 2400)
	  atime=atime;
	else
	  atime=atime-ctime;
      }
    atime = atime  * 60;
    
      
	  
 for (;;) 
   {
     //  diag_printf("Time is %d\n", ticks);
	 /* note that we must lock access to how_many_alarms, since the
	    alarm handler might change it.  this involves using the
	    annoying temporary variable tmp_how_many so that I can keep the
	    critical region short */
	cyg_scheduler_lock();
	tmp_how_many = how_many_alarms;
	cyg_scheduler_unlock();
	if (prev_alarms != tmp_how_many) 
	  {
	  diag_printf("counter : %d\n", tmp_how_many);

	     atime--;
	     if(atime == 0)
	       {
		 diag_printf("\nYOUR ALARM IS RINGING\n");
		
		  cyg_alarm_delete(test_alarmH);
		  break;
	       }
	  prev_alarms = tmp_how_many;
	  }
	cyg_thread_delay(30);


   }
}
/* test_alarm_func() is invoked as an alarm handler, so
   it should be quick and simple.  in this case it increments
   the data that is passed to it. */
void test_alarm_func(cyg_handle_t alarmH, cyg_addrword_t data)
{
  ++*((unsigned *) data);
}


