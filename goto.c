/*
 * =====================================================================================
 *
 *       Filename:  goto.c
 *
 *    Description:  Learn go to 
 *
 *        Version:  1.0
 *        Created:  2024-11-18 12:28:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ragavendra N (rn), ragavendra.bn@gmail.com
 *        Company:  Garden Systems, Vancouver
 *
 * =====================================================================================
 */

#include	<stdio.h>
#include	<string.h>

int main() {
	 int a = (int) 2.3423;

	 if ( a > 10 ) {
		  goto err;
	 } else {
		  goto okay;
	 }

err: printf("a is > than 10");
okay: printf("a is < than 10");

	printf("End of main");

}
