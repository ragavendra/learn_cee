
public class dsa {

    public static int greatestInArr(int[] args) {
        int gr = args[0];
        int steps = 0;
        for (int i = 0; i < args.length; i++) {
            steps++;
            if(gr < args[i])
                gr = args[i];
        }

        System.out.println("Steps for big Oh " + steps + " with arr size " + args.length);

        return gr;
    }

    public static void main(String[] args) {
        
        int arr[] = { 24, 42, 12, 15, 39 };

        System.out.println("Gr in arr is " + greatestInArr(arr));

        int f = 13/2;
        System.out.println("f is " + f);
    }
}