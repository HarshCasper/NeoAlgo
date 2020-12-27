//SIMPLE COLUMNAR MULTIPLE ROUNDS TRANSPOSITION TECHNIQUE
#include<bits/stdc++.h>
using namespace std;

/* Encrypt the plain text message into a cipher text by 
rearranging the characters of the plain text. The plain 
text is written row-wise and read column-wise.This 
procedure is chained and carried out k times. */
string encrypt(string s,vector<int> &order) {
	
	float n = s.length();
	int row = ceil(n/5),col = 5;
	char arr[row][col];
	for(int i = 0;i < row; ++i) {
		for(int j = 0;j < col; ++j) {
			if((i * col + j) >= s.length()) {
				//1 is the bogus character  
				arr[i][j] = '1' ;
			}
			else
				arr[i][j] = s[i*col+j];
		}
	}
	string encString = "";
	for(int i = 0;i < col; ++i) {
		for(int j = 0;j < row; ++j) {
			encString += arr[j][order[i]];
		}
	}
	return encString;
}

int main() {
	
	string s;
	cout<<"Enter the plain text: "; 
	cin>>s;
	int rounds;
	cout<<"Enter the number of rounds: ";
	cin>>rounds;
	
	vector<int>order(5);
	//For example order of repositioning columns could be 1 0 2 3 4
	cout<<"Enter the order of repositioning columns: ";  
	for(int i = 0;i < 5;i++) {
		cin>>order[i];
	}

	//Multiple Rounds
	for(int i = 0;i < rounds; ++i) {
		s = encrypt(s,order);
	}
	cout<<s;
	
}

/*
Example:
Plain Text: TESSERACTCODING
No. of rounds: 3
Order of Columns: 2 3 0 1 4
Cipher Text: ENTSAEICTRSDOCG

Plain Text: NEOALGO
Order of Columns: 3 0 1 4 2
Cipher Text: LAOEN1O1G1

Time Complexity: O(n*k)
Space Complexity: O(1)
*/
