/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

import java.util.LinkedList;

class Solution {

    public static LinkedList<Integer> res = new LinkedList();
    public static LinkedList<Integer> sortedRes = new LinkedList();

    public LinkedList<ListNode> sanitizeLists(ListNode[] lists) {
        if(lists.length == 0)
            return null;

        LinkedList<ListNode> ls = new LinkedList();

        for(int i = 0; i < lists.length; i++) {
            if(lists[i] != null)
                ls.add(lists[i]);
        }

        return ls;
    }

    public ListNode mergeKLists(ListNode[] lists) {

        LinkedList<ListNode> lists_ = sanitizeLists(lists);

        if(lists_ == null)
            return null;
    
        if(lists_.size() == 0)
            return null;

        // create min heap
        for (ListNode lis: lists_) {

            // loop for each ListNode
            while (lis != null) {
                heapIns(lis.val);
                lis = lis.next;
            }
        }

        // tbd - sort heap
        heapSort();

        ListNode result;

        if(sortedRes.size() == 0) {
            return null;
        }

        if(sortedRes.size() == 1) {
            result = new ListNode(sortedRes.removeLast());
            return result;
        }

        result = new ListNode(sortedRes.removeLast());

        // new ListNode(-1);
        //  = new ListNode();

        // print heap
        int len = sortedRes.size();
        for (int i = 0; i < len; i++) {
            // if(result.val == -1)
            if(result == null)
                result = new ListNode(sortedRes.removeLast());
            else
                result = new ListNode(sortedRes.removeLast(), result);
            }
            

        return result;
    }

    public void heapSort() {

        while (res.size() > 1) {

            // add first to sortedList
            sortedRes.add(res.getFirst());

            // add last to root
            int parPos = 0;
            res.set(parPos, res.removeLast());

            // heapify(parPos);
            LinkedList<Integer> linkedList = (LinkedList<Integer>) res.clone();
            res.clear();

            for(Integer item: linkedList) {
                heapIns(item);
            }

        }

         if(res.size() > 0)
            sortedRes.add(res.remove());
    }

    // heapify
    public void heapify(int parPos) {

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
    public void heapIns(int item) {
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
}