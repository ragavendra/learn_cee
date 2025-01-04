import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;

// Java program to Search a sorted array using Binary search
// For heap creation, no use of Node class
public class btreeSrch {

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

    public static int btreeSrch(int[] arr, int srchNo) {
		int lowerBound = 0, mid;
		int upperBound = arr.length - 1;

		Arrays.parallelSort(arr);
		PriorityQueue<Integer> pq = new PriorityQueue();

		while (upperBound >= lowerBound) { 
			// mid = (upperBound + lowerBound)/2;
			mid = lowerBound + (upperBound - lowerBound)/2;

			if(arr[mid] == srchNo)
				return mid;
			else if(srchNo > arr[mid])
				lowerBound = mid + 1;
			else if(srchNo < arr[mid])
				upperBound = mid - 1;
			
		}

		return -1;
	}

    public static void main(String[] args) {

		// [10, 11, 8, 7, 6 ,5 , 4, 3, 2, 1]
		int[] arr = { 10, 15, 17, 19, 24, 37 };
		int srchNo = 37;
		int position = btreeSrch(arr, srchNo);

		if(position >= 0)
			System.out.println("Element " + srchNo + " found at " + position);
		else
			System.out.println("Element " + srchNo + " not found.");

    }
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
