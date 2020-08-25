import java.util.*;

class ManacherAlgorithm {

    public static String manacherSearch(String str) {

        // array for holding the palindromic sequence around every center
        ArrayList<Integer> positions = new ArrayList<Integer>();
        int start = 0;
        int end = 0;

        // i is our current center
        for(int i = 0; i < str.length(); ) {

            // we check on both sides of i till where we can find same letters on 2 positions
            while(start > 0 && end < str.length()-1 && str.charAt(start-1) == str.charAt(end+1)) {
                start--;
                end++;
            }

            // getting the length of palindrome around current center
            positions.add(i, end - start + 1);

            // this is case 2. Current palindrome is proper suffix of input. Meaning input is the longest palindrome
            if(end == (str.length() -1)) {
                break;
            }

            //Mark newCenter to be either end or end + 1 depending on if we dealing with even or old number input.
            int newCenter = end + (i%2 ==0 ? 1 : 0);

            for(int j = i + 1; j <= end; j++) {

                // Its possible left mirror might go beyond current center palindrome. So take minimum of either left side palindrome or distance of j to end.
                // T[j] = Math.min(T[i - (j - i)], 2 * (end - j) + 1);
                positions.add(j, (Math.min(positions.get(i - (j - i)), 2 * (end - j) + i)));

                // This check is to make sure we do not pick j as new center. As soon as we find a center lets break out of this inner loop.
                if(j + positions.get(i - (j - i))/2 == end) {
                    newCenter = j;
                    break;
                }
            }

            // make i as newCenter. Set right and left to atleast the value we already know should be matching based of left side palindrome.
            i = newCenter;
            if(i < positions.size()) {
                end = i + positions.get(i)/2;
                start = i - positions.get(i)/2;
            }

        }

        int max = Collections.max(positions);
        int pos = positions.indexOf(max);

        if(str.length()%2==0) {
            str = str.substring(pos - (max/2), pos + (max/2) + 1);
        } else {
            str = str.substring(pos - (max/2), pos + (max/2));
        }

        // removing $ signs
        str = originalString(str);

        return str;
    }

    public static String originalString(String str) {
        StringBuilder sBuilder = new StringBuilder();

        //getting original String from processed one
        for(int i=0; i < str.length(); i++) {
            if(i%2!=0) {
                sBuilder.append(str.charAt(i));
            }
        }
        return sBuilder.toString();
    }

    public static String process(String str) {
        StringBuilder sBuilder = new StringBuilder();

        // preprocessing string and adding a symbol between letters to take care of strings with even number of characters
        for(int i=0; i < str.length(); i++) {
            sBuilder.append("$");
            sBuilder.append(str.charAt(i));
        }
        sBuilder.append("$");
        return sBuilder.toString();
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String str = sc.nextLine();
        sc.close();

        str = process(str);

        str = manacherSearch(str);
        System.out.println("Longest palindromic substring: " + str);
        System.out.println("Length of longest substring: " + str.length());
    }
}
/**
 * Sample input/output
 * 
 * Enter a string:
 * abba
 * Longest palindromic substring: abba
 * Length of longest substring: 4
 * 
 * Enter a string:
 * babcbaabcbaccba
 * Longest palindromic substring: abcbaabcba
 * Length of longest substring: 10
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
