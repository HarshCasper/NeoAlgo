/* Given a valid (IPv4) IP address, return a defanged version of of that IP address. A defanged IP address replaces every period "." with "[.]".

Input : address : "1.1.1.1"
Output : "1[.]1[.]1[.]1[.]"

Input : "255.100.50.0"
Output : "255[.]100[.]50[.]0[.]"*/
import java.util.*;
class GC3 {
    public static void main(String args[]) {
        int c = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter IPv4 address");
        String s = sc.next();
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) == '.')
                c++;
        s = s.replace(".", "[.]");
        if (c == 3)
            System.out.println("Defanged IPv4 address : " + s);
        else
            System.out.println("Not a valid IPv4 address");

    }
}

/* Sample Input and Output : 
 * Enter IPv4 address
1.1.1.1
Defanged IPv4 address : 1[.]1[.]1[.]1
Enter IPv4 address
2500.100.50.0
Defanged IPv4 address : 2500[.]100[.]50[.]0
Enter IPv4 address
1.1.1.1.
Not a valid IPv4 address
Time Complexity : O(n) where n=s.length();
Space Complexity : O(1)
 */
