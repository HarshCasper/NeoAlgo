    /*
    A positive integer greater than 1 which has no other
    factors except 1 and the number itself is called a prime number.
    2, 3, 5, 7 etc. are prime numbers as they do not have any other factors.
    */
    import java.util.Scanner;
    public class Prime
    {
        public  Prime(int first_range, int second_range)
        {
	         for(int i=first_range;i<=second_range;i++)
           {
		           if(i%2==1 && i%i==0 || i==2)
               {
			             System.out.println(i);
	             }
	         }
        }
	  public static void main(String[] args)
		{
    Scanner scan=new Scanner(System.in);
    System.out.println("Please enter range..");
    int first_range=scan.nextInt();
    int second_range=scan.nextInt();
    Prime out=new Prime(first_range,second_range);
  	}
    }

    /*
    Time complexity is O(n)
    Space complexity is O(n)

    Input :
    Please enter range..
    70
    80

    Output:
    71
    73
    75
    77
    79

    */
