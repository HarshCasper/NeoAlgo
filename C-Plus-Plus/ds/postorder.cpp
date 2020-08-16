#include <iostream>
#include <cstdlib>
#include<stack>
using namespace std;

struct tree {               // treenode
    int data;
    tree *Left, *Right;
};

tree* root;
class Binarytree {
public:
    Binarytree();
    void create(int);
    tree* insert(tree*, tree*);
    void postnonrec(tree*);
    void postraversal(tree*);
};
Binarytree::Binarytree()
{
    root = NULL;
}

tree* Binarytree::insert(tree* temp, tree* newnode)
{
    if (temp == NULL) {
        temp = newnode;
    }
    else if (temp->data < newnode->data) {
        insert(temp->Right, newnode);
        if (temp->Right == NULL)
            temp->Right = newnode;
    }
    else {
        insert(temp->Left, newnode);
        if (temp->Left == NULL)
            temp->Left = newnode;
    }
    return temp;
}
void Binarytree::create(int n)
{
    tree *temp = root, *newnode;
    newnode = new tree;
    newnode->Left = NULL;
    newnode->Right = NULL;
    newnode->data = n;
    root = insert(temp, newnode);
}
void Binarytree::postnonrec(tree* t = root) // non recursive traversal
{
        tree *temp;
        stack<tree *> s;
        temp = root;
        while(true){
            if(temp != NULL){
                s.push(temp);
                temp = temp->Left;   //visting left subtree
            }
            else
            {
                if(s.empty()) break;
                temp = s.top()->Right;
                if(temp == NULL){
                    tree *last = NULL;
                    while(!s.empty() && s.top()->Right == last){
                        last = s.top();
                        s.pop();
                        cout<<last->data<<" ";
                    }
                }
            }
        }
            
        
}

void Binarytree::postraversal(tree* t = root) //recursive traversal
{
    if (root == NULL) {
        cout << "Tree is empty";
    }
    else if (t != NULL) {
        postraversal(t->Left);
        postraversal(t->Right);
        cout << t->data << " ";
    }
}

int main()
{
    Binarytree bt;
    int choice, n, key;
    while (1) {
        cout << "\n\t1. Insert\n\t2. Non recursive Post Traversal\n\t3. Postorder Traversal\n\t4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter Node to be inserted: ";
            cin >> n;
            bt.create(n);
            break;
        case 2:
            cout << endl;
            bt.postnonrec();
            break;
        case 3:
            cout << endl;
            bt.postraversal();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}