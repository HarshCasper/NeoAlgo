import java.util.*;

class TowerOfHanoi {

    public static void shiftRings(int n, int fromRod, int toRod, int midRod) {
        if(n == 1) {
            System.out.println("Shifting disk 1 from rod " + fromRod + " to rod " + toRod);
            return;
        }
        shiftRings(n-1, fromRod, midRod, toRod);
        System.out.println("Shifting disk " + n + " from rod " + fromRod+ " to rod " + toRod);
        shiftRings(n-1, midRod, toRod, fromRod);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rings:");
        int n = sc.nextInt();
        sc.close();

        shiftRings(n, 1, 3, 2);
    }
}
/**
 * Sample input/output: 
 * Enter the number of rings:
 * 4
 * Shifting disk 1 from rod 1 to rod 2
 * Shifting disk 2 from rod 1 to rod 3
 * Shifting disk 1 from rod 2 to rod 3
 * Shifting disk 3 from rod 1 to rod 2
 * Shifting disk 1 from rod 3 to rod 1
 * Shifting disk 2 from rod 3 to rod 2
 * Shifting disk 1 from rod 1 to rod 2
 * Shifting disk 4 from rod 1 to rod 3
 * Shifting disk 1 from rod 2 to rod 3
 * Shifting disk 2 from rod 2 to rod 1
 * Shifting disk 1 from rod 3 to rod 1
 * Shifting disk 3 from rod 2 to rod 3
 * Shifting disk 1 from rod 1 to rod 2
 * Shifting disk 2 from rod 1 to rod 3
 * Shifting disk 1 from rod 2 to rod 3
 * 
 * Time complexity: O(2^n)
 * Space complexity: O(n)
 */
