/*
 *  prefix.c
 *  
 * Shuwen Ruan, B00510391
 * Login: sruan
 * CSCI2132: Assignment 5
 *
 *main program
 *usage: ./decode [input file] [output file]
 * eg: ./decode GB.pfx out
 */
#include <stdio.h>
#include <stdlib.h>
#include "node.h" /*node struct*/

struct node *makeTree();

int main(int argc, char *argv[])
{
	/*open two files
	 *first to read
	 *second to write
	 */
	FILE *fp1,*fp2;
	char description[200],ch;
	/*read file*/
	if ((fp1=fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "cannot open source\n");
    exit(EXIT_FAILURE);
  }
  /*read file description code*/
  int index=0;
  while((ch=fgetc(fp1))!=EOF&&ch!='0')
  {
  	description[index]=ch;
  	index++;
  }
  description[index]='\0';
  
  /*make tree*/
  tree=makeTree(description);
   
  /*traverse tree*/
  traverseTree(tree, 0);
  
  /*open second file to write*/
  fp2=fopen(argv[2], "w");
  
  /*decode and write into file*/
  decodeMessage(fp1,fp2);
  
  /*close two files*/
	fclose(fp2);
  fclose(fp1);
}
