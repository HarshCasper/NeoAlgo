import java.util.ArrayList;
import java.util.stream.IntStream;

/**
 * The Sieve of Atkin is a modern algorithm for finding all prime
 * numbers up to a specified integer. Compared with the ancient
 * sieve of Eratosthenes, which marks off multiples of primes, the
 * sieve of Atkin does some preliminary work and then marks off
 * multiples of squares of primes, thus achieving a better theoretical
 * asymptotic complexity. It was created in 2003 by A. O. L. Atkin
 * and Daniel J. Bernstein.
 *
 * Google it if you don't know about it.
 *
 * @author Ricardo Prins
 * @since 3-7-2020
 */
public class sieveOfAtkin {

    public static ArrayList<Integer> sieve(int lowerLimit, int upperLimit) {
        ArrayList<Integer> result = new ArrayList<>();

        if (upperLimit > 2) {
            result.add(2);
        };
        if (upperLimit > 3) {
            result.add(3);
        };
        boolean[] sieve = new boolean[upperLimit];



        IntStream.range(0, upperLimit)
                .forEach(i -> sieve[i] = false);

        for (int x = 1; x * x < upperLimit; x++) {
            for (int y = 1; y * y < upperLimit; y++) {
                int n = (4 * x * x) + (y * y);
                if (n <= upperLimit && (n % 12 == 1 || n % 12 == 5)) sieve[n] ^= true;
                n = (3 * x * x) + (y * y);
                if (n <= upperLimit && n % 12 == 7) sieve[n] ^= true;
                n = (3 * x * x) - (y * y);
                if (x > y && n <= upperLimit && n % 12 == 11) sieve[n] ^= true;
            }
        }
        IntStream.iterate(5, r -> r * r < upperLimit, r -> r + 1)
                .filter(r -> sieve[r])
                .flatMap(r -> IntStream.iterate(r * r, i -> i < upperLimit, i -> i + r * r))
                .forEach(i -> sieve[i] = false);

        for (int a = lowerLimit; a < upperLimit; a++) {
            if (sieve[a]) {
                result.add(a);
            }

        }
       return result;
    }

}