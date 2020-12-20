/*Simple Columnar Transposition Technique with multiple rounds(Transposition Technique)

It is a type of transposition cipher technique which encrypts the plain text 
message into a cipher text by rearranging the characters of the 
plain text. The plain text is written row-wise and read column-wise.
This procedure is chained and carried out k times.

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

#include<bits/stdc++.h>
using namespace std;

string encrypt(string s,vector<int> &order){
	
	float n = s.length();
	int row = ceil(n/5),col=5;
	char arr[row][col];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if((i*col+j)>=s.length()){
				arr[i][j] = '1' ;          //1 is the boogus character  
			}
			else
			arr[i][j] = s[i*col+j];
			
		}
	}
	string encString="";
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++){
			encString+=arr[j][order[i]];
		}	
	}
	return encString;
}

int main(){
	
    string s;int rounds;vector<int>order(5); 
	cout<<"Enter the plain text: "; //(suggested with length greater than 5)
	cin>>s;
	
	cout<<"Enter the number of rounds: ";
	cin>>rounds;
	
	cout<<"Enter the order of repositioning columns: ";  //Example(1 0 2 3 4)
	for(int i=0;i<5;i++){
		cin>>order[i];
	}
	//MULTIPLE ROUNDS
	for(int i=0;i<rounds;i++){
		s = encrypt(s,order);
	}
	cout<<s;
	
}