// Roman To Integer C++ Program

/* Sample Input 1: S = "IV"
          Output: 4  

   Sample Input 2: S = "LVIII"
         Output: 58
   Explanation: L = 50, V= 5, III = 3

   Sample Input: s = "MCMXCIV"
         Output: 1994
   Explanation: M = 1000, CM = 900, XC = 90 and IV = 4
*/


    #include <bits/stdc++.h>  //Header File
    using namespace std;
    
    int value(char r)   //Function that change roman charcater into integer
    {
        if(r=='I')
            return 1;
        if(r=='V')
            return 5;
        if(r=='X')
            return 10;
        if(r=='L')
            return 50;
        if(r=='C')
            return 100;
        if(r=='D')
            return 500;
        if(r=='M')
            return 1000;
        return -1;
        
    }
    
    int roman_To_Int(string S)   //Function that change roman string into intiger
    {
        int c=0;
        for(int i=0;i<S.length();i++)   //for analyse the string
        {
            int s1=value(S[i]);   //calling function  by taking roman character of ith index
            if(i+1<S.length())   //if value of i+1 greater then the length of string
            {
                int s2=value(S[i+1]);  //calling function  by taking roman character of i+1th index
                if(s1>=s2)   //check if s1>=s2
                {
                    c+=s1;
                }
                else    
                {
                    c+=s2-s1;
                    i++;
                }
            }
            else
                c+=s1;
        }
        return c;    //return intiger value
    }
    int main()
    { 
        string S;  //taking string
        cout<<"Enter string";
        cin>>S;   //input string of roman characters
        int r;   //for taking the value of intiger
       r=roman_To_Int(S);//calling function for converting roman string into intiger value
       cout<<"Roman to Intiger is : "<<r;   //print intiger value
       return 0;
    }

    /* Time Complexity- O(string size) = O(n)
       Space Complexity- O(3) = constant */