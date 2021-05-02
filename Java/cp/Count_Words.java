  /* This is a java code of finding total number of
   words in given string.
  */
  import java.util.*;
  import java.lang.*;
  import java.io.*;
  import java.lang.String;
  public class count_words
  {
      public static int countWords(String str)
      {
             /* The java.util.StringTokenizer class allows
              you to break a string into tokens.
             */
              StringTokenizer tokens = new StringTokenizer(str);
              return tokens.countTokens();
      }
  public static void main(String[] args)
  {
      Scanner scan = new Scanner(System.in);
      System.out.print("Enter your string : ")
      String str = scan.next();
      System.out.println("No of words: " + countWords(str));
  }
  }
   /*
  Time complexity is O(n)
  Space complexity is O(1)

  Input :
  Enter your string : I like to contribute here

  Output:
  No of words: 5
  */
