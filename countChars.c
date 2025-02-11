
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define peach int *

typedef long * lltype;
typedef int (*ptr_to_func)(void);

enum day { mon, tue, wed, thu, fri, sat, sun };

struct date {
	int month;
	enum day day;
	int year;
	char *some;
};

struct empl {
	char name[10];
	struct date hiredate;
	float salary;
};

// linked list
struct node {
	int data;
	struct node *next;
};

// double linked list
struct dlnode {
	int data;
	struct node *prev;
	struct node *next;
};

int countChars(const char *ptr){
	// int res = 0;	
	char *pt = NULL;
	pt = ptr;

	while(*pt){
		pt++;
		// res++;
	}

	return pt - ptr;

	// return res;
}

int main(int ct, char *strr[]){
	printf("Pgm to find string length");
	printf("Length is - %d\n", countChars("sample stsdf fsdr"));

	// char *str = "some onesdf ";
	char str[13] = "some onesdf ";
	char *str2 = "some twosdf ";
	strcpy(str, str2);
	printf("Str is now %s\n", str);

	/*
	printf("Enter empl details - Name, Hiredate dd mm yyyy and Salary\n");
	struct empl some;
	scanf("%s\n", some.name); 
	scanf("%d %d %d\n", &some.hiredate.day, &some.hiredate.month, &some.hiredate.year); 
	scanf("%f", &some.salary); 
	// scanf("%s %d %f", some.name, &some.hiredate, &some.salary); 
	printf("Empl details - %s, %d and %f\n", some.name, some.hiredate.year, some.salary);
	// strcpy(some.name, "Name Here");
	*/

	long l = 10L;
	lltype ab;
	int *cc = NULL;
	// *cc = 1; not possible assignment. First needs to be assigned to an address
	cc = &ct;
	
	ab = &l;
	char * ptt;
	int * pt;
	// pt = (ptr_to_func) ptt; check this
//
//	// sample func pointer
//	int (*func_countChars)(const char *);
//	func_countChars = &countChars;
//	func_countChars("sdfssf");
//
	peach b, c; // b is pointer but c is not. #define only replaces text

	// this is working
	struct date datePtrr = { 12, tue, 2024, calloc(3, sizeof(char)) };
	// datePtrr.some = "ste here"; //  pblm line as this is stack mem
	printf("Enter txt to store in dyn heap!\n");
	scanf("%s", datePtrr.some);
	free(datePtrr.some);

	struct date birthday;
	birthday.day = tue;
	birthday.year = 2024;
	birthday.month = 12;
	// not sure if I can assign heap mem like this, has to be date *
	// birthday.some = calloc(2, sizeof(char));

	char *soo = calloc(2, sizeof(char));
	birthday.some = soo; //  need to assign char var
	birthday.some = calloc(2, sizeof(char));

	// ptr to struct
	// struct date * datePtr = { 12, 3, 2024, calloc(3, sizeof(char)) };
	struct date * datePtr = &birthday;
	(*datePtr).day = 21; // or
	datePtr->day = 30;

	datePtr->some = "de3"; // stack memory
	printf("dateptr->some is %s\n", datePtr->some);

	// free must succeed to confirm heap memory free
	free(soo); // attempt to call free on non heap object

	// free(&soo); // attempt to call free on non heap object
	// free(so); // not sure why it is giving invalid ptr w/o using so var
	// free(birthday.some); // not sure why it is giving invalid ptr
	printf("Code here!\n");
	datePtr->some = NULL;
	// s_gets(str, 13);

	struct date today = { 2, wed, 2024 };
	struct date tommo = { .day=wed, 2024 };
	// struct date arrDate[10];
	// struct date arrDate[10] = {{1, 8, 2024}, {2, 4, 2024}};
	struct date arrDate[10] = {[3]={1, 8, 2024}, [6]={2, 4, 2024}};
	// arrDate[0] = { .month = 1, .day = 3, .year = 2024 };
	arrDate[0].day = 1;
	arrDate[0].month = 8;
	arrDate[0].year = 2024;

	char *a[] = { "hello", "worlds" };
	printf("arr 0 is %s\n", *a);
	printf("arr 1 is %s\n", *(a+1));

	int size;
	printf("Enter string size - ");
	scanf("%d", &size);
	char *stt = NULL;
	stt = calloc(size, sizeof(char));

	if(stt != NULL){
		printf("Enter a string - ");
		scanf("%s", stt);
		// gets_s(str2, 10);

		printf("Str input is %s\n", stt);
		free(stt);
	}
	 
	{

		int *a;
		a=(int*)malloc(sizeof(int));
		*a=100;
		printf("*a%d\n",*a);
		// free(a);

		a=(int*)malloc(sizeof(int));
		*a=200;
		printf("a%p\n",a);
		*a=200;
		printf("a%d\n",*a);
	}


	int *st = (int *) malloc(sizeof(int) * 3);
	free(st);
	st = NULL; // if not st becomes dangling pointer

	int *dst = calloc(3, sizeof(int)); // intializes as well
	free(dst);
	dst = NULL;

	int *ddst = realloc(st, sizeof(int) * 3); // extend memory
	free(ddst);
	ddst = NULL;
}
