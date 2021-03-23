import java.util.Scanner;

/*
Calculating the set bits(number of 1's in binary form) of an integer
*/

public class SetBitsInInteger
{
    private static Scanner sc  =new Scanner(System.in);
    public static void main(String[] args) {
        
        //asking the user for input and storing the input in int variable n
        System.out.println("Kindly enter the number: ");
        int n= sc.nextInt();

        //converting the entered input(integer) into binary and storing it in string variable binary
        String binary = Integer.toBinaryString(n);
        
        //printing the binary form of the integer
        System.out.println("Binary form: "+binary);

        //we store the number of 1's in count variable
        int count=0;

        //now we iterate through the string and check for the presence of 1's
        for(int i=0;i<binary.length();i++)
        {
            //comparing each character present in the string to '1'
            if(binary.charAt(i)=='1'){
                count++;
            }
        }
        System.out.println(count);
    }
}

/*
Sample Outputs:

Kindly enter the number: 
3
Binary form: 11
2


Kindly enter the number:
2
Binary form: 10
1


Kindly enter the number: 
16
Binary form: 10000
1


Kindly enter the number: 
-12
Binary form: 11111111111111111111111111110100
29

*/
