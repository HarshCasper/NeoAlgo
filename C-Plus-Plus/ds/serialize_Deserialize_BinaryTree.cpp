/*
   ------------------SERIALIZE AND DESERIALIZE A BINARY TREE----------------------------
   
   Serialization is the process of converting a data structure or object into a sequence of bits so 
   that it can be stored in a file or memory buffer, or transmitted across a network connection link to 
   be reconstructed later in the same or another computer environment.

   PROBLEM  - Given a Binary Tree and serialize it into a string which contains information of all the nodes 
              of the binary tree - Serialization
              Next you are given the string and you have to get the Binary tree out of that string - Deserialization

   Example -       1
                /     \
               2       3
                     /   \
                    4     5
            After serialization return string  "1,2,3,null,null,4,5"
            and after deserialization get the tree back rooted at 1;

    Approach- 
         The problem can be easily approached using Level order traversal of the binary tree 
         maintaing some checks along with
*/

#include <bits/stdc++.h>
using namespace std;

// the Binary Tree Class with a templater
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

// -----------------------------TAKE INPUT FNCTION TO INPUT THE TREE-------------------
BinaryTreeNode<int> *TakeinputLevelWise()
{
    int data;
    cout << "enter the root data :" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> nodes;
    nodes.push(root);
    while (nodes.size() != 0)
    {
        BinaryTreeNode<int> *front = nodes.front();
        nodes.pop();
        int leftchild;
        int rightchild;
        cout << "Enter the left child of " << front->data << ":" << endl;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTreeNode<int> *LChild = new BinaryTreeNode<int>(leftchild);
            front->left = LChild;
            nodes.push(LChild);
        }
        cout << " Enter the right Child of " << front->data << ":" << endl;
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTreeNode<int> *RChild = new BinaryTreeNode<int>(rightchild);
            front->right = RChild;
            nodes.push(RChild);
        }
    }

    return root;
}
//--------------------------FUNCTION TO PRINT THE TREE---------------------------------------
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> nodes;
    nodes.push(root);
    while (nodes.size() != 0)
    {
        BinaryTreeNode<int> *front = nodes.front();
        cout << front->data << ":";
        nodes.pop();
        if (front->left)
        {
            nodes.push(front->left);
            cout << "L:" << front->left->data;
        }
        if (front->right)
        {
            nodes.push(front->right);
            cout << "R:" << front->right->data;
        }
        cout << endl;
    }
}

// -----------------------------SERIALIZE THE BINARY TREE---------------------------------

string serialize(BinaryTreeNode<int> *root)
{
    string rez;
    if (root)
    {
        // using the level order traversal of the binary tree
        queue<BinaryTreeNode<int> *> q;
        q.push(root);
        // add the root value to the res
        rez += to_string(root->data) + ',';

        while (!q.empty())
        {
            int n = q.size();
            string tmpstr = "";
            while (n--)
            {
                BinaryTreeNode<int> *tmp;
                tmp = q.front();
                q.pop();
                if (tmp->left)
                {
                    q.push(tmp->left);
                    tmpstr += to_string(tmp->left->data) + ',';
                }
                // if the left or right is null then insert the "null"
                else
                    tmpstr += "null,";
                if (tmp->right)
                {
                    q.push(tmp->right);
                    tmpstr += to_string(tmp->right->data) + ',';
                }
                else
                    tmpstr += "null,";
            }
            // this is check if the queue is empty then no need to insert the string of null into the res
            if (!q.empty())
                rez += tmpstr;
        }
    }
    // remove the last comma at the end
    if (!rez.empty())
        rez.pop_back();
    return rez;
}

// -----------------FUNCTION TO GET THE INTEGER VALUE OF THE STRING BEFORE EVERY COMMA-----------------

int takeInt(string &s, int &index)
{
    int t = 0, sign = 1;
    if (s[index] == '-')
    {
        sign = -1;
        index++;
    }
    while (index < s.size() && s[index] != ',')
        t = t * 10 + (s[index++] - '0');
    return t * sign;
}

//--------------------------FUNCTION TO DESERIALIZE THE GIVEN STRING TO GET THE BINARY TREE---------------------
BinaryTreeNode<int> *deserialize(string data)
{
    if (data.empty())
        return NULL;

    int i = 0;
    // make the root node
    BinaryTreeNode<int> *rez = new BinaryTreeNode<int>(takeInt(data, i));
    i++;
    queue<BinaryTreeNode<int> *> q;
    q.push(rez);
    while (i < data.size())
    {
        BinaryTreeNode<int> *tmp = q.front();
        q.pop();
        // if in the string we encounter the 'n' then we jump the i to i+=5 to skip "null,"
        if (data[i] == 'n')
            i += 5;
        else
        {
            tmp->left = new BinaryTreeNode<int>(takeInt(data, i));
            i++;
            q.push(tmp->left);
        }

        if (data[i] == 'n')
            i += 5;
        else
        {
            tmp->right = new BinaryTreeNode<int>(takeInt(data, i));
            i++;
            q.push(tmp->right);
        }
    }
    return rez;
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    string str = serialize(root);
    BinaryTreeNode<int> *node = deserialize(str);
    printLevelWise(node);
}

/*
  INPUT - 1 2 3 -1 -1 4 5 -1 -1 -1 -1
  OUTPUT - 1,2,3,null,null,4,5
           1:L:2R:3
           2:
           3:L:4R:5
           4:
           5:

  TIME COMPLEXITY - For the serialization we traverse the whole tree so O(n) 
                    For the deserialise function we traverse the string till the end - O(s)
                    Total -> O(n) + O(s) where s is the size of the string

  SPACE COMPLEXITY - O(N) for storing the node elements in the queue


*/