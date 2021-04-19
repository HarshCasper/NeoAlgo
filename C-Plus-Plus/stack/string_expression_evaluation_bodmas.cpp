/*
Evaluate string expression using BODMAS
==============================
Evaluate a string expression containing (,),+,-,/ and * using BODMAS rules
Application: Stack data structure
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

//Function to remove spaces from string and return trimmed string.
string removeSpaces(string &s){
	int n = s.length();
	string trimmed;

	for(int i = 0; i < n; i++){
		if(s[i] != ' '){
			trimmed.push_back(s[i]);
		}
	}
	return trimmed;
}

//In Expression containing only '*','/','+' and '-' '*' and '/' have the highest precedence followed by '+' and '-'
int precedence(char c){
	if(c == '*' || c == '/'){
		return 3;
	}
	else if(c == '+' || c == '-'){
		return 2;
	}
	else{
		return 1;
	}
}

//calculate function is used to calculate a value given two operandsand one operator
int calculate(int num1, int num2, char symbol){
	if(symbol == '*'){
		return num1 * num2;
	}
	else if(symbol == '/'){
		return num1 / num2;
	}
	else if(symbol == '+'){
		return num1 + num2;
	}
	else if(symbol == '-'){
		return num1 - num2;
	}
	return -1;
}

//Two stacks are used. 'values' stack is used to store the operands
//'operators' stack is used to hold the operators
int evaluate(string token){
	stack<int>values;
	stack<char>operators;
	int i;
	
	//get length of given expression
	int n = token.length();
	
	for(i = 0; i < n; i++){
		if(isdigit(token[i])){
			int value = 0;
			
			//there may be more than one digit number e.g(48+5) '48' has 2 digits
			while(i<n && isdigit(token[i])){
				value = value * 10 + (token[i] - '0');
				i++;
			}
			
			values.push(value);
			i--;
	
		}

		//if opening paranthesis is encontered push it in 'operators' stack
		else if(token[i] == '('){
			operators.push('(');
		}

		//If a closing paranthesis is encountered continue to evaluate the expression 
		//until an opening paranthesis is encountered
		else if(token[i] == ')'){
			while(!operators.empty() && operators.top()!='('){
				
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				//get the operator
				char symbol = operators.top();
				operators.pop();

				//calculate value 
				int calculated_value = calculate(val1, val2, symbol);

				values.push(calculated_value);
			}

			operators.pop();
		}

		//operator encountered
		else{
			//if 'operators' stack is empty simply push the operator
			if(operators.empty()){
				operators.push(token[i]);
			}
			else{
				//check precedence
				if(precedence(token[i]) > precedence(operators.top())){
					operators.push(token[i]);
				}
				//if precedence of current symbol is less than top of operator stack 
				//then evaluate expression
				else{
					while(!operators.empty() && (precedence(token[i]) <= precedence(operators.top())) ){

						int val2 = values.top();
						values.pop();
						
						int val1 = values.top();
						values.pop();
						
						char symbol = operators.top();
						operators.pop();
						
						int calculated_value = calculate(val1,val2,symbol);
						
						values.push(calculated_value);
					}
					operators.push(token[i]);
				}
			}
		}
	}
	
	//Expression is parsed now, evaluate remaining values
	while(!operators.empty()){
		int val2 = values.top();
		values.pop();

		int val1 = values.top();
		values.pop();
		
		char symbol = operators.top();
		operators.pop();
		
		int calculated_value = calculate(val1,val2,symbol);
		
		values.push(calculated_value);
	}
	
	//Evaluated expression value will be at the top of 'values' stack
	return values.top();
}

int main(){
	string s;
	getline(cin,s);
	string trimmed = removeSpaces(s);
	cout<<evaluate(trimmed)<<endl;
	return 0;
}

/*
Input:

((2+4)*2)/(2+4)

Output:

2

Input:

((7 * 3) + 2)/(1+2)

Output:
7

*/
