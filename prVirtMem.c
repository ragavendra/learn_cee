/*
 * =====================================================================================
 *
 *       Filename:  prVirtMem.c
 *
 *    Description:  Print virt memory against actual RAM - Emb Linux Premier 2-4 
 *
 *        Version:  1.0
 *        Created:  2024-12-04 05:47:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ragavendra N (rn), ragavendra.bn@gmail.com
 *        Company:  Garden Systems, Vancouver
 *
 * =====================================================================================
 */

#include <stdio.h>

int bss_var;

/* Uninitialized global variable */
int data_var = 1;

/* Initialized global variable */
int main(int argc, char **argv)
{
	 void *stack_var;

	 /* Local variable on the stack */
	 stack_var = (void *)main;

	 /* Don't let the compiler */
	 /* optimize it out */
	 // printf("Hello, World! Main is executing at %p %#020x \n", stack_var, (unsigned long)stack_var);
	 printf("Hello, World! Main is executing at %p %lu (in decimal) \n", stack_var, (unsigned long)stack_var);

	 printf("This address (%p) %lu is in our stack frame \n", &stack_var, (unsigned long)&stack_var);

	 /* bss section contains uninitialized data */
	 printf("This address (%p) %lu is in our bss section\n", &bss_var, (unsigned long)&bss_var);

	 /* data section contains initializated data */
	 printf("This address (%p) %lu is in our data section\n", &data_var, (unsigned long)&data_var);
	 return 0;
}
