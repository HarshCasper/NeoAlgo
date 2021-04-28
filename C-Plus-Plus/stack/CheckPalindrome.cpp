/*Check if a given string is a
palindrome or not using stacks*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

void CheckPalindrome(string s){
    stack<char> st;
    /*Push each string character onto the stack.
    This stack will have string characters in reverse order
    from top to bottom*/
    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
    }
    bool flag = true;
    /*While traversing the string, take the top element
    from the stack(which will be the last element
    of string) and compare it with string's characters
    starting from s[0].*/
    for(int i=0; i<s.length(); i++){
        char x = st.top();
        /*if characters from stack and string don't match
        then mark flag as false*/
        if(x!=s[i]){
            flag = false;
            break;
        }
        //pop to got the next element of stack
        st.pop();
    }
    if(flag){
        cout<<"'"<<s<<"'"<<" is a palindrome string"<<endl;
    }
    else{
        cout<<"'"<<s<<"'"<<" is not a palindrome string"<<endl;
    }
}

int main(){
   string s;
   cout<<"Enter a string : ";
   cin>>s;
   CheckPalindrome(s);
   return 0;
}

/* SAMPLE TEST CASES :
-----------------------------------
Test 1:

Enter a string : Hello
'Hello' is not a palindrome string
-----------------------------------
Test 2:

Enter a string : abaCaba
'abaCaba' is a palindrome string
-----------------------------------
Time complexity : O(n)
Space complexity : O(n)
*/
