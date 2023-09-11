#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	 printf("Print args\n");
	 for(int i = 1; i < argc; i++)
	 {
		  printf("Arg %d is %s\n", i, argv[i]);
	 }

	 // printf("try mem");
	 int no[] = { 1, 6, 10 };
	 char *q[3];
	 // char *p = malloc(3 * sizeof(char));
	 // char *p = "string";
	 char p[] = "string";
	 printf("Str :%12.3s: \n",  p);

	 char *a = p;
	 *p = 'a';
	 printf("Str %s \n",  a);
//	 free(p);

	 int s[] = { 12, 11, 10, 06, 15 };
	 *s = 66;
	 printf("No is %d", *s);

	 printf("Int arr size - %lu", sizeof(no));

	 int nos[10];
	 memset(nos, 0, 10 * sizeof(int));
	 for(int i = 0; i < 10; i++)
	 {
		  printf("No is %d\n");
	 }

	 char *t = malloc(8);
	 strcpy(t, "aaa");
	 printf("%s \n", t);
	 printf("%d \n", &t);
	 free(t);
	 printf("%d \n", &t);
	 t = "New str";
	 printf("%s", t);
}
