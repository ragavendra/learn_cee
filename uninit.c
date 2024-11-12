/*
 * =====================================================================================
 *
 *       Filename:  uninit.c
 *
 *    Description: isfsdf 
 *
 *        Version:  1.0
 *        Created:  2024-11-09 05:33:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ragavendra N (rn), ragavendra.bn@gmail.com
 *        Company:  Garden Systems, Iserlohn
 *
 * =====================================================================================
 */

#include <stdio.h>

int main() {
	 int result = null; // Declared but not initialized

	 printf("The result is: %d\n", result); // Using uninitialized variable

	 return 0;
}

