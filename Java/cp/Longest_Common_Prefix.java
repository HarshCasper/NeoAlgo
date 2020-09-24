import java.util.*;
class Longest_Common_Prefix{
    public static String LongestCommonPrefixFn(String[] strs) {
        if(strs.length==0){
            return "";
        }
        String st = strs[0];
        for(int i=1; i<strs.length; i++){
            while(strs[i].indexOf(st)!=0){
                st = st.substring(0, st.length()-1);
            }
        }
        return st;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter strings");
        String st = sc.nextLine();
        String[] arrOfStr = st.split(" ");
        System.out.println("Longest Common Prefix : "+LongestCommonPrefixFn(arrOfStr));
    }
}

/*sample input and output:

Enter strings
encourage encoder enchant

Longest Common Prefix : enc

Complexities
Time: O(n^2)
Space: O(n)*/
