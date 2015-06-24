/*
 *  main.c
 *  
 * Shuwen Ruan, B00510391
 * Login: sruan
 * CSCI2132: Assignment 4
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  /*for sqrt()*/
#include "list.h"  /*for linked list*/

/*for length count*/
double dotlength=0;

/*create a new Node*/
struct node *createNode(double xV, double yV)
{
	struct node *new;
	new=malloc(sizeof(struct node));
	if (new == NULL) {
    fprintf(stderr,"malloc failed in insert\n");
    exit(EXIT_FAILURE);
  }
  new->x=xV;
  new->y=yV;
  new->next=NULL;
  return new;
}

/*insert a new node at begin of linked list n*/
struct node *insert(struct node *n, double xV, double yV)
{
	struct node *new;
	new=malloc(sizeof(struct node));
	if (new == NULL) {
    fprintf(stderr,"malloc failed in insert\n");
    exit(EXIT_FAILURE);
  }
  new->x=xV;
  new->y=yV;
  new->next=n;
  return new;
}

/*move a node change
 *from list nodes to tour*/
move(struct node *change)
{
	struct node *curr, *prev;
	curr=nodes;
	prev=NULL;
	
	
	tour=insert(tour,change->x,change->y);
  if(curr==change)
  {
  	nodes=nodes->next;
  }
  else
	{	
		while(curr->next!=change)
	  {
	  	curr=curr->next;
	  }
	  curr->next = change->next;
	}
	  
  free(change);

}

/*get the length of two dots*/
double length(double x1, double y1, double x2, double y2)
{
	double d;
	d=sqrt((((x1)-(x2))*((x1)-(x2)))+(((y1)-(y2))*((y1)-(y2))));
	return d;
}

/*get the next closest point for nodes*/
struct node *nextpoint()
{
	double shortest=10.0;
	struct node *curr=nodes;
	struct node *shortNode=NULL;
	
	while(curr!=NULL)
	{
		if(shortest>length(curr->x,curr->y,tour->x,tour->y))
		{
			shortest=length(curr->x,curr->y,tour->x,tour->y);
			shortNode=curr;
		}
		curr=curr->next;
	}
	if(shortNode!=NULL)
		dotlength+=shortest;
	return shortNode;
}



/*main program*/
int main(int argc, char *argv[])
{
  double x,y;
	struct node *nextp, *first;
	nodes=NULL;
	
	/*get 2 files 
	* for read and write*/
	FILE *fp1,*fp2;
	
	/*read first as input data*/
	if ((fp1=fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "cannot open source\n");
    exit(EXIT_FAILURE);
  }
 	
 	/*insert data into nodes*/
  while(fscanf(fp1, "%lf %lf\n", &x, &y)!=EOF)
  {
  	nodes=insert(nodes,x,y);
  }
  fclose(fp1);
  
  /*save the first node for count the length*/
  first=createNode(nodes->x,nodes->y);
  
  /*move nodes to tour
 	 * in order*/
  nextp=nodes;
  while(nodes!=NULL)
  {
  	move(nextp);
  	nextp=nextpoint();
  }
  
  /*create second file to write*/
  fp2=fopen(argv[2], "w");
  
  /*write PostScropt file*/
  plotTour(tour,fp2);
  fclose(fp2);
  
  /*count length*/
  dotlength+=length(tour->x, tour->y, first->x, first->y);
  fprintf(stderr, "%lf\n",dotlength);
  
  exit(0);
}


