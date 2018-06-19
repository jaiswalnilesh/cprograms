#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void main()
{
	char again='n';
	int i,j,row,column,*arr,*resultArr;
	int k;
	//int *tp=(int *)calloc(4,4);
	int* findSaddle(int *arr,int row,int column);
	char isInt(int no);
	do
	{
		printf("Enter The Array Row Dimension : ");
		fflush(stdin);
		scanf("%d",&row);
		while(row<0)
		{
			printf("Enter The VALID Array Row Dimension : ");
			fflush(stdin);
			scanf("%d",&row);
		}
		printf("Enter The Array Column Dimension : ");
		fflush(stdin);
		scanf("%d",&column);
		while(column<0)
		{
			printf("Enter The VALID Array Column Dimension : ");
			fflush(stdin);
			scanf("%d",&column);
		}
		arr=(int *)malloc(sizeof(int)*row*column);
//		resultArr=(int *)malloc(sizeof(int)*((row*column)+1));
		printf("Enter Array Elements : ");
		for(i=0;i<row;i++)
		{
			printf("\n\tRow %d\t",(i+1));
			for(j=0;j<column;j++)
			{
				printf("\n\t\tColumn %d\t\t",(j+1));
				fflush(stdin);
				scanf("%d",((arr+(i*column))+j));
				k=*((arr+(i*column))+j);
/*				if(isInt(k)=='n')
				{
					if((*((arr+(i*column))+j)>=0) || (*((arr+(i*column))+j)<0))
					{
						fflush(stdin);
						printf("\nENTER CORRECT : Column %d\t\t",(j+1));
						scanf("%d",((arr+(i*column))+j));
					}
				}*/
			}
		}
		resultArr=findSaddle(arr,row,column);
//		realloc(resultArr,((((*resultArr)*2)+1)*sizeof(int)));
		if(resultArr[0]!=-1)
		{
			printf("\n\n\nEntered Array Is : ");
			printf("\n\t\t\t%c",218); //left top character
			for(i=0;i<column+1;i++) //give the spaces required for printing
							//the right top character
				printf("\t");
			printf("%c",191); //right top character
			for(i=0;i<(2*row);i++) //(2*row) for considering new line even 
								//if the number is not to be printed
			{
				printf("\n\t\t\t%c",179); //normal character
				if(i%2==0) //we have to print the digits for half the loop
						//count as we have twisced the actual loop count
				{
					for(j=0;j<column;j++)
					{
						printf("\t%d",*((arr+((i/2)*column))+j));
					}
				}
				else
				{
					for(j=0;j<column;j++)//if we are not printing the number,
						//give the spaces required for printing
							//the right top character
						printf("\t");
				}
				printf("\t%c",179);	//normal character
			}
			printf("\n\t\t\t%c",192);//print bottom left character
			for(i=0;i<column+1;i++)//give the spaces required for printing
							//the right bottom character
				printf("\t");
			printf("%c",217);	//print bottom right character

			printf("\n\n\n\tThe Array is having %d Saddle Points",resultArr[0]);
			for(i=1;i<=(2*resultArr[0]);i+=2)
				printf("\n\n\n\tSaddle Point is %d And It's Location Is [%d][%d] ",
					*((arr+resultArr[i]*column)+resultArr[i+1]),resultArr[i],resultArr[i+1]);
		}
		else
			printf("NO SADDLE POINT IS THERE ");
		memset(resultArr,0,(((*(resultArr)*2)+1))*sizeof(int));
		free(arr);
		free(resultArr);
		
		printf("\n\n\t\tDo You Want To Enter Again?(y/n) : ");
		fflush(stdin);
		scanf("%c",&again);
	}while(again=='y' || again=='Y');
	
}

/*
METHOD THAT FINDS THE SADDLE POINT OF THE ARRAY
@param arr : pointer to the integer array
@param row : the row count of the array
@param column : the column count of the array
@return int* : returns the array  containing the row index and 
	column index of the saddle point.If saddle point does not exist,it contains -1,-1
*/
int* findSaddle(int *arr,int row,int column)
{
	int* result=(int *)malloc(((2*row*column)+1)*sizeof(int));//result array
	int resultCount=1;
	char done; //character that denotes the end of operation
	int i,j,smallestPosCount;
	int *smallestElem=(int *)malloc(column*sizeof(int));
	int *smallestPos=(int *)malloc(column*sizeof(int));
	memset(result,-1,5);
	for(i=0;i<row;i++)
	{
		smallestElem[0]=*(arr+(i*column));
		memset(smallestPos,0,column);
		smallestPosCount=0;
		done='y';
		for(j=0;j<column;j++) //find the smallest element
		{
			if((*(arr+(i*column)+j))==smallestElem[0]) //if smallest is repeted
					//no smallest is there
			{
				smallestElem[smallestPosCount]=(*(arr+(i*column)+j));
				smallestPos[smallestPosCount++]=j;
			}
			else if((*(arr+(i*column)+j))<smallestElem[0])
			{
				smallestPosCount=0;
				smallestElem[smallestPosCount]=(*(arr+(i*column)+j));
				smallestPos[smallestPosCount++]=j;
			}
		}
		while(--smallestPosCount>=0)
		{
			for(j=0;j<row;j++)//check if the smallest in that row is 
					//not smaller in any element in that column
			{
				if((*(arr+(i*column)+smallestPos[smallestPosCount]))<(*(arr+(j*column)+smallestPos[smallestPosCount])))
				{
					done='n';
					break;
				}
			}
			if(done=='y')
			{
				result[resultCount++]=i;
				result[resultCount++]=smallestPos[smallestPosCount];
			}
		}
	}
	*result=resultCount/2;
	free(smallestElem);
	free(smallestPos);
	return result;
}

/*
checks whether the input no is integer or not
@param no : integer to be parsed;
@return char : return 'y' if function successful in parsing
			   return 'n' if function in NOT successful in parsing
*/
/*char isInt(int no)
{
	char ok='y';
	int p;
	while(no>0)
	{
		p=isdigit(no%10);
		if(p==0)
		{
			ok='n';
			break;
		}
		else
			no=no/10;
	}
	return ok;
}*/