
#include<bits/stdc++.h>

using namespace std;

string getString(int d){
    if(d == 2){
        return "abc";
    }
    if(d == 3){
        return "def";
    }
    if(d == 4){
        return "ghi";
    }
    if(d == 5){
        return "jkl";
    }
    if(d == 6){
        return "mno";
    }
    if(d == 7){
        return "pqrs";
    }
    if(d == 8){
        return "tuv";
    }
    if(d == 9){
        return "wxyz";
    }
    return " ";
    
}

void printKeypad(int n, string outputSoFar) {
    if(n == 0) {
        cout << outputSoFar << endl;
        return;
    }

    int lastDigit = n % 10;
    int smallNumber = n / 10;
    string options = getString(lastDigit);

    for(int i = 0; i < options.size(); i++) {
        printKeypad(smallNumber, options[i] + outputSoFar);
    }
}
int main(){
    
    int n;
    cin >> n;

    printKeypad(n, "");
    cout << endl;
    return 0;
}