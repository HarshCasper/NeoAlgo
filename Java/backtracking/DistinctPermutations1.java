import java.util.HashSet;

public class DistinctPermutations1 {
    // store all the generated permutations
    public static HashSet<String> h = new HashSet<String>();

    public static void permute(char s[], int i, int n) {

        // if the permutation is complete
        if (i == n) {

            // if set doesn't contain
            // the permutation already
            if (!(h.contains(String.copyValueOf(s)))) {
                h.add(String.copyValueOf(s));
                // Print the generated permutation
                System.out.println(s);
            }
        }

        else {

            // one by one swap the jth
            // character with the ith
            for (int j = i; j <= n; j++) {
                // swap a[i] and a[j];
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                // revert the swapping
                permute(s, i + 1, n);
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    public static void main(String args[]) {
        char s[] = { 'A', 'B', 'A' };
        permute(s, 0, s.length - 1);
    }
}