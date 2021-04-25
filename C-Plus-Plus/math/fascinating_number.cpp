/*
Taking a number as input and check whether it is fascinating number or not.
To find this, first multiply the number with 2 and then separately multiply the number with 3. Now concatenate the original number, the number multiplied with 2 and the number multiplied with 3, the number will be fascinating if the concatenated string contains all numbers 1 to 9 exactly once and the zeros are ignored.
Example: 192
192 * 2 = 384
192 * 3 = 576
Concatenating both the results with the original number, we get:
“192” + “384” + “576” = 192384576.
Thus, 192 is a fascinating number.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,j,c=0,count=0;
    string s;
    char i;
    
    cin>>n;
    
    //Convert all required numbers to strings and concatenate them
    s=to_string(n)+to_string(n*2)+to_string(n*3);
   
        for(i = '1'; i <= '9'; i++)
        {
            //First loop is for checking for all digits 1 to 9
            int c = 0;
            for(int j = 0; s[j]!=NULL; j++)
            {
                //Second loop is for checking for all characters of concatenated string
                if(i == s[j])
                    c++;
            }
            //check all digits occur only once 
            if(c == 1)
            {
                
                count++;
            }
        }
    //check all digits 1 to 9 are present in final string
         if(count == 9)
         {
             
                cout<<"Fascinating number";
                
            }
            else
            {
                cout<<"Not Fascinating number";
            }
        return 0;

}

/*
Time Complexity:9*length of string
O(n)
Space Complexity:sizeof(string)+4*sizeof(int)+sizeof(char)
*/

/*
Test Case 1:
192
Fascinating number
Test Case 2:
273
Fascinating number
Test Case 3:
23
Not Fascinating number
*/
