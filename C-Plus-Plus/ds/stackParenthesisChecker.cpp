#include <iostream>
#include<stack>
using namespace std;

// returns true if opening parenthesis
bool isOpening(char c){
    return c=='('||c=='['||c=='{';
}

// returns false if closing parenthesis
bool isClosing(char c){
    return c==')'||c==']'||c=='}';
}

//returs the corresponding opening parenthesis of a closing parenthesis
char makeOpening(char c){
    if(c==')')
        return '(';
    else if(c==']')
        return '[';
    else if(c=='}')
        return '{';
}

// function to check if input is balanced
bool checkBalanced(char *exp) {
    stack<char>s;
    int i=0;
    while(exp[i]!='\0'){
        if(isOpening(exp[i])){
            s.push(exp[i]);
        }
        if(isClosing(exp[i])){
            if(s.empty())           //if not an opening bracket in  the beginning
                return false;
            if(makeOpening(exp[i])==s.top()){  // undefined behaviour of top if stack empty
                s.pop();
            }else
                return false;
        }
        i++;
    }
    if(s.empty())
        return true;
    else
        return false;

}
int main() {
    char input[100000];
    cout<<"Enter input\n";
    cin >> input;
    cout<<"Are the parenthesis balanced?\n";
    if(checkBalanced(input)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}

