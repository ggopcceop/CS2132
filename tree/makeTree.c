/*
 *  makeTree.c
 *  
 * Shuwen Ruan, B00510391
 * Login: sruan
 * CSCI2132: Assignment 5
 *
 *funtion to make the tree data struct
 */
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

/*index for tree*/
int i=0;

struct node *makeTree(char c[])
{
	if(c[i]!='\0')
	{
		/*if reads ~
		 *create a new node*/
		if(c[i]=='~')
		{
			struct node *new;
			new=malloc(sizeof(struct node));
			if (new == NULL) {
    		fprintf(stderr,"malloc failed in insert\n");
    	exit(EXIT_FAILURE);
  		}
			new->character='\0';
			/*new left and right*/
			i++;
			new->left=makeTree(c);
			i++;
			new->right=makeTree(c);
			
			return new;
		}
		/*else create a new node
		 *put c[i] into character*/
		else
		{
			struct node *new;
			new=malloc(sizeof(struct node));
			if (new == NULL) {
    		fprintf(stderr,"malloc failed in insert\n");
    		exit(EXIT_FAILURE);
  		}
			new->character=c[i];
			/*next left and right is NULL*/
			new->left=NULL;
			new->right=NULL;
			
			return new;
		}
	}
	else
	{
		return NULL;
	}
}
