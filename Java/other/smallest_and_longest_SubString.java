  /*This is a java code of finding two substring. One will be shortest substring
  as the substring will start from smallest(initial charater of alphabets) charater from string,
  similarly for largest substring, the substring will start from largest(end
  most charater of alphabets) charater from string.
  For example, AwesomeJAVAcode for length 3 will return Aco as smallest and wes as largest.
  */
  import java.util.Scanner;
  import java.lang.String;
  public class smallest_and_longest_SubString
  {
        public static String getSmallestAndLargest(String string, int length)
        {
            String largest = "";
            String smallest = "";
            int string_length = string.length();
            String store[] = new String[20];
            char last_char = 'z';
            int start = 0;
            /*
             the idea here is to store the occurrence count against the ASCII
             value of that character. For example, the occurrence of ‘A’ would
             be stored in counter[65] because ASCII value of A is 65.
            */
            for (int i = 57; i >= 0; i--)
            {
                for (int j = 0; j <= string_length - length; j++)
                {
                    char current_char = string.charAt(j);
                    if (current_char == last_char)
                    {
                        store[start] = string.substring(j, j + length);
                        smallest = store[start];
                        largest = store[0];
                        start++;
                    }
                }
                last_char--;
            }
            return "Smallest substring  "+smallest + "\n" +"largest String  "+ largest;
        }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter your String...");
        String string = scan.next();
        System.out.println("Please enter length that you want for substring...");
        int length = scan.nextInt();
        scan.close();
        System.out.println(getSmallestAndLargest(string, length));
    }
  }
  /*
  Time complexity is O(n)
  Space complexity is O(n)

  Input :
  Enter your String...
  ABCDEFGHIJKLMNOPQRS
  Please enter length that you want for substring...
  3

  Output:
  Smallest substring  ABC
  largest String  QRS
  */
