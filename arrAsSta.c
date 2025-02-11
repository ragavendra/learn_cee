//  I don't loop except for display

#include <stdio.h>
#include <assert.h>
#define LEN 10

int arr[LEN] = {};
int inde = 0;
void push(int it);
int pop();
void disp();
void exit();

// check the implementation
void main() {
	push(10);
	push(20);
	assert(pop() == 20);
	push(30);
	assert(pop() == 30);
	// assert(1 == 3);
}


// head is in inde
int _main() {
	
	int ch, it;
	printf("Stack %d\n", ch);

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
}

int pop() {
	if(arr[0] == 0) {
		printf("Stack empty, nothng to pop\n");
		return -1;
	}

	int it;

	// add 0 to head
	if(inde > 0) {
		inde--;
		it = arr[inde];
		*(arr + inde) = 0;
		// arr[inde - 1] = 0;
	}
	else {
		printf("Pop first ele of arr\n");
		it = arr[inde];
		*(arr + inde) = 0;
	}

	return it;
}

void disp() {
	if(arr[0] == 0) {
		printf("Stack empty, nothng to display\n");
		return;
	}

	for(int i = 0; i < inde; i++) {
		printf("%d ", *(arr + i));
	}
	
	printf("<-- head\n");
}


