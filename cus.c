#include <stdio.h>
int SharedVar;

void PrintVar(int no)
{
	 printf("In cus, no is %d", no);

	 // udt here for common
	 SharedVar = 1;
}
