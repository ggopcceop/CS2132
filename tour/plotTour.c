/*
 *  plotTour.c
 *  
 * Phil Cox, B00XXXXXX
 * Login: pcox
 * CSCI2132: Assignment 3
 *
 */

#include <stdio.h>
#include "list.h"

void plotTour(struct node *tour,FILE *fp2)
{
	/*
	 *	Print postscript code depicting a given tour
	 */

	struct node	*curr;

	if (tour == NULL)
		return;

	fprintf(fp2,"%%!\n50 50 translate\n0 0 512 512 rectstroke\n");
	
	/* plot the tour's edges */
	fprintf(fp2,"%5.1f %5.1f moveto\n", 512.0*tour->x, 512.0*tour->y);
	fprintf(fp2,"1.0 0.0 0.0 setrgbcolor\n");
	for (curr=tour->next; curr != NULL; curr=curr->next)
		fprintf(fp2,"%5.1f %5.1f lineto\n",
			512.0*curr->x, 512.0*curr->y);
	fprintf(fp2,"closepath stroke\n");
	
	/* plot dots marking the locations of the nodes */
	fprintf(fp2,"0.0 0.0 0.0 setrgbcolor\n");
	for (curr=tour; curr!=NULL; curr = curr->next)
	{
		fprintf(fp2,"newpath\n");
		fprintf(fp2,"%5.1f %5.1f 2 0 360 arc\n",
			512.0*curr->x, 512.0*curr->y);
		fprintf(fp2,"closepath\nfill\n");
	}

	fprintf(fp2,("showpage\n"));
}
