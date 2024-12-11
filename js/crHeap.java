import java.util.LinkedList;

// Java program to Create min heap
// For heap creation, no use of Node class
public class crHeap {

	public static LinkedList<Integer> outPut = new LinkedList();

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

    public static void PrintOutput() {
		for(Integer ele: outPut){
			System.out.println(ele);
		}
	}

    public static void main(String[] args) {

		// [10, 11, 8, 7, 6 ,5 , 4, 3, 2, 1]
		// Integer[] arr = { 2, 3, 4, 6, 1, 3, 1 };
		// Integer[] arr = { 8, 7, 6, 5, 4, 3, 2, 1 };
		// Integer[] arr = { 28, 57, 16, 85, 34, 93, 12, 71 };
		// Integer[] arr = { 85, 34, 16, 71, 57, 93, 28 };
		Integer[] arr = { 2, 3, 4, 6, 1 };

		for (Integer i = 0; i < arr.length; i++) {
            insertEle(arr[i]);
        }

		PrintOutput();
    }

	/*
	 * Exp op
1
2
1
6
3
4
3
	 */

	/* Not working 
	// I am cutting short of not comparing till root ele by this?
    public static void insertEle_(Integer ele) {

        int last = outPut.size() - 1;

		if(outPut.size() == 0) {
            outPut.add(ele);
			return;
		}

		if(outPut.size() == 1) {
			if(outPut.getLast() <= ele) {
				outPut.add(ele);
			}
			else {
			//if(outPut.getLast() <= ele) {}
				// add parent to last
				outPut.add(outPut.get(0));

				// update parent to ele
				outPut.set(0, ele);
			}
			return;
		}

        int parIndex;
        while (last != 0) {

            parIndex = (last - 1) / 2;
			
			// if ele less than parent, swap
            // if (ele < outPut.get(parIndex)) {
            if (outPut.get(parIndex) > ele) {
                int par = outPut.get(parIndex);
                outPut.set(parIndex, ele);
                outPut.add(par);
            } else {
                outPut.add(ele);
            }
            last = parIndex;
        }
    }

	Output
1
1
3
1
3
2
4
3
6
1
1

	 */

}