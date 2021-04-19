/*Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not.
Return true if the pattern is present and false otherwise.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

    bool search(TrieNode* root,string pattern){
  		if(pattern.size()==0){
            return true;
        }
        
        int index = pattern[0]-'a';
        TrieNode* child;
        if(root->children[index]==NULL){
            return false;
        }else{
            child = root->children[index];
        }
        
        bool smallans = search(child,pattern.substr(1));
        return smallans;
        
    }
    
    
	bool patternMatching(vector<string> vect, string pattern) {
		// Complete this function
		// Return true or false
		for(int i=0;i<vect.size();i++){
            string s  = vect[i];
            while(s.size()!=0){
                insertWord(s);
                s = s.substr(1);
            }
        }
        
        bool ans =  search(root,pattern);
        return ans;
        
	}
};

int main() {
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}
/*
SAMPLE INPUT :
4
abc def ghi cba
de

Sample Output :
true

Time Complexity: O(n)

*/
