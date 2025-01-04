/*
 * =====================================================================================
 *
 *       Filename:  toggleThirdBitXor.c
 *
 *    Description:  Toggle 3rd bit using XOR
 *
 *        Version:  1.0
 *        Created:  2024-12-31 12:03:30 PM
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
	 int no;

	 do{
		  printf("Enter a no: ");

		  // if int returns no of digits or 0
		  if(scanf("%d", &no) > 0){}
		  else
			   break;

		  printf("No is : %d\n", no);

		  // XOR with 4 which is 0100 to toggle 3rd bit
		  printf("No. after 3rd bit toggle is %d\n", no ^ 4);

	 }while(no > 0);
}
