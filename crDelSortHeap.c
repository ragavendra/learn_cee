#include <stdio.h>
#define ARRSIZE 10

	/*
    public static LinkedList<Integer> outPut = new LinkedList();
    public static LinkedList<Integer> sortedList = new LinkedList();

	// min heapify
    public static void heapifyBelow(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < outPut.size() && outPut.get(leftChild) < outPut.get(index)) {
            int temp = outPut.get(leftChild);
            outPut.set(leftChild, outPut.get(index));
            outPut.set(index, temp);
            heapifyBelow(leftChild);
        }

        if (rightChild < outPut.size() && outPut.get(rightChild) < outPut.get(index)) {
            int temp = outPut.get(rightChild);
            outPut.set(rightChild, outPut.get(index));
            outPut.set(index, temp);
            heapifyBelow(rightChild);
        }
    }

    public static void RemoveEle(int pos) {
		// remove from pos
        int last = outPut.removeLast();

        // update pos ele to last
        outPut.set(pos, last);

		// parse inside the heap or below it from that pos
		heapifyBelow(pos);
	}
	*/

    void PrintOutput(int lis[]) {
		for(int i = 0; i < ARRSIZE; i++)
			printf("%d ", lis[i]);
		printf("\n");
	}

	int output[ARRSIZE] = {};
	int sorted[ARRSIZE] = {};

	void swap(int * it1, int * it2){
		int temp = *it1;
		*it1 = *it2;
		*it2 = temp;
	}

    void insertEle(int ele, int lastIndex) {

		// output[ARRSIZE - 1] = ele;
		output[lastIndex] = ele;

        // int lastIndex = ARRSIZE - 1;
        int parIndex;

        while (lastIndex != 0) {

			// k, 2k+1, 2k+2; 2k = l-1; k = (l-1)/2; l = 10, k = 4
            parIndex = (lastIndex - 1) / 2;

			// if parent > child, swap with parent - min heap
			if(output[parIndex] > ele)
				swap(&output[parIndex], &output[lastIndex]);

			// Now loop till root is reached or par index is 0
			// System.out.println("Value " + value + " Curr ind is " + curIndex + " Par ind is " + parentIndex);
			lastIndex = parIndex;
		}
    }

	// Heap sort
 	/*
	 * Heap is mostly sorted with root having least in min heap
	 * a. Pop the root to a new list.
	 * b. Swap the last ele to root and heapify.
	 * c. Repeat a till 1 or last ele. Append it after the loop
	 */
    int main() {

		int arr[] = { 85, 34, 16, 71, 57, 93, 28, 10, 24, 74 };
		// int arr[] =  {10, 11, 8, 7, 6 ,5 , 4, 3, 2, 1};
		// int len = sizeof(arr)/sizeof(arr[0]);

		for (int i = 0; i < ARRSIZE; i++) {
            insertEle(arr[i], i);
        }

		PrintOutput(output);

		int l = ARRSIZE - 1;
		int i = 0;

		// need to fix this
		while(l > 0) {
            // root is lowest, so swap with last or pop it to sor arr
			sorted[i] = output[0];
			i++;

            // set last ele to root; and remove it
			output[0] = output[l];
			// output[l] = 0;

			l--;

			// int ar[ARRSIZE] = output[l - 1];
			// try use another arr
			for(int i = 0; i < l; i++)
				insertEle(output[i], i);

		}

		sorted[ARRSIZE - 1] = output[ARRSIZE - 1];

		PrintOutput(sorted);
			/* 

        while (outPut.size() > 1) {

            // root is lowest, so swap with last or pop it to sor arr
            sortedList.add(outPut.get(0));

            // set last ele to root and remove it
            outPut.set(0, outPut.removeLast());

            LinkedList<Integer> tempList = (LinkedList<Integer>) outPut.clone();
            outPut.clear();

            // heapify or insert as an heap
            for (Integer elem : tempList) {
                insertEle(elem);
            }

        }
        }

		// add last or root ele
        sortedList.add(outPut.remove());

        PrintOutput(sortedList);
*/
    }

