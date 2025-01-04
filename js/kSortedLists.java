
import java.util.Arrays;
import java.util.LinkedList;
import java.util.random.RandomGenerator;


/**
 * Definition for singly-linked list.
 */
 class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }

public class kSortedLists {

    public static LinkedList<Integer> res = new LinkedList();
    public static LinkedList<Integer> sortedRes = new LinkedList();
    public static LinkedList<Boolean> res_ = new LinkedList();

    public static ListNode mergeKLists(ListNode[] lists) {

        java.util.Queue queue = new java.util.PriorityQueue<ListNode>();
        queue.remove();

        res.isEmpty();
        Arrays.copyOf(res.toArray(), res.size() - 1);


        int lsLen = lists.length;

        if(lists.length == 0)
            return null;

        // create min heap
        for (int i = 0; i < lsLen; i++) {

            if(lists[i] == null)
                break;

            // loop for each ListNode
            while (lists[i] != null) {
                // System.out.println("Inserting " + lists[i].val);
                heapIns(lists[i].val);
                lists[i] = lists[i].next;
            }
        }

        // tbd - sort heap
        heapSort();
        ListNode result = new ListNode(sortedRes.removeLast());

        // print heap
        PrintOutput(sortedRes);

        /*
         * 
        for (Integer elem : sortedRes) {
            System.out.println("Res is " + elem);
       }
         */

       int len = sortedRes.size();

        for (int i = 0; i < len; i++) {
             // if(result == null)
                // result = new ListNode(sortedRes.removeLast());
            // System.out.println("Peek list " + sortedRes.peekLast());
            result = new ListNode(sortedRes.removeLast(), result);
        }

        /*
         * 
        for (Integer elem : sortedRes) {
            
        }
         */
         do { 
            System.out.println("Node list " + result.val);
            result = result.next;
        }
        while (result.next != null);
        /*
         * 
        ListNode temp = result;

        for (Integer elem : res) {
            temp.val = elem;
            temp = temp.next;
        }

        ListNode temp = result;
        while (temp.next != null) {
            System.out.println(temp.val);
        }
         */

        return result;
    }

    public static void PrintOutput(LinkedList<Integer> lis) {
		for(Integer ele: lis){
			System.out.println(ele);
		}
	}

    public static void heapSort() {

        // System.out.println("res size " + res.size());
        /*
         * 
        PrintOutput(res);
        System.out.println("res size ");*/

        while (res.size() > 1) {

            // add first to sortedList
            sortedRes.add(res.getFirst());

            // add last to root
            res.set(0, res.removeLast());

            // heapify(parPos);
            LinkedList<Integer> linkedList = (LinkedList<Integer>) res.clone();
            res.clear();

            for(Integer item: linkedList) {
                heapIns(item);
            }

        }

        sortedRes.add(res.remove());
        // System.out.println("res size " + res.size());
        // System.out.println("sorted res size " + sortedRes.size());
    }

    // heapify
    public static void heapify(int parPos) {

        int leftPos = (2 * parPos) + 1;
        int rightPos = (2 * parPos) + 2;

        if(leftPos < res.size() && res.get(leftPos) < res.get(parPos)) {
            int temp = res.get(parPos);
            res.set(parPos, res.get(leftPos));
            res.set(leftPos, temp);
            heapify(leftPos);
        }

        if(rightPos < res.size() && res.get(rightPos) < res.get(parPos)) {
            int temp = res.get(parPos);
            res.set(parPos, res.get(rightPos));
            res.set(rightPos, temp);
            heapify(rightPos);
        }
    }

    // cr min heap
    public static void heapIns(int item) {
        res.add(item);
        int lastPos = res.size() - 1;

        while (lastPos != 0) {
            int parPos = (lastPos - 1) / 2;

            if (res.get(parPos) > item) {
                int temp = res.get(parPos);
                res.set(parPos, item);
                res.set(lastPos, temp);
            }

            lastPos = parPos;
        }

    }

    public static void main(String[] args) {

        // ip - [[1,4,5],[1,3,4],[2,6]]
        // create array of list nodes
        var no = RandomGenerator.getDefault();
        int len;

        int[] ip = { 1, 1, 2, 4, 3, 6, 5, 4, 6 };
        int n = 0;

        ListNode[] listNodes = new ListNode[3];

        listNodes[0] = new ListNode(1, new ListNode(4, new ListNode(5)));
        listNodes[1] = new ListNode(1, new ListNode(3, new ListNode(4)));
        listNodes[2] = new ListNode(2, new ListNode(6));

        /*
         * 
        for (int i = 0; i < 3; i++) {
            len = 3;
            // listNodes[i] = new ListNode(no.nextInt(1, 10));
            // listNodes[i] = new ListNode(no.nextInt(1, 10));
            listNodes[i] = new ListNode(ip[n]);

            while (len-- > 0) { 
                // System.out.println(i + " index val is " + listNodes[i].val);
                // listNodes[i] = new ListNode(no.nextInt(1, 10), listNodes[i]);
                listNodes[i] = new ListNode(ip[n++], listNodes[i]);
                // temp = temp.next;
            }
        }
         */

        /*
         * 
        while (lis.next != null) { 
            System.out.println("val is " + lis.val);
            lis = lis.next;
        }
         */

        mergeKLists(listNodes);

    }
}
