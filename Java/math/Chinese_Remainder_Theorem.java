import java.util.Scanner;

public class Chinese_Remainder_Theorem {

    public static long chineseRemainder(long[] coPrimes, long[] remainders){
        long x = 0;
        long m = arrayMultiplied(coPrimes);
        for (int i = 0; i <coPrimes.length ; i++) {
            long mm = m/coPrimes[i];
            x+= remainders[i] * modularMultiplicativeInverse(mm,coPrimes[i]) * mm;
        }
        return x % m;
    }
    public static long modularMultiplicativeInverse(long a, long m){
        // Returns modulo inverse of a with respect to m using extended Euclid Algorithm
        // Explanation : we have GCD = aS + mT, the modular inverse is S ( mod m )
        if(m==1)
            return 0;
        long s0 = 1 , s1 = 0;
        long remainder = m;
        while (a>1){
            long quotient = a /remainder;
            //R(i) = R(i-2) % R(i-1)
            long temp = remainder;
            remainder = a % remainder;
            a = temp ;
            //S(i) = S(i-1)- quotient * S(i-2)
            temp = s1;
            s1 = s0 - quotient*s1;
            s0 = temp;
        }
        // make s0 positive
        if(s0 < 0)
            s0+=m;
        return s0;
    }

    public static long arrayMultiplied(long[] arr){
        long m = 1 ;
        for (long n:arr) {
            m*=n;
        }
        return m;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("This algorithm finds X where \nX ≡ remainder0 ( mod coPrime0 )\nX ≡ remainder1 ( mod coPrime1 )\n.\n.\n.\nX ≡ remainder(n) ( mod coPrime(n) )");
        System.out.println("Enter number of equations (n) :");
        int n = scan.nextInt();
        //elements in coPrimes[] must be pairwise co-prime
        long[] coPrimes = new long[n];
        long[] remainders = new long[n];
        scan.nextLine();
        System.out.println("Enter co-primes ( Modulos ) :");
        for (int i = 0; i < n; i++) {
            coPrimes[i] = scan.nextLong();
        }
        scan.nextLine();
        System.out.println("Enter corresponding remainders : ");
        for (int i = 0; i < n; i++) {
            remainders[i] = scan.nextLong();
        }
        System.out.println("X is "+ chineseRemainder(coPrimes,remainders));
    }
}
