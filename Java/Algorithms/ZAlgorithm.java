import java.util.Scanner;

public class ZAlgorithm {

    public static void main(String[] args) {
        // taking the user input
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the text:");
        String text = scanner.nextLine();
        System.out.println("Enter the pattern to be searched:");
        String pattern = scanner.nextLine();
        scanner.close();

        searchPattern(text, pattern);
    }

    private static void searchPattern(String text, String pattern) {
        String concatNewStr = pattern + "$" + text;
        int[] zArr = new int[concatNewStr.length()];

        //get the z array
        getZarr(concatNewStr, zArr);

        // looping to find the array locations
        for (int i = 0; i < zArr.length; i++) {
            if(zArr[i] == pattern.length()) {
                System.out.println("Found pattern at index " + (i - pattern.length() - 1));
            }
        }
    }

    private static void getZarr(String concatNewStr, int[] zArr) {
        int n = concatNewStr.length();

        // [left,right] make a window which matches with prefix of s
        int left = 0, right = 0;

        for (int i = 1; i < concatNewStr.length(); ++i) {

            // if i>right nothing matches
            if (i > right) {

                left = right = i;

                // right-left = 0 in starting, so it will start checking from 0'th index.
                while (right < n && concatNewStr.charAt(right - left) == concatNewStr.charAt(right)) {
                    right++;
                }

                zArr[i] = right - left;
                right--;

            } else {

                // k = i-left so k corresponds to number which matches in [left,right] interval.
                int k = i - left;

                // if zArr[k] is less than remaining interval then zArr[i] will be equal to zArr[k].
                if (zArr[k] < right - i + 1) {
                    zArr[i] = zArr[k];
                } else {
                    // else start from right and check manually
                    left = i;
                    while (right < n && concatNewStr.charAt(right - left) == concatNewStr.charAt(right)) {
                        right++;
                    }
                    zArr[i] = right - left;
                    right--;
                }
            }
        }
    }
}
/*
* Sample input/output:
* Enter the text:
* AABAACAADAABAABA
* Enter the pattern to be searched:
* AABA
* Found pattern at index 0
* Found pattern at index 9
* Found pattern at index 12
*
* Time complexity and Space complexity: O(m + n), length of text be n and of pattern be m
*/
