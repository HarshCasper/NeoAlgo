//Given a sequence of integer(input)
// return the n'th term of the count-and-say sequence

//The problem is to start count from the digit 1 and print(output) the counter and value of till that nth digit in the form of string 

//For Example:
//Input: n = 4              where n is a integer
//Output: s = "1211"        where s is a string

//Here we have to count till 4 and start from 1 digit so the our output value is now will be

//step 1/(at 1st iteration) : count will "1" 
// step 2                   : count "1" and say '"one" `1`' = "11"
// step 3                   : count "11" and say '"two" `1`' = "21"
// step 4/(nth iteration)   : count "21" and say '"one" `2` "one" `1`' = "12" + "11" = "1211"

//So for 4th(nth) term the sequence gives output of "1211"

//Test case 1: 
//Input : n = 6
//Output : s = "312211"

//Test case 2: 
//Input : n = 9
//Output : s = "31131211131221"

//This Question has been asked in various MNC's coding round 

class Solution {
public:
    
    
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11"; 
        
        
        string s = "11";
        
        for ( int i = 3 ; i <= n ; i++ ){
            string t = "";
            s = s + '&';
            int c = 1;
            
            for ( int j = 1 ; j < s.length() ; j++ ){
                if( s[j] != s[j-1] ){
                    t = t + to_string(c);
                    t = t + s[j-1];
                    c = 1;
                
                } else c++;
                
            } s = t;
            
        } return s;
    }
};