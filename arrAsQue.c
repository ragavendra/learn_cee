//  I  loop only for reorder if last
// not working

#include <stdio.h>
#define LEN 3

int arr[LEN] = {};
int * startPos = arr;
int head = 0; // last ele of arr
int tail = 0;
void push(int it);
void pop();
void disp();
void exit();

int main() {
	
	int ch, it;
	printf("Stack %d\n", ch);

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

void push(int it) {
	if(tail == 0 && head == LEN) {
	// if(*arr[LEN - 1] != 0) {
		printf("Que is full, try pop()\n");
		return;
	}

	// *(arr + head) = &it;
	if(head < LEN)
		arr[head++] = it;
	else {
		printf("Head is same as len?\n");
		if(tail != 0) {

			// loop to move eles to beg of arr
			do {
				--tail;
				arr[tail] = arr[tail + 1];
				head--;

			} while (tail > 0);
			// may be fix here
			// arr[head] = arr[head+1];
			arr[head++] = it;

		}
	}
}

void pop() {
	if(head == tail || tail == LEN) {
		printf("Que is empty, nothing to pop\n");
		head = tail = 0;
		return;
	}

	arr[tail++] = 0;
//
//	// add 0 to head
//	if(head > 0) {
//		head--;
//		*(arr + head) = 0;
//		// arr[head - 1] = 0;
//	}
//	else {
//		printf("Pop first ele of arr\n");
//		*(arr + head) = 0;
//	}
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


