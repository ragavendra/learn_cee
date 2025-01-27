#include <stdio.h>
#define LEN 10

int arr[LEN] = {};
int inde = 0;
void push(int it);
void pop();
void disp();
void exit();

// head is in inde
int main() {
	
	int ch, it;

	do {
		printf("Stack is ready. Press 1 for PUSH, 2 for POP, 3 for DISPLAY and 4 for EXIT\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1: 
				printf("Enter item: ");
				scanf("%d", &it);
				push(it);
				break;
			case 2: pop();
					break;
			case 3: disp();
					break;
			case 4: return 0;
		}
	}while(1);

	// return -1;
}

void push(int it) {
	if(inde == LEN) {
	// if(*arr[LEN - 1] != 0) {
		printf("Stack is full, try pop()\n");
		return;
	}

	// *(arr + inde) = &it;
	arr[inde++] = it;
/* 

	int i;
	do{
		if(*(arr + i) == 0) {
			// *(arr + i) = it;
			*arr[i] = it;
			return;
		}

		i++;
	}while(i < LEN);

*/
}

void pop() {
	if(arr[0] == 0) {
		printf("Stack empty, nothng to pop\n");
		return;
	}

	// add 0 to head
	if(inde > 0) {
		inde--;
		*(arr + inde) = 0;
		// arr[inde - 1] = 0;
	}
	else {
		printf("Pop first ele of arr\n");
		*(arr + inde) = 0;
	}
}

void disp() {
	if(arr[0] == 0) {
		printf("Stack empty, nothng to display\n");
		return;
	}

	for(int i = 0; i < LEN; i++) {
		printf("%d ", *(arr + i));
	}
	
	printf("\n");
}


