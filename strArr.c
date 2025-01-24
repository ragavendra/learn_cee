#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>
#include	<math.h>
#include	<string.h>
#include <stdbool.h>
#define PI 22.0e6/7.0e6
#define OOPS "This is %d"
#define _PI acos(-1.0)

union a {
	int b;
};

int *someMetho(int **x, char *, union a *);

int *someMethod_(){
	int *c;
	return c;
}

union a someMethod(int no){
	union a c;
	return c;
}

void * somePtrMeth(int * one, float * two, char *arr) {
// void somePtrMeth(int * one, float * two, char arr[]) {
	++*one;
	--*two;
	printf("\nOne and two and arr are %d and %f and %s\n", *one, *two, arr);
	return arr;
}

void swap(int *const a, int *const b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void square(int *no){
	printf("\nSquare of no is %d", *no * *no);
}

int main(int count, char *vector[]){
	someMethod(3);
	// int a = 0;

	{
		// int a = 3;
		long double pi = 22.0e7/7.0e7;
		printf("Value of pi is calculated %g and  math const %g\n", PI, M_PI);
	}


	// char arr[] = { "This is a string" };
	// char arr2[] = "This is a string";
	char arr3[3] = "asd";
	const char arr6[] = "asd is %d";
	printf("\narr is %s and %c\n", arr3, arr3[2]);
	// fgets();

	char arr4[100];
	// arr4 = "sfsf";
	char one_[] = "sample str | one";
	char const *one = one_; // only *one is const and cannot be changed, but one and val var one_ can be
	const int ne_ = 4;
	int *const ne = &ne_; // only ne stored value (addr) cannot be changed
	int nee = 7;
	// ne = &nee; // not poss
	// ne_ = 3;
	printf("\nptr *ne is %d", *ne);
	char tw[30] = "sfd ";
	char *two = "sample str two 2.344j";
	const int some;

	one = tw;
	// char *two = &tw[0];
	// strncat(tw, one, sizeof(tw) - 1);
	strncat(tw, one, strlen(one));
	// strcpy(tw, one);
	printf("\nStr tw now %s\n", tw);
	printf("strcmp tw and one is now %d\n", strcmp(tw, one));
	printf("oe is in tw %s\n", strstr(tw, "oe")); // index of searched str or null
	printf("z is in tw %s\n", strchr(tw, 'z'));
	printf("| tok in tw %s\n", strtok(tw, "|")); // space, comma and period
	printf("| tok in tw %s\n", strtok(tw, "|")); // call many times till NULL to get each str
	printf("atol is %ld\n", atol("2"));
	printf("atof is %f\n", atof("2.6"));
	printf("atoll is %lld\n", atoll("2.6"));
	printf("strcmp is %d\n", strcmp(tw, one));
	char *dou = "3.29";
	printf("strtod is %g\n", strtod(dou, &two));
	printf("strcasecmp is %d\n", strcasecmp(tw, one)); // case insensitive comparison
	// strcmpcase();

	/*
	// two or three steps 
	a. declare pointer and assign NULL, 
	b. assign address of var or anoter ptr and c. assign value (optional)
	*/
	// scanf("%s", arr4);
	// int * poi = NULL;
	int no = 3;
	// int *noo = 37;
	// int *poi = &no;
	int *poi = &no;
	// poi = &no;
	int *poi2 = poi;
	// *poi = 4;
	// printf("poi value is %d its address is %p or %p \n", *poi, &poi, (void *)&poi);
	printf("poi value is %d its vals address is %p and its address is %p and size is %d\n", *poi, poi, (void*)&poi, (int) sizeof(poi)); // 4 bytes int on 32 bit compiler and 8 bytes on 64 bit compiler
	// printf("poi value is %d its address %p \n", *poi, (void*)poi);
	float *fl = NULL;
	float fval = 3.242;
	fl = &fval;
	*fl = 8.324;

	// void ptrs
	int d = 7;
	float f = 8.34;
	char c = 'e';
	void * pt = NULL;
	pt = &d;
	printf("\npt is %d", *(int *)pt);
	pt = &f;
	printf("\npt is %f", *(float *)pt);
	pt = &c;
	printf("\npt is %c", *(char *)pt);

	int inarr[] = {0, 3, 7, 8};
	// int *inar = inarr;
	int *inar = NULL;
	inar = inarr; // or like below
	inar = &inarr[0];

	if(inarr[3] == *(inarr + 3))
		printf("\nBoth refer to same val");

	swap(&d, &no);
	square(&d);
	printf("\nd is now %d and no is %d", d, no);
	printf("\nvoid * size is uns long %d", sizeof(void *));
	printf("\nuns long size %d", sizeof(unsigned long));
	int a = 15;
	void *ptr = (int *)&a;
	printf("\n%d", *(int *)ptr);
	// printf("%d", *ptr);

	int b[5] = {1, 2, 3, 4, 5};
	int *p = b;
	printf("\n%d\t%d\t%d\t%d\t", *p, b[0], b, p);

	printf("b[3] is %d", *(b+3));
	p++; // will now pt to p[1]

	char *str = (char *)somePtrMeth(poi,fl, arr3); 
	int sstr = *(int *)somePtrMeth(poi,fl, arr3); 

	// arr3 [0] = 'c';

	{
		// const int PI = 3;
		int a[2][3] = {1, 2, 3, 4, 5};
		// int a[2][3] = {{1, 2, 3}, 
		//			    {4, 5, 6}};
		int i = 0, j = 0;
		int *k = &i;

		for (i = 0; i < 2; i++){
			for (j = 0; j < 3; j++)
				printf("%d ", a[i][j]);
			printf("Finish row %d\n", i);
		}

		printf("\n");
	}

	{
		int k;

		for (k = -3; k < -5; k++)
			printf("Hello\n");
	}

	{
		double k = 0;

		for (k = 0.0; k < 3.0; k++);
		printf("%lf\n", k);
	}

	{
		int x = 0;

		if (x++)
			printf("true\n");
		else if (x == 1)
			printf("false\n");
	}

	{
		int x = 1, y = 0, z = 5;
		int a = x && y && z++;

		// z is not printed - short circuit evaluation - as bool val is already known before evaluation - 0 && ? = 0
		printf("\nZ is %d and A is %d", z, z);
	}

	int x;

	{
		if (x)
			printf("\nhi");
		else
			printf("\nhow are you, x is %d", x);
	}

	{
		/*
		   int a = 3;
		   double c = 3.4e+4; // 3.4 * 10 x to pow of 4
		   _Bool _val = false; // C89 has this type
		   bool val = false;

		// short, long and unsigned are adjectives with int float
		// long float sss;
		long long erwd = 24234234L;
		long long _erwd = 24234234l;
		*/
		double c = 3.4e+4; // 3.4 * 10 x to pow of 4
		printf("\nc is  %e and %g", c, c);
		float num = 3.325423;
		printf("\nnum is %7.3f and %f", num, num);

	}

	enum priColor { Red, Pink, Grey };
	// enum priColor one, two = Pink; // int val corresp in list start from 0, which is 1 here
	enum dire { left , up, right=1, down }; // left is 0, 1, 11 and 12
	enum dire up_ = up;
	// char ascii = 65; // or 'c' or '\n' \oOO \xhh \v vert tab
	printf("\nenum up is now %u and %u and right %u", up_, up, right); // up and right have same value 1

	if(strcpy(arr3, "hi")){
		printf("\narr3 is now %s", arr3);
		// printf("\narr3 is now %d", someMethod 2);
	}

	// gets(arr3); // takes space in string unlike scanf
	puts(arr3);
	// strlen(arr3); length of string and not the \o term

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
