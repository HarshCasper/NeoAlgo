/**
 * @author ujjawal-199
 * @file
 * Given string S of size N of character, generate all the possible subsequences of the string.
 *	The total number of subseuences of a string in 2^n - 1, where n is the size of the string.
 *  Input :
 *  Testcase1:
    "abc" 3                 =>  where 3 is the size of an array and "abc" is the original string.

*   Testcase2:
    "neo" 3                   =>  where 3 is the size of an array and "neo" is the original string.
    
* Output :
    a,b,c,ab,ac,bc, abc     =>  space seperated subsequences of the given string.
    n,e,o,ne,no,eo,neo		=>  space seperated subsequences of the given string.
* Approach :
	1. Find the total number of subsequences using size = pow(2,n).
	2. Iterate over the entire size. 
	3. Create a separate function say, sequences with the initial string and the iteration index. sequences(s,i);
	Sequences(s,i) :- 
    1. Get the position of rightmost set bit in i using bit masking. pos = log2(i & -i) + 1; 
	2. Append the character corresponding to that bit from the string to the subsequence.
	3. Reset the bit at the given positon.
	4. Repeat steps 1-3 until no set bit remains.

	Store the result in a map of containing set of strings based on the length of the subsequence so that it can be printed lexographically.
	Example -  s = "abc"
	Iteration 1 :- sequences(s,1)
	001 => abc . Only c corresponds to bit 1. So, subsequence = c
	return c;
	
	Iteration 2: - sequences(s,2)
	010 => only b corresponds to bit 1. So, subsequence = b
	
	Iteration 5 :- sequences(s,5)
	
	101 => Rightmost bit is at position 1, so append c to the subsequences sub = c. Reset pos 1, => 100
	100 => Rightmost bit is at position 3, so append a to the subsequences sub = ac. Reset pos 1, => 000
	000 => No more set bits return sub = ac;
*/

#include<bits/stdc++.h>
using namespace std;

//Printing all subsequences of a given string
string sequences(string s, int i){
	string curr = "";
	while(i){
		int pos = log2(i & -i)+1;
		curr = s[pos-1] + curr;
		i = (i & ~(1 << (pos-1)));
	}
	reverse(curr.begin(),curr.end());
	return curr;
}
void possibleSubsequences(string s){
	int n = s.size();
	int limit = pow(2,n);
	map<int,set<string> >m;
	for(int i = 1; i < limit; i++){
		string sub = sequences(s,i);
		m[sub.size()].insert(sub);
	}
	map<int, set<string> >::iterator it;
	set<string>::iterator i;
	for(it = m.begin(); it != m.end(); ++it){
		for(i = it->second.begin(); i != it->second.end(); ++i)
			cout << *i << " ";
		cout << "\n";
	}
}
void test() {
    cout << "Test 1" << endl;
    string a = "abc";
    possibleSubsequences(a);
    cout << "Test 1 passed\n ===================== \n";

    cout << "Test 2" << endl;
    string b = "neo";
    possibleSubsequences(b);
    cout << "Test 2 passed\n ===================== \n";
}
int main(){
	test();
	return 0;
}
