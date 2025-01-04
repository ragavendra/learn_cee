
import java.util.LinkedList;
import java.util.Scanner;


public class staAsQue {
    public static LinkedList<Integer> sta1 = new LinkedList();
    public static LinkedList<Integer> sta2 = new LinkedList();
    
    public static void main_(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        // only below is poss in stacks
        // sta1.removeLast();
        Scanner sc = new Scanner(System.in);
        int noQ = sc.nextInt();
        
        while (noQ-- > 0) {
            switch (sc.next()) {
                case "1":
                    insertQueue(sc.nextInt());

                    // print queue top
                    printQueueHead();
        
                    break;

                case "2":
                    deQueue();
                    break;

                case "3":
                    printQueueHead();
                    break;

                case "q":
                    return;

                default:
                    System.out.println("Invalid input!");
                    break;
            }
        }
    }
    
    public static void insertQueue(int item) {
        sta1.add(item);
    }
    
    public static void deQueue() {

        if(sta1.size() == 0) {
            System.out.println("Que empty!");
            return;
        }

        if(sta1.size() == 1) {
            // System.out.println("Que empty!");
            sta1.clear();
            sta2.clear();
            return;
        }
        

        if(sta2.size() == 1) {
            System.out.println(sta2.removeLast());
            sta1.clear();
            return;
        }


        LinkedList<Integer> temp = (LinkedList<Integer>) sta1.clone();
        
        // pop from first all items and add it to second
        while(temp.size() != 0) {
            sta2.add(temp.removeLast());
        }
        
        System.out.println(sta2.removeLast());

        if(sta2.size() == 0)
            System.out.println("Que empty!");

        // fill sta1 from sta2
        LinkedList<Integer> temp_ = (LinkedList<Integer>) sta2.clone();
        sta1.clear();
        
        // pop from first all items and add it to second
        while(temp_.size() != 0) {
            sta1.add(temp_.removeLast());
        }
        
    }
    
    // sta1 s last element is the queue head
    public static void printQueueHead(){
        if(sta1.size() == 0) {
            System.out.println("Que empty!");
            return;
        }

        LinkedList<Integer> temp = (LinkedList<Integer>) sta1.clone();
        int top = 0;
        while(temp.size() != 0) {
            top = temp.removeLast();
        }
        
        System.out.println(top);
    }
  
    // Queue
    public static void main(String[] args) {

        Queue queue = new Queue();
        queue.push(28);
        queue.push(35);
        queue.push(73);
        queue.peek();
        queue.pop();
        queue.peek();
        queue.pop();
        queue.peek();
        queue.pop();
        queue.peek();
    }

    // Stack
    public static void mainS(String[] args) {
        Stack stack = new Stack();
        stack.push(28);
        stack.push(35);
        stack.push(73);
        stack.peek();
        stack.pop();
        stack.peek();
        stack.pop();
        stack.peek();
        stack.pop();
        stack.peek();
    }   
}

class Queue {

    static int[] items;

    Queue() {
        items = new int[]{ -1 };
    }

    public static int pop() {

        if(items.length <= 0) {
            return -1;
        }

        int popItem = items[0];

        int[] temp = items.clone();
        items = new int[items.length - 1];
        for (int i = 1; i < temp.length; i++) {
            items[i-1] = temp[i];
        }
        return popItem;
    }

    public static void peek() {
        if(items.length > 0)
            if (items[items.length - 1] != -1) {
                System.out.println(items[0]);
            }
    }

    public static void push(int item) {
        if (items[0] == -1) {
            items[0] = item;
            return;
        }

        int[] temp = items.clone();
        items = new int[items.length + 1];
        for (int i = 0; i < temp.length; i++) {
            items[i] = temp[i];

            items[i + 1] = item;
        }
    }
}


class Stack {

    static int[] items;

    Stack() {
        items = new int[]{ -1 };
    }

    public static int pop() {

        if(items.length <= 0) {
            return -1;
        }

        int popItem = items[items.length - 1];

        int[] temp = items.clone();
        items = new int[items.length - 1];
        for (int i = 0; i < temp.length - 1; i++) {
            items[i] = temp[i];
        }
        return popItem;
    }

    public static void peek() {
        if(items.length > 0)
            if (items[items.length - 1] != -1) {
                System.out.println(items[items.length - 1]);
            }
    }

    public static void push(int item) {
        int[] temp = items.clone();
        items = new int[items.length + 1];
        for (int i = 0; i < temp.length; i++) {
            items[i] = temp[i];

            items[i + 1] = item;
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(28);
        stack.push(35);
        stack.push(73);
        stack.peek();
        stack.pop();
        stack.peek();
        stack.pop();
        stack.peek();
        stack.pop();
        stack.peek();
    }
}
