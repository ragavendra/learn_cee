
import java.util.LinkedList;
import java.util.List;

// Q asked in Amazon prep to find nos in btree path and sum of it.
// Using bottom up approach from last to root
// Other way is root to bottom, using DFS to stack
public class HeapSum {

    public static List<Integer> resList = new LinkedList();

    public static void PrintOutput(List<Integer> lis) {
		for(Integer ele: lis){
			System.out.println(ele);
		}
	}

    public static void main(String[] args) {
        
        int arr[] = { 16, 28, 34, 57, 71, 85, 93 };
        int lastPos = arr.length - 1;
        // resList.add(arr[lastPos]);

        int f = -13/2;
        System.out.println("f is " + f);
        // System.out.println("arr is " + arr[10]);

        // traverse from last till first. Complexity - nlogn
        for (int i = lastPos; i > 0; i--) {

            resList.add(arr[lastPos]);
            int p = lastPos;
            do {
                // p = (k - 1)/ 2
                p = (p - 1) / 2;
                resList.add(arr[p]);
                // lastPos = p;
            } while (p > 0);

            // add 0 as separator
            resList.add(0);

            lastPos--;

            // if child exists, stop
            if ((2 * lastPos) + 1 >= arr.length) {
            } else {
                break;
            }
        }

        PrintOutput(resList);
        String str = "";
        int in = 0;
        
        String[] strArr = new String[resList.size()];
        int no = 0;

        // concat eles, complexity is n
        for (Integer elem : resList) {
            if(elem == 0) {
                strArr[in++] = str;
                no = no + Integer.parseInt(str);
                str = "";
                continue;
            }

            str = str + elem.toString();
        }
        System.out.println(no);

        /* Below is for display only */
        int res = 0;

        // conv and sum, complexity is n
        for (int i = 0; i < strArr.length; i++) {
            if(strArr[i] == null)
                break;

            res = res + Integer.parseInt(strArr[i]);
            System.out.println(strArr[i]);
        }

        // Total complexity - (n+nlogn)
        // Space complexity - n+n -> (~2n)
        // Space complexity - n -> (n) . strArr is not needed but there for display/ debug only.
        // Time complexity can be made to nlogn
        System.out.println(res);


    }
}
