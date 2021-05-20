//Given a string,print reverse of the string using stack
//Approach:-
//In stack,we know LIFO principle works.
//First,i create an empty stack,then i push each character of string in stack
//then,using for loop i popped out every single character.

#include<bits/stdc++.h>
using namespace std;

//function to reverse the string
void reverse(string &s)
{
	int i;
	stack<int> str;

	for(char ch:s){
        str.push(ch);
    }
    for(i=0;i<s.size();i++){
        s[i]=str.top();
        str.pop();
    } 
}

int main()
{
	cout<<"***********Program to reverse a string using stack***********"<<endl;
	string s;
	cout<<"Enter a string you want to reverse: ";
	cin>>s;
	reverse(s);
      cout<<"String After Reverse: ";
	cout<<s;
	return 0;
}

/*
Test Case 1:
Input :
***********Program to reverse a string using stack***********
Enter a string you want to reverse: Harshit
Output :
String After Reverse: tihsrah

Time Complexity : O(n), where n is the length of the input string.
Space Complexity : O(n) for stack.
*/
