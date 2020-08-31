import java.util.*;

public class Anagram{

    static boolean checkAnagram(String s1, String s2){

        //Converting into character array
        char[] string1 = s1.toCharArray();
        char[] string2 = s2.toCharArray();

        //Checking the lenghth of string
        if(string1.length != string2.length){
            return false; //if not same the  they are not anagram
        }

        //Sorting the charcater array alphabetically
        Arrays.sort(string1);
        Arrays.sort(string2);

        //Converting the character array to string to compare
        String str1 = new String(string1);
        String str2 = new String(string2);

        //Compare the two string and return accordingly
        return str1.equals(str2) ;
    }

    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        //Taking input from user
        System.out.println("Enter the string 1 : ");
        String s1 = scan.next();
        System.out.println("Enter the string 2 : ");
        String s2 = scan.next();

        //Calling the function checkAnagram to check whether the two string is anagram or not.
        boolean result = checkAnagram(s1, s2);

        if(result){
            System.out.println("Both the Strings are anagram."); //yes Anagram
        }
        else{
            System.out.println("Both the String are not anagram."); //No, not Anagram
        
    }
}