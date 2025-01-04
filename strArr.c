/*
 * =====================================================================================
 *
 *       Filename:  strArr.c
 *
 *    Description:  String array 
 *
 *        Version:  1.0
 *        Created:  2025-01-03 04:29:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ragavendra N (rn), ragavendra.bn@gmail.com
 *        Company:  Garden Systems, Vancouver
 *
 * =====================================================================================
 */

#include	<stdio.h>
#include	<ctype.h>
#include	<string.h>

int main(){
	 // char arr[] = { "This is a string" };
	 // char arr2[] = "This is a string";
	 char arr3[3] = "as" ;
	 arr3[0] = 'c';

	 if(strcpy(arr3, "hi")){
		  printf("\narr3 is now %s", arr3);
	 }

	 // gets(arr3);
	 puts(arr3);

	 // char arr4[] = {'a', 'b'}; 
	 // char arr4[10] = {'a', 'b'};  // only first two will be init

	 char firstName[10];
	 printf("\nFirst name without init is: %c", firstName[3]);
	 char lastName[10] = {}; // init to \0 which is null and nothing will print
	 printf("\nLast name after init is: %c", lastName[3]);
	 printf("\nEnter first name: ");
	 scanf("%s", firstName);

	 printf("\nEnter last name: ");
	 scanf("%s", lastName);
	 printf("\nYour full name: %s", strcat(firstName, lastName));
	 printf("\nlastName length is %ld", strlen(lastName));
	 printf("\nlastName size in bytes %ld", sizeof(lastName));

	 // if(isalpha(lastName[0]))
		  printf("\nFirst char of lastName is an alphabet %d",isalpha(lastName[0]));

	 // if(isdigit(lastName[0]))
		  printf("\nFirst char of lastName is a digit %d",isdigit(lastName[0]));

	 // if(isalnum(lastName[0]))
		  printf("\nFirst char of lastName is an alphabet or a digit %d",isalnum(lastName[0]));

	 // if(isupper(lastName[0]))
		  printf("\nFirst char of lastName is upper case %d",isupper(lastName[0]));

	 // if(islower(lastName[0]))
		  printf("\nFirst char of lastName is lower case %d",islower(lastName[0]));

	 printf("\nFirst char of firstName to lower case %c", tolower(firstName[0]));

	 printf("\nFirst char of firstName to upper case %c", toupper(firstName[0]));

	 // if(isspace(firstName[0]))
		  printf("\nIs a space.%d",isspace(' '));

	 for(int i=0; i<strlen(firstName); i++) {
		  firstName[i] = toupper(firstName[i]);
	 }

	 firstName[0] = 75;
	 printf("\nFirst char of firstName for asc ii 75 %c", firstName[0]); // asc ii for K is 75

	 printf("\nfirstName in upper case. %s", firstName);
	 // almost all methods return +ve or 1 or true or its ASCII value
	 // 0 or false
}
