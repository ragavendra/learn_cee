#include <stdio.h>
int SharedVar;

void PrintVar(int no)
{
	 // custom line here
	 int a[4] = { 0, 1, 3, 7};
	 // char b[] = "This is a str length.";
	 char *b = "This is a str length.\n";
	 printf("Checking buffer over run %s\n", b);
	 // printk(KERN_DEBUG *b);
	 printf("In cus, no is %d\n", no);

	 // udt here for common
	 SharedVar = 1;
}
