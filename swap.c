#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void swap(int *px, int *py);
int d = 88;

int main(){
	 int a = 3, b = 2;
	 printf("d is %d \n", d);

	 swap(&a, &b);

	 printf("a is %d and b is %d\n", a, b);
	 return 2;
}

void swap(int *px, int *py){

	 unsigned int c = 0;
	 printf("c is %d \n", c);

	 int temp;
	 /* interchange *px and *py */
	 temp = *px;
	 *px = *py;
	 *py = temp;
}

