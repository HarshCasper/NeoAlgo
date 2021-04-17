    /*
    Given a string, we need to reverse it without reversing any word in it.
    We can reverse each word of a string.
    In other words, Reverse text without reversing individual word in a String.
    */
    import java.util.Scanner;

    public class Reverse_String 
    {
    /*
    This is an constructor called from main function
    */
    public Reverse_String(String in[],int n)
    {
         System.out.println(); 
        
	   for (int i = n - 1; i >= 0; i--) 
           {
               System.out.print(in[i] + " ");
           }
    }
    public static void main(String[] args) 
    {

       Scanner scan = new Scanner(System.in);
       System.out.println("Please Enter the number of words your String have....");
       int n = scan.nextInt();
       String in[] = new String[n];
       System.out.println("Please enter your String here...");
           for (int i = 0; i <= n-1; i++) 
	   {
              in[i] = scan.next();
           }
       Reverse_String r1=new Reverse_String(in,n);
    }
    }   
    /*
    Time complexity is O(n-1)
    Space complexity is O(1)
    Input :
    Please Enter the number of words your String have....
    6
    Please enter your String here...
    i like this program very much
    Output:
    much very program this like i
    */
