/*
 * ===================================================================================== *
 *       Filename:  tryy.c
 *
 *    Description: Sample function to do the important thing. 
 *
 *        Version:  1.0
 *        Created:  2024-11-08 11:04:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ragavendra N (rn), ragavendra.bn@gmail.com
 *        Company:  Garden Systems, Iserlohn
 *
 * =====================================================================================
 */

// \p<
#include	<stdio.h>
#include	<stdlib.h>
#include	<assert.h>

// *    Description: Sample function using \if.
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  msome
 *  Description: Msome function header \cfu
 * =====================================================================================
 */

/*-----------------------------------------------------------------------------
 * \cfr for frame comment 
 *-----------------------------------------------------------------------------*/

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  calloc_double_matrix
 *  Description:  Allocate a dynamic double-matrix of size rows*columns;
 *                return a pointer.
 * =====================================================================================
 */
	 double**
calloc_double_matrix ( int rows, int columns )
{
	 int      i;
	 double **m;
	 m     = calloc ( rows, sizeof(double*) );       /* allocate pointer array     */
	 assert( m != NULL);                             /* abort if allocation failed */
	 *m    = calloc ( rows*columns, sizeof(double) );/* allocate data array        */
	 assert(*m != NULL);                             /* abort if allocation failed */
	 for ( i=1; i<rows; i+=1 )                       /* set pointers               */
		  m[i]  = m[i-1] + columns;
	 return m;
}  /* ----------  end of function calloc_double_matrix  ---------- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  free_matrix_double
 *  Description:  Free a dynamic double-matrix.
 * =====================================================================================
 */
	 void
free_double_matrix ( double **m )
{
	 free(*m);                                       /* free data array            */
	 free( m);                                       /* free pointer array         */
	 return ;
}  /* ----------  end of function free_double_matrix  ---------- */


	 void
main (  )
{
	 int i = 3;
	 printf("Trying Vim C support %d\n", i);


	 int x = 3, y = 2, no = 0;
	 double **res = calloc_double_matrix ( x, y );
	 for ( int i = 0; i < x; i++) {
		  for ( int ii = 0; ii < y; i++) {
			   printf ( "No id %d\n", no );
			   res[i][ii] = no++;
		  }
	 }

	 for ( int i = 0; i < x; i++) {
		  for ( int ii = 0; ii < y; i++) {
			   printf("No in x %d and y %d is no %c", i, ii, res[i][ii]);
		  }
	 }

	 return ;
}		/* -----  end of function main  ----- */


