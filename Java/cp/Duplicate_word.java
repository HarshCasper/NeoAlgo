    /*This is a java code for removing duplicate words from sentence.
    remove instances of words that are repeated more than once,
    but retain the first occurrence of any case-insensitive repeated word
    For example, Sam went went to to to his school, will become Sam went to his school.
    For example, Hello hello Ab aB, will change to Hello Ab.
    */
    import java.lang.String;
    import java.util.Scanner;
    import java.util.regex.Matcher;
    import java.util.regex.Pattern;

    public class Duplicate_word
    {
    public Duplicate_word(String input, Pattern p)
    {
        Matcher m = p.matcher(input);
        // Check for subsequences of input that match the compiled pattern
        while (m.find())
        {
             input = input.replaceAll(m.group(), m.group(1));
        }
        // Prints the modified sentence.
        System.out.println(input);
    }
    public static void main(String[] args)
    {
          String regex = "\\b(\\w+)(?:\\W+\\1\\b)+";
          Pattern p = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
          Scanner in = new Scanner(System.in);
          System.out.println("Please enter how many sentences you want correct : ")
          int numSentences = Integer.parseInt(in.nextLine());
          System.out.println("Please enter your sentence...")
          while (numSentences-- > 0)
          {
              String input = in.nextLine();
              Duplicate_word s = new Duplicate_word(input, p);
          }
          in.close();
    }
    }
    /*
    Time complexity is O(n)
    Space complexity is O(1)

    Input :
    Please enter how many sentences you want correct :
    5
    Please enter your sentence...
    Goodbye bye bye world world world.
    Sam went went to to to his business.
    Reya is is the the best player in eye eye game.
    in inthe.
    Hello hello Ab aB

    Output:
    Goodbye bye world
    Sam went to his business
    Reya is the best player in eye game
    in inthe
    Hello Ab
    */
