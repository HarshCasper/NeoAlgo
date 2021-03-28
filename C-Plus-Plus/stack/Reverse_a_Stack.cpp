/* 
Reverse a Stack
Out of the two given stacks, one is populated and the other one is empty. Write a function that reverses the populated stack using the one which is empty.
*/

#include <iostream>
#include <stack>
#include <stack>
using namespace std;
void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
    if(input.size()==1||input.size()==0){
        return;
    }   
    
	int x=input.top();
    input.pop();
    
    reverseStack(input,extra);

    while(!input.empty()){
        extra.push(input.top());
    	input.pop();    
    }

    input.push(x);

    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
    

    return;
}


int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}


/*
Sample Input 1:
6
1 2 3 4 5 10
Sample Output 1:
1 2 3 4 5 10
*/
