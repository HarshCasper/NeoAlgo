#include<bits/stdc++.h>
using namespace std;

//Mapping one plain-text alphabet to more than one cipher-text alphabet.
void mapping(vector<vector<char> > &code) {    
	code[0].push_back('Q');code[0].push_back('4');
	code[1].push_back('W');
	code[2].push_back('E');
	code[3].push_back('R');
	code[4].push_back('T');code[4].push_back('5');code[4].push_back('9');code[4].push_back('0');
	code[5].push_back('Y');
	code[6].push_back('U');
	code[7].push_back('I');
	code[8].push_back('O');code[8].push_back('8');
	code[9].push_back('P');
	code[10].push_back('A');
	code[11].push_back('S');
	code[12].push_back('D');
	code[13].push_back('F');code[13].push_back('7');
	code[14].push_back('G');code[14].push_back('2');
	code[15].push_back('H');
	code[16].push_back('J');
	code[17].push_back('K');
	code[18].push_back('L');code[18].push_back('1');
	code[19].push_back('Z');code[19].push_back('6');
	code[20].push_back('X');
	code[21].push_back('C');
	code[22].push_back('V');
	code[23].push_back('B');
	code[24].push_back('N');
	code[25].push_back('M');	
}

/* Encodes characters of plain text by one of the 
several different cipher text letters using a map. */
string encode(string plain) {
	
	vector<vector<char> >code(26);
	mapping(code);
	string encrypted = "";
	int n = plain.length();
	for(int i = 0;i < n; ++i) {
		//if lowercase character
		if(plain[i] >= 97) {
			int num = (rand() % (code[plain[i] - 97].size()));
			
			if(code[plain[i]-97][num] >= 65)
				encrypted = encrypted+char(code[plain[i]-97][num]- 65 + 97);
			else
				encrypted = encrypted+code[plain[i]-97][num];
		}
		//uppercase letter
		else {
			int num = (rand() % (code[plain[i]-65].size()));
			encrypted = encrypted+code[plain[i]-65][num];
		}
	}
	
	return encrypted;
}

int main(){
	
	vector<vector<char> >code(26);
	mapping(code);
	
	string plain,encrypt;
	cout<<"Enter the plain text: ";
	cin>>plain;
	
	encrypt = encode(plain);
	cout<<"Cipher Text: "<<encrypt<<endl;
	
}

/* Mapping used: 
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
Q W E R T Y U I O P A S D F G H J K L Z X C V B N M
4       5       8         7 2       1 6            
        9                                          
        0                         

Example:
Plain Text : TESSERACTCODING
Cipher Text: 60LL5KQEZE2R87U

Plain Text : NeoAlgo
Cipher Text: 70gQsug

Time Complexity: O(n)
Space Complexity: O(1)                  
*/