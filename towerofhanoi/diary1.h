#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct diary_info
{
	char name[20];
  char email_addr[60];
	int ph_num;
	char city[25];
 struct diary_info *next;  
};

typedef struct diary_info DIARY;
void create(DIARY **);

void disply( DIARY *);

void qSort( DIARY **);

void sort( DIARY **, int, int);

void swap( DIARY **,  DIARY *,  DIARY *);

void insert( DIARY **,  DIARY *,  DIARY *);
