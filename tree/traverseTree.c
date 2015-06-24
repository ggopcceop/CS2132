/*
 *  traverseTree.c
 *  
 * Shuwen Ruan, B00510391
 * Login: sruan
 * CSCI2132: Assignment 5
 *
 *funtion traverse the tree
 */
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

/*level stand for how deep the char
 *can be found*/
traverseTree(struct node *n, int level)
{
	if(level==0)
	{
		fprintf(stderr,"character  bits\n---------------\n");
		traverseTree(n->left, level+1);
		traverseTree(n->right, level+1);
	}
	else if(n->character!='\0')
	{
		/*if reads newline or tab
		 *print it*/
		if(n->character=='\n')
			fprintf(stderr," \\n \t   %d\n",level);
		else if(n->character=='\t')
			fprintf(stderr," \\t \t   %d\n",level);
		else
			fprintf(stderr," %c\t   %d\n",n->character,level);
		
	}
	else
	{
		traverseTree(n->left, level+1);
		traverseTree(n->right, level+1);
	}
}
