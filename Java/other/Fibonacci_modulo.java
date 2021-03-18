/*
  To find a huge fibonacci number N modulo M using Pisano period properties.
  
  Pisano Period:
  In number theory the nth Pisano Period is the period with which the sequence of Fibonacci numbers taken modulo n repeats.
  Properties:
  		1. For a given value of N and M>=2 the series generated F(i) modulo M is periodic.
  		2. The period always starts with 01
   		3. Pisano Period is defined as the length of the period of this series.
   	   		Example: For M=2 period is 011 and has length 3
   	   				 For M=8 period is 01120221 and has length 8, and so on.
   	   	4. The Pisano Period for a given M ranges from 3 to M*M
   
  Approach:
  1. Compute the pisano period of M by checking for the period with repeating 01.
  2. Find the remainder when N is divided by the pisano period of M.
  3. Then calculate F(N remainder) modulo M for new N.
  
  Example: F(2019) modulo 5
  1. Pisano period of 5 = 20
  2. 2019 % 20 = 19
  3. F(2019) modulo 5 = F(19) modulo 5 = 1
  
  Time Complexity : O(M^2)
  Space Complexity : O(1)
 */
import java.util.*;
public class Fibonacci_modulo {

    private static long getPisanoPeriod(long m) {
        long a = 0, b = 1, c = a + b, result = 0;
        for (int i = 0; i < (m * m); i++) {
            c = (a + b) % m;
            a = b;
            b = c;
            if (a == 0 && b == 1) {
                result = i + 1;
                break;
            }
        }
        return result;

    }

    private static long getFibonacciHuge(long n, long m) {
        long pisanoPeriod = getPisanoPeriod(m);
        long rem = n % pisanoPeriod;
        long first = 0, second = 1;
        long res = rem;
        for (int i = 1; i < rem; i++) {
            res = (first + second) % m;
            first = second;
            second = res;
        }

        return res % m;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the huge fibonacci number N");
        long n = sc.nextLong();
        System.out.println("Enter the the number M to find modulo with");
        long m = sc.nextLong();
        long result = getPisanoPeriod(m);
        System.out.println("Pisano period is: " + result);
        System.out.println("Hence, F(" + n + ")" + " % " + m + " = " + getFibonacciHuge(n, m));

        sc.close();
    }

}
/*
Sample Input:
Enter the huge fibonacci number N
2016
Enter the the number M to find modulo with
15

Sample Output:
Pisano period is: 40
Hence, F(2016) % 15 = 12

Time Complexity: O(M^2)
Space Complexity: O(1)
 */