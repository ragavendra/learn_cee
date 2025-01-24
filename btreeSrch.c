#define NDEBUG
#include <stdio.h>
#include <assert.h>

int btreeSrch(int [], int);

int main() {

	// should be sorted
	int arr[] = { 10, 15, 17, 19, 24, 37 };
	printf("len of arr is %d\n", sizeof(arr));
	assert(2 == 1);

	int srchNo = 37;
	int position = btreeSrch(arr, srchNo);

	if(position >= 0)
		printf("Element %d found at %d", srchNo, position);
	else
		printf("Element %d not found", srchNo);

}

int btreeSrch(int arr[], int no) {
	int lb = 0, mid;
	int ub = sizeof(arr)/ sizeof(arr[0]); 
	printf("len of arr is %d\n", sizeof(arr[0]));
	ub = 6;

	while(ub >= lb) {
		mid = lb + (ub - lb)/2;

		if(arr[mid] == no)
			return mid;
		else if(no > arr[mid])
			lb = mid + 1;
		else
			ub = mid - 1;
	} 

	return -1;
}
