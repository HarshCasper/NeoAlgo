/* Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter. */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
  public:
  char data;
  TrieNode ** children;
  bool isTerminal;

  TrieNode(char data) {
    this -> data = data;
    children = new TrieNode * [26];
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie {
  TrieNode * root;

  public:
    int count;

  Trie() {
    this -> count = 0;
    root = new TrieNode('\0');
  }

  bool insertWord(TrieNode * root, string word) {

    // Base case

    if (word.size() == 0) {
      if (!root -> isTerminal) {
        root -> isTerminal = true;
        return true;
      } else {
        return false;
      }
    }

    // Small Calculation

    int index = word[0] - 'a';
    TrieNode * child;
    if (root -> children[index] != NULL) {
      child = root -> children[index];
    } else {
      child = new TrieNode(word[0]);
      root -> children[index] = child;
    }

    // Recursive call

    return insertWord(child, word.substr(1));
  }

  // For user

  void insertWord(string word) {
    if (insertWord(root, word)) {
      this -> count++;
    }
  }

  TrieNode * complete(TrieNode * root, string s, string pattern) {
    if (s.size() == 0) {
      if (root -> isTerminal == true) {
        cout << pattern << endl;
      }
      return root;
    }

    TrieNode * child;
    int index = s[0] - 'a';

    if (root -> children[index] != NULL) {
      child = root -> children[index];
    } else {
      return NULL;
    }

    TrieNode * ans = complete(child, s.substr(1), pattern);
    return ans;

  }

  void print(TrieNode * root, string s) {
    for (int i = 0; i < 26; i++) {
      TrieNode * child = root -> children[i];
      if (child != NULL) {
        if (child -> isTerminal == true) {
          string temp = s;
          cout << temp << child -> data << endl;
          child -> isTerminal = false;
          temp = temp + child -> data;
          print(child, temp);
        } else {
          string temp = s;
          temp = temp + child -> data;
          print(child, temp);
        }
      }
    }
  }

  void autoComplete(vector < string > input, string pattern) {

    // Print the output as specified in question

    for (int i = 0; i < input.size(); i++) {
      insertWord(input[i]);
    }

    TrieNode * ans = complete(root, pattern, pattern);
    if (ans != NULL) {
      print(ans, pattern);
    }

  }
};

int main() {
  Trie t;
  int n;
  cout << "enter number of complete words to be stored in trie" << endl;
  cin >> n;

  vector < string > vect;
  cout << " enter the words " << endl;
  for (int i = 0; i < n; ++i) {
    string word;
    cin >> word;
    vect.push_back(word);
  }

  string pattern;
  cout << " enter the incomplete word" << endl;
  cin >> pattern;
  cout << "the words that starting from "<< pattern<< " are"<<endl;
  t.autoComplete(vect, pattern); 
}

/*

TIme Complexity - O(N*M)
Space Complexity - O(N*M)
where N is the number of words in trie and M is the average word length.

Sample Input 1- 
enter number of complete words to be stored in trie
7
enter the words 
do dont no not note notes den
enter the incomplete word
no

Sample output 1 -
the words that starting from no are
no
not
note
notes
*/
