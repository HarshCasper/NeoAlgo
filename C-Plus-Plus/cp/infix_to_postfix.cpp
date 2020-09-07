// Author: Prasad V Patil

/*
   C++ code for Conversion of infix expression to post fix expression.
*/

#include <bits/stdc++.h>

using namespace std;

//Function declarations

// Function to convert Infix expression to postfix
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter
//(letter or numeric digit) or not.
bool IsOperand(char C);

// Function to check whether a char is an opening parenthesis i.e '(' or '{' or '['
bool IsOpeningParentheses(char C);

// Function to check whether a char is an closing parenthesis i.e ')' or '}' or ']'
bool IsClosingParentheses(char C);

int main()
{
	string expression;
	cout<<"Enter Infix Expression \n";
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	cout<<"Output = "<<postfix<<"\n";
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++.
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for(int i = 0;i< expression.length();i++) {

		// Scanning each character from left.
		// If character is a delimiter, move on.
		if(expression[i] == ' ' || expression[i] == ',') continue;

		// Else if character is an operand then just append it in res string
		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		//If character is operator, check for Higher precedence operator in Stack top
		//till first opening bracket and pop all such operators
		//Finally push the current operator on the Stack
		else if(IsOperator(expression[i]))
		{
			while(!S.empty() && !IsOpeningParentheses(S.top())
            		&& HasHigherPrecedence(S.top(),expression[i]))
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}

		//If opening Parentheses simply push it on the Stack
		else if(IsOpeningParentheses(expression[i]))
		{
			S.push(expression[i]);
		}

        //If Closing Parentheses then pop all the operators and append to res string
        // until Stack top is opening Parentheses and finally one extra pop for Opening Parentheses
		else if(IsClosingParentheses(expression[i]))
		{
			while(!S.empty() && !IsOpeningParentheses(S.top())) {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

    //Finally pop and append all operators till Stack is not empty
	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
		return true;

	return false;
}

bool IsOpeningParentheses(char C)
{
    if(C == '(' || C == '{' || C=='[')
        return true ;
    return false;
}

bool IsClosingParentheses(char C)
{
    if(C == ')' || C == '}' || C==']')
        return true ;
    return false;
}
// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
	if(op == '^') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
		break ;
	case '*':
	case '/':
		weight = 2;
		break ;
	case '^':
		weight = 3;
		break ;
	}
	return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative.
	// return false, if right associative.
	// if operator is left-associative, left one should be given priority.
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}
