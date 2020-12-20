/*Simple Columnar Transposition Technique (Transposition Technique)

It is a type of transposition cipher technique which encrypts the plain text 
message into a cipher text by rearranging the characters of the 
plain text. The plain text is written row-wise and read column-wise.

Example:
Plain Text: TESSERACTCODING
Order of Columns: 2 3 1 0 4
Cipher Text: SCISTNEADTROECG

Plain Text: NEOALGO
Order of Columns: 3 0 1 4 2
Cipher Text: A1NGEOL1O1

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

string encrypt(string s){
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
	vector<int>order;  
	cout<<"Enter the order of repositioning columns: ";  //Example(1 0 2 3 4)
	int x;
	for(int i=0;i<col;i++){
		cin>>x;
		order.push_back(x);
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
	
    string s;
	cout<<"Enter the plain text: "; //(suggested with length greater than 5)
	cin>>s;
	cout<<encrypt(s);

}