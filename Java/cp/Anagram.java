import java.util.*;

public class Anagram{

    static boolean checkAnagram(String s1, String s2){
        char[] string1 = s1.toCharArray();
        char[] string2 = s2.toCharArray();

        if(string1.length != string2.length){
            return false;
        }
        Arrays.sort(string1);
        Arrays.sort(string2);

        String str1 = new String(string1);
        String str2 = new String(string2);

        return str1.equals(str2) ;
    }
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the string 1 : ");
        String s1 = scan.next();
        System.out.println("Enter the string 2 : ");
        String s2 = scan.next();
        boolean result = checkAnagram(s1, s2);

        if(result){
            System.out.println("Both the Strings are anagram.");
        }
        else{
            System.out.println("Both the String are not anagram.");
        
    }
}