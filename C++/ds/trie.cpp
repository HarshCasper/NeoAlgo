#include<bits/stdc++.h>
using namespace std;
// trie structure
struct trie {
  struct trie *children[26];
  bool isend;
  trie () {
    memset(children, NULL, sizeof(children));
    isend = false;
  }
};

struct trie* root;
// insert algorithm in trie
void insert( string s1) {
  struct trie *curr = root;
  for (char ch : s1) {
    int currindex = ch - 'a';
    if (curr->children[currindex] == NULL) {
      curr->children[currindex] = new trie;
    }
    curr = curr->children[currindex];
  }
  curr->isend = true;
}
// search algorithm in trie
bool search(string s1) {
  struct trie *curr = root;
  for (char ch : s1) {
    int currindex = ch - 'a';
    if (curr->children[currindex] == NULL)
      return false;
    curr = curr->children[currindex];
  }
  return curr->isend;
}

int main() {
  root = new trie;
  insert("alex");
  insert("eric");
  insert("daniel");
  insert("zee");
  insert("zoi");
  insert("jonathon");
  insert("darek");
  insert("amly");
  string result = search("darek") ? "Found" : "Not Found";
  cout << result << '\n';
  return 0;
}
