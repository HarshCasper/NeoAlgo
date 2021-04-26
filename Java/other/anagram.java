/*An anagram of a string is another string that contains the same characters,
* only the order of characters can be different.
* For example, “abcd” and “dabc” are an anagram of each other.
*/
public class anagram {
    public static void main (String [] args) {
        String a = "cat";
        String b = "act";
        boolean isAnagram = false;
        for(int i =0;i<a.length(); i++){
            char c = a.charAt(i);
          //  boolean isAnagram = true;
            for(int j =0;j<b.length(); j++) {
                char d = b.charAt(j);
                if (d==c){
                    isAnagram = true;
                    break;
                }
            } 
            if(!isAnagram){
                break;
            }  
        }
if(isAnagram){
    System.out.println("Anagram");
}else{
    System.out.println(" not a Anagram");
}
        
    }
}
/*
*Time Complexity = n*O(n) 
*Space Complexity = O(1)
*/
