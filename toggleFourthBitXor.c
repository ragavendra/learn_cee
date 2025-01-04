/*
 * =====================================================================================
 *
 *       Filename:  toggleFourthBitXor.c
 *
 *    Description:  Toggle 4th bit using XOR
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

		  // XOR with 8 which is 1000 to toggle 4th bit
		  printf("No. after 4th bit toggle is %d\n", no ^ 8);

	 }while(no > 0);
}
