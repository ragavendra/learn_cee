/* 
Assignment to capture and show product deets.
*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define NAMELEN 10

struct item {
	char * itemName;
	int qty;
	float price;
	float amount;
};

void readItem(struct item * itmPtr){
	printf("Please enter product name, price and qty\n");
	scanf("%s %f %d", itmPtr->itemName, &itmPtr->price, &itmPtr->qty);
	itmPtr->amount = itmPtr->price * itmPtr->qty;
}

void printItem(const struct item * itmPtr){
	printf("Product name %s, price %f, quantity %d and amount %f\n", itmPtr->itemName, itmPtr->price, itmPtr->qty, itmPtr->amount);
}

int main(){
	struct item *itmPtr;
	itmPtr->itemName = malloc(sizeof(char) * NAMELEN);

	readItem(itmPtr);

	printItem(itmPtr);
	free(itmPtr->itemName);
	itmPtr->itemName = NULL;

	return 0;
}


struct temp
{
	int a;
} s;


void func(struct temp s)
{
	s.a = 10;
	printf("%d\t", s.a);
}

int imain(){
	long c = -1;

	// void ptrd
	void * po = &c; // no incompatible pointer type warning for void *
	// char * cc = &c;
	char ch = 'c';
	po = &ch;
	long l = *(long *)po; // assigning ch value as long - lol

	void * p = (void *)c;

	printf("Void * is now %ld", (unsigned long) p);

	void (*fp_func)(struct temp);
	// fp_func = &func;
}

int main_3(){
	int mchar, tell, counter;
	FILE * f = fopen("samp.txt", "r");

	// seek to end
	if(fseek(f, 0, SEEK_END) != 0){
		printf("Unable to seek to end\n");
		return -1;
	}

	do {
		mchar = fgetc(f);
		tell = ftell(f);
		printf("%c", mchar);
		fseek(f, counter, SEEK_END);
		--counter;
		// f = stdout;
	} while(tell != 1);

	if(fclose(f) == EOF) {
		printf("File could not be closed.\n");
		return -1;
	}
}

int main_2(){
	int mchar;
	FILE * f = fopen("samp.txt", "r");
	FILE * ft = fopen("temp", "w+");
	do {
		// fsetc();
		mchar = fgetc(f);
		// fputc(2, f);
		// alphabets ascii values are 33 to 100
		// sub from 32 to conv to lower
		// fputs("Str to be written %d\n", f); // or \0 in fputc
		// fseek(f, 0, SEEK_END);
		int tell = ftell(f);
		printf("Pos in file %d\n", tell);

	/* 
		fgetpos(f, &here); 
		fsetpos(f, &here); 
		// fseek(f, 3, SEEK_SET); move to 3 and set. SEEK_CUR and SEEK_SET
	*/

		if(islower(mchar))
			mchar = mchar - 32;

		fputc(mchar, ft);

	} while(mchar != EOF);

	rename("temp", "samp.txt");

	if(fclose(f) == EOF) {
		printf("File could not be closed.\n");
		return -1;
	}

	if(fclose(ft) == EOF) {
		printf("File could not be closed.\n");
		return -1;
	}
}

int main_()
{
	/* 
	   func(s);
	   printf("%d\t", s.a);
	   */

	// FILE * f = fopen("sample.txt", "r");
	FILE * f = fopen("samp.txt", "a+");

	if(f == NULL) {
		printf("File could not be opened.\n");
		return -1;
	}
	// rename("", "");
	// remove("");

	int mchar;

	// rewind(f); set pos to 0
	char * ch;
	int ctr;

	// fputs("Str to be written %d\n", f); // or \0 in fputc
	fprintf(f, "Str to be written %d\n and %s and %s \n", 1, "one", "two");
	/* 
	   do {
	// fsetc();
	mchar = fgetc(f);
	// fputc(2, f);
	// alphabets ascii values are 33 to 100
	// fputs("Str to be written %d\n", f); // or \0 in fputc

	if(mchar == '\n')
	ctr++;
	} while(mchar != EOF);
	// } while(*ch != EOF);

*/
	printf("Total lines is %d.\n", ctr);

	// int year;
	// char str1[10];
	// fscanf(f, "%s %s %s", str1, str2, str3, &year);

	if(fclose(f) == EOF) {
		printf("File could not be closed.\n");
		return -1;
	}



}
