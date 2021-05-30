/*
	In this solution we insert value in a vector or array 
	after expression is inserted

	We iterate from back of array 
	if value is operand we calulate result between operands
		we get operands by popping two latest values from stack
		Insert result back in stack

	else we just insert value in stack

	In last if size of stack is one it is fully solved 

*/

#include <bits/stdc++.h>
using namespace std;

stack<int> st;
//We take stack for storing operands 

int apply_operator(char op){

	int operand1,operand2;

	/*
		pop a value from stack storing in operand 1 
		and popped again for operand 2  
	*/

	operand1=st.top();
		st.pop();
	operand2=st.top();
		st.pop();

	/*
		After we got operands 
		We apply operator according to its operator
		returned result
	*/


	if( op == '*' )
		return operand1 * operand2 ;

	// We cannot divide anything from zero
	else if( op == '/' and operand2 != 0 ) 
		return operand1 / operand2 ;

	else if( op == '+' )
		return operand1 + operand2 ;

	else if( op == '-' )
		return operand1 - operand2 ;

	else
		return -1; 
		 //for the cases like diveded by 0 or wrong operator 
	
}



string evaluate_infix_expression( vector <char> vec ){   
	// funtion will return a string type 

	int temp;
	
	for ( int i = vec.size()-1 ; i >= 0 ; i-- )
	{
		if (vec[i] == '*' or vec[i] == '/' or vec[i] == '+' or vec[i] == '-' ){

			temp = apply_operator(vec[i]);

			/*
				After we got result in apply_operator()
				We now store its value in temp variable if .
				temp == -1 it is invalid we return invalid 
				else we directly insert result value in stack 
			*/

			if( temp == -1 )
				return "Expression have some invalid case ";
			
			st.push( temp );  
			//inserting temp result got from apply_operator() in stack

		}
		else
			st.push( vec[i] - '0' );
	}

	/*
		If size of stack is 1 then it have only operand which is result 
		Else expression was invalid or carry some wrong values
	*/

	if ( st.size() == 1 )

		return to_string( st.top() );
	

	else

		return "Expression is invalid ";

}



// Driver code
int main(){

	int len;
	vector<char> vec ;
	// For taking input of expression 
	// We can also use string in place of vector

	cout<<" Enter length of expression : \n";
	cin>> len;

	for( int i = 0 ; i < len ; i++ )
	{
		char temp;
		cin>> temp;
		vec.push_back( temp );  
		// Inserting value in vector vec
	}

	cout<< " Result after evaluating Expression is : " << evaluate_infix_expression( vec ); 
	//Calling funtion to evaluate expression 

}


/*


Time complexity : O(n)
Space complexity : O(n)

....................................

Test Case 1 : 
7
+ 2 * 3 / 4 2

Result : 8

....................................

Test Case 2 :
5
+ 2 / 2 0

Result : Expression have some invalid case

....................................


Author : Subodh Siddharth

*/