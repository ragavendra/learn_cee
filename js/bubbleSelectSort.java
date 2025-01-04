
public class bubbleSelectSort {

    /*
     * a. Pass 1 - Compare each ele with next and swap if less than it.
     * b. Now, last position should be the greatest, ignore that pos and repeat a
     * c. Once, no swap in a loop, the arr is sorted
     */
    // O(N*N) - b.c. and w.c.
    // Recalling, analyzing the steps before implementation is key.
    public static void bubbleSort(int[] args) {

        boolean sorted = false;
        int lastPos = args.length - 1;

        while (!sorted) { 

            // assume sorted before entering the loop
            sorted = true;

            for (int i = 0; i < lastPos; i++) {

                // if none goes here means arr is sorted
                // else loop or pass again
                if(args[i] > args[i + 1]) {
                    sorted = false;
                    int temp = args[i + 1];
                    args[i + 1] = args[i];
                    args[i] = temp;
                }
                // System.out.println("Steps " + ++step);
            }

            lastPos--;
        }
    }

    /*
     * a. Step for each position say first.
     * b. Compare with first pos, if less, then note the position
     * c. After this loop, swap with index with the noted pos
     * d. Start from a for next position till sencond last
     */
    // O(N*N / 2) --> O(N*N) - b.c. and w.c.
    public static void selectionSort(int[] args) {
        // index to be maintained
        int lowestValueIndex;
        for (int i = 0; i < args.length - 1; i++) {
            lowestValueIndex = i;

            // identify lowest ele compared to first
            for (int j = i + 1; j < args.length; j++) {
                if(args[i] > args[j]) {
                    lowestValueIndex = j;
               }
            }

            // swap if identified
            if(lowestValueIndex != i) {
                int temp = args[lowestValueIndex];
                args[lowestValueIndex] = args[i];
                args[i] = temp;
            }
        }
    }

    public static void main(String[] args) {

        // int arr[] = { 24, 42, 12, 15, 39 };
        int arr[] = {75, 42, 24, 15, 8};
        // bubbleSort(arr);
        selectionSort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(" " + arr[i]);
        }

    }
}
