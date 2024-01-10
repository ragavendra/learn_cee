#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cus.h"
#include <assert.h>
#include <threads.h>
#include <ctype.h>
#define NKEYS 10
typedef char *String;

/*
   gcc -Wall mem.c cus.c cus.h -o mem.o
*/

struct point {
	 int a;
	 int b;

	 union {
		  char e;
		  unsigned d;
	 };
};

struct key {
	 char *word;
	 int count;
};

int main(int argc, char *argv[])
{
	 // struct key keytab[NKEYS];
	 struct key keytab[] = {
		  { "auto", 0 }, // can be with or w/o braces
		  "break", 0,
		  "case", 0,
		  "char", 0,
		  "const", 0,
		  "continue", 0,
		  "default", 0,
		  /* ... */
		  "unsigned", 0,
		  "void", 0,
		  "volatile", 0,
		  "while", 0
	 };

	 struct point pt = { 11, 12 };
	 pt.d = -11;
	 pt.e = 's';
	 pt.a = 6;

	 printf("d is %u and e is %c", pt.d, pt.e);

	 SharedVar = 6;
	 PrintVar(SharedVar);
	 printf("Print args %d\n", SharedVar);
	 for(int i = 1; i < argc; i++)
	 {
		  printf("Arg %d is %s\n", i, argv[i]);
	 }

	 float floa = 231.123;
	 printf("Float is %.0f", floa);// no dec displayed here

	 String str = "This is a str\n";

	 printf("Typdef str is %s",  str);

	 // fork(PrintVar(SharedVar));

	 assert(SharedVar > 0);

	 int inpNo;
	 printf("Enter the size of array: ");
	 scanf("%d", &inpNo);

	 // int aNos[inpNo];
	 int *aNos = malloc(sizeof(int) * inpNo);
	 int aNos_[inpNo];
	 int inNo;

	 // aNos stores in stack
	 for(int i = 0; i < inpNo; i++)
	 {
		  printf("Enter no:");
		  scanf("%d", &inNo);
		  aNos[i] = inNo;
		  aNos_[i] = inNo;
	 }

	 for(int i = 0; i < inpNo; i++)
	 {
		  printf("No: %d %d\n", *(aNos + i), aNos_[i]); // pointer arith
	 }

	 // *aNos = malloc(sizeof(int) * inpNo);
	 // int *aNos_ = calloc(sizeof(int) * (inpNo + 1), sizeof(aNos));
	 // int *aNos_ = calloc(sizeof(int) * (inpNo + 1), sizeof(aNos));

	 free(aNos);

	 // printf("try mem");
	 int no[] = { 1, 6, 10 };
	 char *q[3];
	 // char *p = malloc(3 * sizeof(char));
	 // char *p = "string";
	 char p[] = "string";
	 printf("Str :%12.3s: \n",  p); // 12 chars before and print 3 chars
	 printf("Inttt :%d: \n",  atoi(p));

	 char *a = p;
	 *(p + 1) = 'a';
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
		  printf("No is %d\n", i);
	 }

	 // stores in heap, can be freed or ml
	 char *t = malloc(8);
	 strcpy(t, "aaa");
	 printf("%s \n", t);
	 printf("%d \n", &t);
	 free(t);
	 printf("%d \n", &t);
	 printf("%s", t);
	 t = "New str";
	 printf("%s", t);
}
