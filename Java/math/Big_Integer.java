    /* We have to add and multiply huge numbers!!
    These numbers are so big So, you can't contain them
    in any ordinary data types like a long integer.
    */
    import java.io.*;
    import java.util.*;
    import java.math.BigInteger;
    public class Big_Integer
    {
        Big_Integer(BigInteger first, BigInteger second)
        {
        BigInteger addition=first.add(second);
        Big_Integer obj1=new Big_Integer(addition);
        BigInteger multipilication=first.multiply(second);
        Big_Integer obj2=new Big_Integer(multipilication);
        }
        Big_Integer(addition)
        {
        System.out.println("Addition is : ");
        System.out.println(addition);
        }
        Big_Integer(multipilication)
        {
        System.out.println("multipilication is : ");
        System.out.println(multipilication);
        }
    public static void main(String[] args)
    {
        Scanner scan=new Scanner(System.in);
        System.out.println("Please enter first big integer");
        BigInteger first=scan.nextBigInteger();
        System.out.println("Please enter second big integer");
        BigInteger second=scan.nextBigInteger();
        Big_Integer obj=new Big_Integer(first,second);
    }
    }
    /*
    Time complexity is O(1)
    Space complexity is O(1)

    Input :
    Please enter first big integer
    123456789123456789
    Please enter second big integer
    100000000000000000

    Output:
    Addition is :
    223456789123456789
    multipilication is :
    12345678912345678900000000000000000
    */
