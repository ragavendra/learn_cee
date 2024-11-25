/*
 * =====================================================================================
 *
 *       Filename:  deref.c
 *
 *    Description:  Learn about dereference 
 *
 *        Version:  1.0
 *        Created:  2024-11-22 10:03:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ragavendra N (rn), ragavendra.bn@gmail.com
 *        Company:  Garden Systems, Vancouver
 *
 * =====================================================================================
 */

#include	<stdio.h>

int main(){

	 int no = 4;

	 int *ptr = &no;

	 printf("Value of num is %d\n", no);
	 printf("Value of *ptr is %d\n", *ptr);
	 printf("Updating *ptr\n");
	 *ptr = 8;
	 printf("Value of num now is %d\n", no);
	 printf("Value of *ptr now is %d\n", *ptr);
}
