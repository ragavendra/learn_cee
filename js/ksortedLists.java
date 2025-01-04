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

import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.TreeSet;

class Solution {

    public static LinkedList<Integer> res = new LinkedList();
    public static LinkedList<Integer> sortedRes = new LinkedList();

    public ListNode[] sanitizeLists(ListNode[] lists) {
    // public LinkedList<ListNode> sanitizeLists(ListNode[] lists) {
        int len = lists.length;
        if(len == 0)
            return null;

        LinkedList<Integer> nullIndexes = new LinkedList();

        // if all items are null
        for(int i = 0; i < len; i++) {
            if(lists[i] == null)
                nullIndexes.add(i);
        }

        if(nullIndexes.size() == 0)
            return lists;

        if(nullIndexes.size() == lists.length)
            return null;

        ListNode[] newArr = new ListNode[lists.length - nullIndexes.size()];
        int arrI = 0;
        for(int i = 0; i < len; i++) {
            if(lists[i] != null)
                newArr[arrI++] = lists[i];
        }

        return newArr;
    }



    public ListNode mergeKLists(ListNode[] lists) {

        lists = sanitizeLists(lists);

        if(lists == null)
            return null;
    
        if(lists.length == 0)
            return null;

        boolean ins = false;

        // int count = 10;
        do {

            ins = false;

            for(int i = 0; i < lists.length; i++) {

                if(lists[i] != null) {
                    ins = true;
                    heapIns(lists[i].val);
                    // System.out.println(lists[i].val);
                    lists[i] = lists[i].next;
                }
            }
            
        }  while(ins);

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
        ListNode temp = result;
        int len = sortedRes.size();
        for (int i = 0; i < len; i++) {
            temp.next = new ListNode(sortedRes.removeLast());
            temp = temp.next;
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

            // Integer.compare(parPos, parPos)
            // PriorityQueue<Integer, Integer> priorityQueue = new PriorityQueue<>((a, b) -> Integer.compare(b.getValue(), a.getValue()));
            // PriorityQueue<Integer, Integer> priorityQueue = new PriorityQueue<>((a, b) -> Integer.compare(b, a));

             PriorityQueue<Map.Entry<Integer, Integer>> heap = new PriorityQueue<>(
            (a, b) -> Integer.compare(b.getValue(), a.getValue())
        );

        heap.offer(null);
        heap.poll();

            HashMap<Integer, Integer> hashMap = new HashMap<>();
            hashMap.put(parPos, parPos);
            hashMap.get(1);
           hashMap.containsKey(1);
           
           Set<Integer> set = hashMap.keySet();
           Collection<Integer> coll = hashMap.values();
           // coll.co
           // Set<Integer> seta = new TreeSet<>((a, v) -> Integer.compare(a, v));
           Set<Integer> seta = new TreeSet<>();
           seta.addAll(coll);

           hashMap.get(1);

           linkedList.res

           for (int elem : hashMap.keySet()) {
               
           }
           
            Object[] arr = sortedRes.toArray();
           

        }

         // if(res.size() > 0)
            sortedRes.add(res.remove());

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