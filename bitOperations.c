/*
 * =====================================================================================
 *
 *       Filename:  bitOperations.c
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

// OR
// 1 << pos gives no in binary - 8 4 2 1
int setNthBit(int no, int pos){
	 int s = sizeof(no);
	 return no | ( 1 << pos );
}

// XOR
int toggleNthBit(int no, int pos){
	 return no ^ ( 1 << pos );
}

// if 1 then is set else 0
// AND
int checkNthBit(int no, int pos){
	 return no & ( 1 << pos ) ? 1 : 0;
}

// AND and compl
int clearNthBit(int no, int pos){
	 return no & ( ~( 1 << pos ));
}

/* this is not right
int multiply(int no, int mul){
	 return no << mul/2;
}*/

int multiply(int a, int b){
	 int res = 0;

	 while(b > 0) {
		  // if b is odd, add it to res
		  if(b & 1) {
			   res = res + a;
		  }

		  a = a << 1;
		  b = b >> 1;
	 }
	 return res;
}

int main(){
	 int no;
	 int pos;
	 int res;
	 char op;

	 do{
		  printf("Enter operation: a set, b toggle, c check, d clear, e multiply and q exit: ");

		  // can use below if not " %c"
		  // fflush(stdin);
		  if(scanf(" %c", &op) > 0){}
		  // if(scanf("%d %c", &no, &op) > 0){}
		  // if(scanf("%d%d", &no, &pos) > 0){}
		  else
			   break;

		  if(op == 'q')
			   return 0;

		  printf("Enter a no: ");

		  // if int returns no of digits or 0
		  if(scanf("%d", &no) > 0){}
		  else
			   break;

		  if(no <= 0){
			   printf("\nEnter no greater than 0\n");
			   continue;
		  }

		  printf("\nEnter bit position: ");

		  if(scanf("%d", &pos) > 0){}
		  else
			   break;

		  pos--;
		  if(pos < 0){
			   printf("\nEnter bit position greater than 0\n");
			   continue;
		  }

		  switch(op){
			   case 'a': res = setNthBit(no, pos);
					 break;
			   case 'b': res = toggleNthBit(no, pos);
					 break;
			   case 'c': res = checkNthBit(no, pos);
					 break;
			   case 'd': res = clearNthBit(no, pos);
					 break;
			   case 'e': res = multiply(no, ++pos);
					 break;
			   default: 
					 printf("Unknown option %c", op);
					 break;
		  }

		  printf("Nr. %d after %c on bit pos %d is %d\n", no, op, pos+1, res );

	 }while(op != 'q');
}
