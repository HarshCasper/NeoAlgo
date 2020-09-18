import java.util.Scanner;

public class SwapNibbles {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:");
        int num = sc.nextInt();

        int result = swapNibbles(num);

        System.out.println("Number after swapping nibbles:" + result);
        sc.close();
    }

    private static int swapNibbles(int x) {
        /* (x & 0x0F) << 4 gives us the last 4 bits of the number and
        shifts it by 4 bits to the left.
        (x & 0xF0) >> 4 gives us the last 4 bits of the number and
        shifts it to right by 4 bits. */
        return ((x & 0x0F) << 4 | (x & 0xF0) >> 4);
    }
}
/*
* Sample input/output
* Enter a number:
* 100
* Number after swapping nibbles:70
*
* Space and Time complexity = O(1)
*/
