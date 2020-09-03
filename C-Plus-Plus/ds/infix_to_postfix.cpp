#include<iostream>
#include<stack>
#include<string>

using namespace std;

string InfixToPostfix(string expression);

int HasHigherPrecedence(char operator1, char operator2);

bool IsOperator(char C);

bool IsOperand(char C);

bool IsOpeningParentheses(char C);

bool IsClosingParentheses(char C);

int main()
{
	string expression;
	cout<<"Enter Infix Expression \n";
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	cout<<"Output = "<<postfix<<"\n";
}

string InfixToPostfix(string expression)
{
	stack<char> S;
	string postfix = "";
	for(int i = 0;i< expression.length();i++) {

		if(expression[i] == ' ' || expression[i] == ',') continue;

		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

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

		else if(IsOpeningParentheses(expression[i]))
		{
			S.push(expression[i]);
		}

		else if(IsClosingParentheses(expression[i]))
		{
			while(!S.empty() && !IsOpeningParentheses(S.top())) {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

bool IsOperand(char C)
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

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
int IsRightAssociative(char op)
{
	if(op == '^') return true;
	return false;
}

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

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}
