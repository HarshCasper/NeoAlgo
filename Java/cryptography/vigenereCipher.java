  
import java.util.*;
public class Main {
public static String encrypt(String str,String key)
{
    int indexI= 0,indexJ=0;
    String s1="";char ch;
    for(indexI=0;indexI<str.length();indexI++)
    {
        if(indexJ>=key.length())
        indexJ=0;
        ch = (char)((str.charAt(indexI)+(key.charAt(indexJ)-65)%26));
        if(ch>'Z')
        ch=(char)(ch-26);
        s1 = s1 + ch;
        indexJ++;
    }
      return s1;
}

public static String decrypt(String str,String key)
{
    int indexI= 0,indexJ=0;String s1="";char ch;
    for(indexI=0;indexI<str.length();indexI++)
    {
        if(indexJ>=key.length())
        indexJ=0;
        ch = (char)((str.charAt(indexI)-(key.charAt(indexJ)-65)%26));
        if(ch<'A')
        ch=(char)(ch+26);
        s1 = s1 + ch;
        indexJ++;
    }
    return s1;
}

    
public static void main(String[] args)
{
    Scanner sc = new Scanner(System.in);
    String str = sc.nextLine();
    String key = sc.nextLine();
   String encrpytedString = encrypt(str.toUpperCase(),key.toUpperCase());
   String decryptedString = decrypt(encrpytedString,key.toUpperCase());
   System.out.println(encrpytedString);
     System.out.println(decryptedString);
}
}
