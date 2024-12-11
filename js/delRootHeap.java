import java.util.LinkedList;

// Java program to Del from heap position
public class delRootHeap {

    public static LinkedList<Integer> outPut = new LinkedList();
    // ([ 1, 2, 1, 6, 3, 4, 3 ]);

    public static void delRootEle() {

        int last = outPut.removeLast();

        // update first or root to last
        outPut.set(0, last);

		heapify(0);

        int nodePos = 0;

		/*
		 * 
        while (nodePos != 0) {
            int lefPos = (2 * nodePos) + 1;
            int righPos = (2 * nodePos) + 2;
            int leftChild = outPut.get(lefPos);
            int rightChild = outPut.get(righPos);

            // if node more than left, swap
            if (outPut.get(nodePos) > leftChild) {
                int temp = outPut.get(nodePos);
                outPut.set(nodePos, leftChild);
                outPut.set(lefPos, temp);
                nodePos = lefPos;

                // else if node more than right, swap
            } else if (outPut.get(nodePos) > rightChild) {
                int temp = outPut.get(nodePos);
                outPut.set(nodePos, rightChild);
                outPut.set(righPos, temp);
                nodePos = righPos;
            }
        }
		 */
    }

	// min heapify
    public static void heapify(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // System.out.println("L " + outPut.get(leftChild) + " < " + outPut.get(index));
        if (leftChild < outPut.size() && outPut.get(leftChild) < outPut.get(index)) {
			// System.out.println("L " + outPut.get(leftChild) + " < " + outPut.get(index));
            int temp = outPut.get(leftChild);
            outPut.set(leftChild, outPut.get(index));
            outPut.set(index, temp);
            heapify(leftChild);
        }

        // System.out.println("L " + outPut.get(rightChild) + " < " + outPut.get(index));
        if (rightChild < outPut.size() && outPut.get(rightChild) < outPut.get(index)) {
			// System.out.println("L " + outPut.get(rightChild) + " < " + outPut.get(index));
            int temp = outPut.get(rightChild);
            outPut.set(rightChild, outPut.get(index));
            outPut.set(index, temp);
            heapify(rightChild);
        }
    }
    public static void PrintOutput() {
		for(Integer ele: outPut){
			System.out.println(ele);
		}
	}

    public static void RemoveEle(int pos) {
		// remove from pos
        int last = outPut.removeLast();

        // update pos ele to last
        outPut.set(pos, last);

		// parse inside the heap
		heapify(pos);

		// ArrayList<Integer> arr = new ArrayList();
		// arr.remove(2);
	}

	public static Integer[] arrr;

    public static void main(String[] args) {

		// [10, 11, 8, 7, 6 ,5 , 4, 3, 2, 1]
		Integer[] arr = { 1, 2, 1, 6, 3, 4, 3 };
		// Integer[] arr = { 85, 34, 16, 71, 57, 93, 28 };
		// Integer[] arr = { 93, 57, 34, 85, 71 };
		// Integer[] arr = { 85, 71, 57, 93 };
		// Integer[] arr = { 93, 85, 71 };
		// Integer[] arr = { 2, 3, 4, 6, 1 };

		// Scanner scanner = new Scanner(System.in);

		// fill list
		for (Integer i = 0; i < arr.length; i++) {
			outPut.add(arr[i]);
        }

		RemoveEle(0);
		RemoveEle(1);
		// heapify(0);

        PrintOutput();
    }

	/*
	 * 
    void deleteFromHeap(int index) {
        System.out.println("Deleting the element " + outPut.get(index));
        int lastIndex = outPut.size() - 1;
        int temp = outPut.get(index);
        outPut.set(index, outPut.get(lastIndex));
        outPut.set(lastIndex, temp);
        outPut.remove(lastIndex);
        heapify(index);
    }
	 */
}