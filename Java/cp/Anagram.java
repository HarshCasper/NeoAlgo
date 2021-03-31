  /*This is a java code of checking whether the Strings are anagram to each other and not...
  An anagram of a string is another string that contains the same characters,
  Only the order of characters can be different.
  In other words, Two strings are said to be anagram if we can form one string
  by arranging the characters of another string.
  For example, Race and Care. Here, we can form Race by arranging the characters of Care.
  For example, “abcd” and “dabc” are an anagram of each other.
  */
  import java.util.Scanner;
  import java.lang.String;
  public class Annagram 
  {
	
        static boolean isAnagram(String first_string, String second_string) 
	{ 
              first_string = first_string.toLowerCase();
              second_string = second_string.toLowerCase();
              boolean check = true;
              int first_length[] = new int[256];
	  
	      /* system provided the ASCII table
              which had 256 characters and each ASCII code
	      (numerical code) was assigned to one character.
              */
              
	      int second_length[] = new int[256];
              
	      for (char each_char : first_string.toCharArray()) 
	       {
                   int index = (int) each_char;
                   first_length[index]++;
               }
              
	      for (char each_char : second_string.toCharArray()) 
	       {
                   int index = (int) each_char;
                   second_length[index]++;
               }
              
	      /*
              For comparing each character from one
              String to another.
              */
              
	      for (int i = 0; i < 256; i++) 
	      {
                  if (first_length[i] != second_length[i]) 
		  {
                      check = false;
                      break;
                  }
              }
              return check;
        }
        public static void main(String[] args) 
        {
            Scanner scan = new Scanner(System.in);
            System.out.println("Please enter the first String : ");
            String first_string = scan.next();
            System.out.println("Please enter the Second String : ");
            String second_string = scan.next();
            scan.close();
            boolean ret = isAnagram(first_string, second_string);
            System.out.println((ret) ? "String are Anagrams..." : "Strings are Not Anagrams...");
        }
  }
   /*
  Time complexity is O(n)
  Space complexity is O(1)

  Input :
  Please enter the first String :
  abcd
  Please enter the Second String :
  dcab

  Output:
  String are Anagrams...
  */
