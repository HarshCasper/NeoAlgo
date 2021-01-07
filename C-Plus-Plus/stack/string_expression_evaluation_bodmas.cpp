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

//Function to remove spaces from input string and return trimmed string
string removeSpaces(string&s){
	int n = s.length();
	string trimmed;

	for(int i=0; i<n; i++){
		if(s[i]!=' '){
			trimmed.push_back(s[i]);
		}
	}

	return trimmed;
}

//In Expression containing only '*','/','+' and '-'
//'*' and '/' have the highest precedence followed by
//'+' and '-'
int precedence(char c){
	if(c=='*' || c=='/'){
		return 3;
	}
	else if(c=='+' || c=='-'){
		return 2;
	}
	else{
		return 1;
	}
}

//calculate function is used to calculate a value given two operands
//and one operator
int calculate(int num1, int num2, char symbol){
	if(symbol=='*'){
		return num1*num2;
	}
	else if(symbol=='/'){
		return num1/num2;
	}
	else if(symbol=='+'){
		return num1+num2;
	}
	else if(symbol=='-'){
		return num1-num2;
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
	
	for(i=0; i<n; i++){
		if(isdigit(token[i])){//digit encountered
			int value = 0;
			while(i<n && isdigit(token[i])){//there may be more than one digit number e.g(48+5) '48' has 2 digits
				value = value*10 + (token[i]-'0');
				i++;
			}
			
			values.push(value);
			i--;//decrement i to avoid incrementing it 2 times as outer for loop also increments it
	
		}
		//if opening paranthesis is encontered simply push it in 'operators' stack
		else if(token[i]=='('){
			operators.push('(');
		}

		//If a closing paranthesis is encountered we have to evaluate the expression until an opening paranthesis is encountered
		//Assuming the expression is valid we are guaranteed to obtain an opening paranthesis '('
		else if(token[i]==')'){
			while(!operators.empty() && operators.top()!='('){
				//since stack stores values in Last In First Out(LIFO) fashion the top value in the 'values' stack is the second operand 
				//e.g if expression is (4+5), the top value in stack will be 5 which is the second operand and 4 is the first operand
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				//get the operator from operator stack
				char symbol = operators.top();
				operators.pop();

				//we now have 2 operands and one operator therefore we can calculate the value and store the calculated value back into 
				//the 'values' stack for futher evaluation
				int calculated_value = calculate(val1, val2, symbol);

				values.push(calculated_value);
			}

			//pop opening brace as it is evaluated
			operators.pop();
		}
		
		else{//operator encountered
			//if 'operators' stack is empty simply push the operator
			if(operators.empty()){
				operators.push(token[i]);
			}
			else{
				//check precedence
				//if precedence of current symbol is more than symbol at top of 'operators' stack then simply push it
				if(precedence(token[i]) > precedence(operators.top())){
					operators.push(token[i]);
				}
				//if precedence of current symbol is less than top of operator stack then evaluate expression
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
					//After the above while loop is over either the 'operators' stack is empty or the current operator in  
					//'operators' stack has lower precedence than operator of given string so we can safely push it
					operators.push(token[i]);
				}
			}
		}
	}
	
	//After the string is parsed if operators stack is still not empty this means the expression is not fully calculated. 
	//Note that size of operators stack will always be less than size of 'values' stack.
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
	
	//Finally the evaluated expression value will be at the top of 'values' stack
	return values.top();
}

int main(){
	string s;
	getline(cin,s);
	//remove spaces from string
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
