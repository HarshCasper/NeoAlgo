/*
Check for balanced parenthesis
==============================
Given an expression containing parenthesis, check if it is well-formed or balanced.
A balanced parenthesis means for every opening bracket there must be equivalent closing brackets.
Application: Stack data structure
Author: @gargvader
Edit by: @Mohim-Singla
*/
#include <iostream>
#include <stack>
using namespace std;

/*Function for Parenthesis matching.*/
void parenthcheck(string s)
{
	/*Initializing a vector "oper"*/
	stack<char> oper;
	for(int i = 0; i < s.length(); i++)
	{
		/*Open parenthesis is always pushed into the stack*/
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
       		{
         		oper.push(s[i]);
        	}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
     		{
           		//Closed parenthesis encountered must be balanced by an open parenthesis already
			//present in the stack
            		if (oper.empty())
            		{
                		cout << "Unbalanced Parenthesis";
                		return;
            		}
            		else
            		{
                		//Stack contains open parenthesis, one of which has been balanced
				//Pop one parenthesis out
                		if ((s[i] == ')' && oper.top() == '(') || (s[i] == ']' && oper.top() == '[') || (s[i] == '}' && oper.top() == '{'))
                    			oper.pop();
                		else
                		{
                    			/*Stack contains no open parenthesis. So closed parenthesis cannot be balanced*/
                    			cout<< "Unbalanced Parenthesis";
                    			return;
                		}
        		}
        	}
        	else
        	{
            		continue;
        	}
	}
    	/*Check if we have open parenthesis remaining*/
    	if (oper.empty())
    	{
        	cout<< "Balanced Parenthesis";
    	}
    	else
    	{
		cout<< "Unbalanced Parenthesis";
    	}
}

/*Main Function*/
int main()
{
	/*Input the string*/
	string s;
	cout<< "enter string: ";
	cin>> s;
	/*Calling out the function*/
	parenthcheck(s);
}
/*
-------------------------------
Test case 1:
Input:
((a+b)+(c-d+f))
Output:
Balanced Parenthesis
-------------------------------
Test case 2:
Input:
{(a+b)+(c-d+f)]}
Output:
Unbalanced Parenthesis
---------------------------------
Test case 3:
Input:
(a+b)*{c*[a+b*(c+d)}]
Output:
Unbalanced Parenthesis
--------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/
