/*
 *  decodeMessage.c
 *  
 * Shuwen Ruan, B00510391
 * Login: sruan
 * CSCI2132: Assignment 5
 *
 *decode message
 */
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

decodeMessage(FILE *fp1,FILE *fp2)
{
	/*char counter and bit counter*/
	int ccount=0,bcount=0;
	char step;
	struct node *curr;
	curr=tree;
	/*keep reading 1||0 until end of file*/
	while(fscanf(fp1,"%c",&step)!=EOF)
	{
		/*if 0 goes left
		 *1 goes right*/
		if(step=='0')
		{
			bcount++;
			curr=curr->left;
			/*if found a char
			 *print it and start tree again*/
			if(curr->character!='\0')
			{
				fprintf(fp2,"%c",curr->character);
				ccount++;
				curr=tree;
			}
		}
		else if(step=='1')
		{
			bcount++;
			curr=curr->right;
			if(curr->character!='\0')
			{
				fprintf(fp2,"%c",curr->character);
				ccount++;
				curr=tree;
			}
		}
	}
	/*print the count*/
	fprintf(stderr,"Number of bits       = %d\n",bcount);
	fprintf(stderr,"Number of characters = %d\n",ccount);
	fprintf(stderr,"Compression ratio    = %.1lf%%\n",bcount/(ccount*8.0)*100.0);
}

