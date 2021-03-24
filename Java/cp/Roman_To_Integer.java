// Program to convert Roman Numeral to Integer


import java.util.Scanner;

class Solution {
              
    public static int symboltoChar(char c){
        switch(c){
            case 'I': return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L': return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
        }
        return 0;
    }

    public static void main(String...ar){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Roman Numeral");
        String s= sc.next();
        int result=0;
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            
            if((i!= s.length()-1) && (symboltoChar(c) < symboltoChar(s.charAt(i+1)))){
                result= result - symboltoChar(c);
            }else{
                result = result + symboltoChar(c);
            }
               }
               System.out.println(result);
        
    }
}