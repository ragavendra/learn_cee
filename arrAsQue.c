//  I  loop only for reorder if last
// not working

#include <stdio.h>
#include <assert.h>
#define LEN 3

int arr[LEN] = {};
int * startPos = arr;
int head = 0; // last ele of arr
int tail = 0;
void push(int it);
int pop();
void disp();
void exit();

// check the implementation
void main() {
	push(10);
	push(20);
	assert(pop() == 10);
	push(30);
	push(33);
	// push(34);
//	int res = pop();
//	printf("%d\n", res);
	assert(pop() == 20);
}

int main_() {
	
	int ch, it;
	// printf("Stack %d\n", ch);

	do {
		printf("Que is ready. Press 1 for PUSH, 2 for POP, 3 for DISPLAY and 4 for EXIT\n");
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

void moveToStart(int it){
	int ind = 0;
	for (int i = tail; i < LEN; i++) {
		arr[ind++] = arr[i];
	}
	arr[ind++] = it;
	tail = 0;
	disp();
//	
//	// loop to move eles to beg of arr
//	do {
//		--tail;
//		arr[tail] = arr[tail + 1];
//		head--;
//
//	} while (tail > 0);
//	// may be fix here
	// arr[head] = arr[head+1];
}

void swap(int *a, int *b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

void push(int it) {
	if(tail == 0 && head == LEN) {
		// if(*arr[LEN - 1] != 0) {
		printf("Que is full, try pop()\n");
		return;
	}

	// *(arr + head) = &it;
	if(head < LEN){}
	else { // head == LEN
		printf("Head is same as len?\n");
		if(tail != 0) {
			moveToStart(it);
		}
	}
	arr[head++] = it;
}

int pop() {
	if(head == tail || tail == LEN) {
		printf("Que is empty, nothing to pop\n");
		head = tail = 0;
		return -1;
	}

	int po = arr[tail];

	arr[tail] = 0;
	tail++;

	return po;
}

void disp() {
	if(head == tail) {
		printf("Que is empty, nothng to display\n");
		return;
	}

	for(int i = 0; i < head; i++) {
		printf("%d ", *(arr + i));
	}

	printf("<-- head\n");
}


