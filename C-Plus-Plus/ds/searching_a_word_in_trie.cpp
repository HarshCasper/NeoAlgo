/*
A trie is a tree and each node in it contains the number of pointers equal to the number of
characters of the alphabet. For example, if we assume that all the strings are formed with English
alphabet characters “a” to “z” then each node of the trie contains 26 pointers.
*/

#include<map>
#include<string>
#include<queue>
#include<list>
using namespace std;

class node{
public:

	char data;
	map<char,node*> m;
	bool is_terminal;

	node(char c){
		data = c;
		is_terminal = false;
	}
	
};

class Trie{
    node* root;
public:

	Trie(){
		root = new node('\0');
	}

	void Addword(char word[]){
		node* temp = root;

		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			//if not present
			if(temp->m.count(ch)==0){				
				// create link
                node* child = new node(ch);
                temp->m[ch] = child;				
                temp = child;
			}
			else{
				// next address
				temp = temp->m[ch];				

			}
		}
		// last node
		temp->is_terminal = true;				
	}

	bool search(char word[]){

		node* temp = root;

		for(int i=0;word[i]!='\0';i++){

			char ch = word[i];
			// if present 
			if(temp->m.count(ch)==1){				
                 temp = temp->m[ch];
			}
			else{		
			 	// not present		
               return false;
			}
			
		}
	// not always at last node
    return temp->is_terminal;				
	}


};

int main()
{
	Trie T;
	T.Addword("adf");
	T.Addword("not");
	T.Addword("nott");
	
	int n;
	cin>>n;
	char word[n];
	cin >> word;



	cout << boolalpha<<T.search(word);
	
	return 0;
}

/* 

	Test Case :

	Input : adf
	Output : true

	Time Complexity : O(L), where L is the length of the string to be searched.
	Time Complexity : O(1)

*/


