#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffmanCodes(vector<char> data, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < data.size(); i++)
        pq.push(new Node(data[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    printCodes(pq.top(), "");
}

int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    huffmanCodes(data, freq);
    return 0;
}
