/*Tries are tree based structures used for efficient 
retrieval of key form huge set of strings.

This is a basic implementation of Trie in which strings are inserted and 
then there are some queries to find if strings are present in trie or not.

Time Complexity for insert and find function: 
O(l) where l is the length of word. 
Space complexity: O(n*m) where n is number of keys 
and m=max(l) i.e max length of input strings.*/

#include<bits/stdc++.h>
using namespace std;
//Trie Node
class Node{
public:
	char data;
	//to store children of node
	unordered_map<char,Node*> children;
	bool terminal;
	Node(char d){
		data=d;
		terminal=false;
	}
};

class Trie{
Node*root;
public:
	Trie(){
		root=new Node('\0');
	}
	//to insert strings in Trie
	void insert(string w){
		Node*temp=root;
		for(int i=0;w[i]!='\0';i++){
			char ch=w[i];
			if(temp->children.count(ch)){
				temp=temp->children[ch];
			}
			else{
				Node*n=new Node(ch);
				temp->children[ch]=n;
				temp=n;
			}
		}
		temp->terminal=true;
	}
	//To find if string is present or not
	bool find(string w){
		Node*temp=root;
		for(int i=0;w[i]!='\0';i++){
			char ch=w[i];
			if(temp->children.count(ch)==0){
				return false;
			}
			else{
				temp=temp->children[ch];
			}
		}
		return temp->terminal;
	}
	//to delete a string from trie
	void deletion(string w){
		Node*temp=root;
		for(int i=0;w[i]!='\0';i++){
			char ch=w[i];
			if(temp->children.count(ch)==0){
				return;
			}
			else{
				temp=temp->children[ch];
			}
		}
		temp->terminal=false;
	}
};

int main(){
    //initialize trie
	Trie T;
	cout<<"Enter number of strings:"<<endl;
	int n;
	cin>>n;
	string*arr=new string[n];
	cout<<"Enter the strings:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		T.insert(arr[i]);
	}
	cout<<"Enter number of queries to find if strings are present or not"<<endl;
	int q;
	cin>>q;
	cout<<"Enter a string for each query:"<<endl;
	while(q--){
		string s;
		cin>>s;
		if(T.find(s)){
			//String is present in set of strings
			cout<<"The given string is present in the set of strings"<<endl;
		}
		else{
			cout<<"The given string is absent in the set of strings"<<endl;
		}
	}
	//for deletion
	string str;
	cin>>str;
	T.deletion(str);
	if(T.find(str)){
		//String is present in set of strings
		cout<<"The given string is present in the set of strings"<<endl;
		}
	else{
		cout<<"The given string is absent in the set of strings"<<endl;
	}
}

/*Sample input:
5
"a"
"hello"
"HEllo"
"apple"
"news"
6
"a"
"hello"
"HEllo"
"not"
"new"
"news"
"news"

Sample output:
The given string is present in the set of strings
The given string is present in the set of strings
The given string is present in the set of strings
The given string is absent in the set of strings
The given string is absent in the set of strings
The given string is present in the set of strings
The given string is absent in the set of strings
*/

