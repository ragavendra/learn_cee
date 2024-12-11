import java.util.LinkedList;

// Java program to Del from heap position
public class crDelSortHeap {

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

    public static void PrintOutput(LinkedList<Integer> lis) {
		for(Integer ele: lis){
			System.out.println(ele);
		}
	}

    public static void insertEle(Integer ele) {

        outPut.add(ele);

        int lastIndex = outPut.size() - 1;
        int parIndex;

        while (lastIndex != 0) {

			// k, 2k+1, 2k+2; 2k = l-1; k = (l-1)/2;
            parIndex = (lastIndex - 1) / 2;

			// if parent > child, swap with parent - min heap
			if(outPut.get(parIndex) > ele) {
				int par = outPut.set(parIndex, ele);
				outPut.set(parIndex, ele);
				outPut.set(lastIndex, par);
			}

			// Now loop till root is reached or par index is 0
			// System.out.println("Value " + value + " Curr ind is " + curIndex + " Par ind is " + parentIndex);
			lastIndex = parIndex;
		}
    }

	// Remove from position
   /*
	 * Heap is mostly sorted with root having least in min heap
	 * a. Pop the element from the position.
	 * b. Swap the last ele to the pos and heapify below nodes.
	 */ 
    public static void main_(String[] args) {

		// [10, 11, 8, 7, 6 ,5 , 4, 3, 2, 1]
		Integer[] arr = { 2, 3, 4, 6, 1, 3, 1 };
		// Integer[] arr = { 1, 2, 1, 6, 3, 4, 3 };
		// Integer[] arr = { 85, 34, 16, 71, 57, 93, 28 };
		// Integer[] arr = { 93, 57, 34, 85, 71 };
		// Integer[] arr = { 85, 71, 57, 93 };
		// Integer[] arr = { 93, 85, 71 };

		// fill list
		for (Integer i = 0; i < arr.length; i++) {
			outPut.add(arr[i]);
        }

		RemoveEle(0);
		RemoveEle(1);
		// heapifyBelow(0);

        PrintOutput(outPut);
    }

	// Create min Heap/ Heapify
    /*
	 * Array as an Heap has k, 2k+1 and 2k+2 positions. Insertion happens from last pos or end.
     * a. Insert ele to list.
     * b. Get last pos of list, and when it is > 0
     * c. If new ele is less than parent, swap it, recurse parent ele, par = k-1/2 
	 */ 
    public static void mainn(String[] args) {

		Integer[] arr = { 2, 3, 4, 6, 1, 3, 1 };

		for (Integer i = 0; i < arr.length; i++) {
            insertEle(arr[i]);
        }

		PrintOutput(outPut);
		/* Exp op 1, 2, 1, 6, 3, 4, 3 */
    }

	// Heap sort
 	/*
	 * Heap is mostly sorted with root having least in min heap
	 * a. Pop the root to a new list.
	 * b. Swap the last ele to root and heapify.
	 * c. Repeat a till 1 or last ele. Append it after the loop
	 */
    public static void main(String[] args) {

		// Integer[] arr = { 2, 3, 4, 6, 1, 3, 1 };
		Integer[] arr = { 85, 34, 16, 71, 57, 93, 28 };

		for (Integer i = 0; i < arr.length; i++) {
            insertEle(arr[i]);
        }

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

		// add last or root ele
        sortedList.add(outPut.remove());

        PrintOutput(sortedList);
    }

}