#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void swap(int *px, int *py);

int main(){
	 int a = 3, b = 2;
	 swap(&a, &b);

   printf("a is %d and b is %d\n", a, b);
	 return 2;
}

void swap(int *px, int *py)
{
	int temp;
	/* interchange *px and *py */
	temp = *px;
	*px = *py;
	*py = temp;
}

