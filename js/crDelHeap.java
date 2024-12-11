import java.util.LinkedList;

// Java program to Del from heap position
public class delRootHeap {

    public static LinkedList<Integer> outPut = new LinkedList();
    // ([ 1, 2, 1, 6, 3, 4, 3 ]);

	// min heapify
    public static void heapifyBelow(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // System.out.println("L " + outPut.get(leftChild) + " < " + outPut.get(index));
        if (leftChild < outPut.size() && outPut.get(leftChild) < outPut.get(index)) {
			// System.out.println("L " + outPut.get(leftChild) + " < " + outPut.get(index));
            int temp = outPut.get(leftChild);
            outPut.set(leftChild, outPut.get(index));
            outPut.set(index, temp);
            heapifyBelow(leftChild);
        }

        // System.out.println("L " + outPut.get(rightChild) + " < " + outPut.get(index));
        if (rightChild < outPut.size() && outPut.get(rightChild) < outPut.get(index)) {
			// System.out.println("L " + outPut.get(rightChild) + " < " + outPut.get(index));
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

    public static void PrintOutput() {
		for(Integer ele: outPut){
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

	// Remove ele
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

        PrintOutput();
    }

	// Create Heap/ Heapify
    public static void main(String[] args) {

		Integer[] arr = { 2, 3, 4, 6, 1, 3, 1 };

		for (Integer i = 0; i < arr.length; i++) {
            insertEle(arr[i]);
        }

		PrintOutput();
		/* Exp op 1, 2, 1, 6, 3, 4, 3 */
    }

}