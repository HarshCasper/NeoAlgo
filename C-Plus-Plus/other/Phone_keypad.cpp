/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
*/
#include<bits/stdc++.h>
using namespace std;

void printKeypad_rec(int num, string output){
    string index[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(num == 0){
        cout << output <<endl;
        return;
    }
    
    int rem = num%10;
    int first = num/10;
    if(rem == 7 || rem == 9){
        printKeypad_rec(first, index[rem - 2][0] + output);
		printKeypad_rec(first, index[rem - 2][1] + output);
        printKeypad_rec(first, index[rem - 2][2] + output);
        printKeypad_rec(first, index[rem - 2][3] + output);
    }
    else{
        printKeypad_rec(first, index[rem - 2][0] + output);
		printKeypad_rec(first, index[rem - 2][1] + output);
        printKeypad_rec(first, index[rem - 2][2] + output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    
    string output = "";
    printKeypad_rec(num, output);
}

int main(){
    	int num;
	cout<<"Enter the integer for which you want the combinations of keypad: ";
	//take input of integer
    	cin >> num;
	cout<<"All the combinations of the keypad for given input integer are: "<<endl;
    	printKeypad(num);
	//prints all the combinations of the keypad for given input integer
    	return 0;
}



/*
Sample input: 
Enter the integer for which you want the combinations of keypad: 32
Sample output:
All the combinations of the keypad for given input integer are: 
da
ea
fa
db
eb
fb
dc
ec
fc

Time complexity: O(4^n)
Space complexity: O(1)
*/
