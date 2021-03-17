/*
Given a string S encode it according to the Dynamic Huffman Encoding Technique.
In Dynamic Huffman encoding technique we generate new code for each character dynamically i.e. it changes after we scan a new character.
*/
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int freq;
    char symbol;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        //Intially Frequency of non character element is zero
        this->freq = 0;
        //Root is represented by '*'
        this->symbol = '*';
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

//Function to print the corresponding Dynamic Huffman Tree during Dynamic encoding of each character
void printTree(TreeNode *root)
{
    //Using queue to print Tree level order wise
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        //Marking end of current level
        if (curr == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        //Printing of symbol along with its frequency
        cout << curr->symbol << curr->freq;
        cout << "  ";
        //Pushing children of current node to the queue
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

//Function to Return Reverse Level Order of the given tree to check Balancing.
vector<TreeNode *> ReverseLevelOrder(TreeNode *root)
{
    //vector to store reverse level order
    vector<TreeNode *> reverse_level_order;
    //To help in reversing of level order
    vector<TreeNode *> current;
    //queue to store Treenode
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            //Inserting reverse level order at the end of current list
            current.insert(current.end(), reverse_level_order.begin(), reverse_level_order.end());
            reverse_level_order = current;
            current.clear();
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        current.push_back(curr);
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    return reverse_level_order;
}

//Function to correct the tree
void correctTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    //Correcting each subtree first
    correctTree(root->left);
    correctTree(root->right);

    //Correcting the root
    int freq = 0;
    if (root->left)
    {
        freq += root->left->freq;
    }
    if (root->right)
    {
        freq += root->right->freq;
    }
    if (root->freq != freq)
    {
        root->freq = freq;
    }
}

//Function to swap the tree nodes
void swapTreeNode(TreeNode *root, TreeNode *a, TreeNode *b)
{
    //Getting each node parent
    TreeNode *parentA = a->parent;
    TreeNode *parentB = b->parent;
    //Swapping the parent
    a->parent = parentB;
    b->parent = parentA;
    //Chaning parent corresponding node
    if (parentA->left == a)
    {
        parentA->left = b;
    }
    else
    {
        parentA->right = b;
    }
    if (parentB->left == b)
    {
        parentB->left = a;
    }
    else
    {
        parentB->right = a;
    }
    correctTree(root);
}

//Function to get Code corresponding to each character
void getCodes(TreeNode *n, string code)
{
    if (n->left == NULL && n->right == NULL)
    {
        //If symbol is '*' that means it needs not to be coded
        if (n->symbol == '*')
        {
            return;
        }
        //Printing code for the symbol
        cout << "'" << n->symbol << "':" << code << " ";
        return;
    }
    //Adding "0" for left sub-tree
    getCodes(n->left, code + "0");
    //Adding "0" for right sub-tree
    getCodes(n->right, code + "1");
}
//Function to insert the corresponding Node to the tree
TreeNode *insertIntoTree(TreeNode *insertion, TreeNode *node)
{
    //Making the new TreeNode for addition of the next Node
    TreeNode *newInsertion = new TreeNode();
    //Incrementing Frequency of Parent by 1 for height balancing
    insertion->freq++;
    //Inserting the corresponding node to right
    insertion->right = node;
    //Making Parent of the node as this Insertion Node
    node->parent = insertion;
    //Making this next insertion point to the left of previous insertion point
    insertion->left = newInsertion;
    //Making parent of next insertion point previous insertion point
    newInsertion->parent = insertion;
    // Increment Each Parent Frequency by 1
    while (insertion->parent != NULL)
    {
        insertion->parent->freq++;
        insertion = insertion->parent;
    }
    return newInsertion;
}
//Function to Balance the Tree
TreeNode *checkTree(TreeNode *root)
{
    //Reverse Level Order
    vector<TreeNode *> seq = ReverseLevelOrder(root);
    //Swap Tree Node of the corresponding sub-tree is not balanced
    for (int i = 0; i < seq.size() - 1; i++)
    {
        if (seq[i]->freq > seq[i + 1]->freq)
        {
            for (int j = seq.size() - 1; j > i; j--)
            {
                if (seq[j]->freq < seq[i]->freq)
                {
                    //Function to swap the Tree nodes
                    swapTreeNode(root, seq[i], seq[j]);
                    TreeNode *temp = seq[i];
                    seq[i] = seq[j];
                    seq[j] = temp;
                    i--;
                    break;
                }
            }
        }
    }
    return root;
}

//Function to encode the string according to Dynamic Huffman
void dynamic_huffman(string input)
{
    //Intializing root
    TreeNode *root = new TreeNode();
    //Insertion is equal to root as we will intially insert character to root
    TreeNode *insertion = root;
    //Map to track apperance of each character in string
    unordered_map<char, int> apperance;
    //This will map character to its corresponding TreeNode
    unordered_map<char, TreeNode *> node;

    //For loop to iterate over each character in string
    for (int i = 0; i < input.size(); i++)
    {
        //If this is the first ever apperance of the given character
        if (apperance[input[i]] == 0)
        {
            //Creating a new TreeNode for the current character
            TreeNode *current = new TreeNode();
            //Making its frequency 1
            current->freq = 1;
            //Storing it's symbol
            current->symbol = input[i];
            //Inserting it to the tree
            insertion = insertIntoTree(insertion, current);
            //Updating the map to Map this character to current TreeNode
            node[input[i]] = current;
            //Marking that the character is visited
            apperance[input[i]]++;
        }
        else
        {
            //Getting the TreeNode Corresponding to the given character
            TreeNode *current = node[input[i]];
            //Incrementing the frequency by 1
            current->freq++;
            //Updating each parent frequency by 1 to balance the tree later on
            while (current->parent != NULL)
            {
                current->parent->freq++;
                current = current->parent;
            }
        }

        //Balancing the Tree
        root = checkTree(root);
        //Printing the Tree level order wise
        printTree(root);
        //Printing code corresponding to each character
        cout << "Codes:\t";
        getCodes(root, "");
        cout << endl
             << endl;
    }
}
int main()
{
    string input;
    cout << "Enter the input string:\t";
    getline(cin, input);
    dynamic_huffman(input);
    return 0;
}

/*Time complexity : O(n^2)
Input : "Dynamic"
Output:
*1
*0  D1        
Codes:  'D':1 

*2
*1  D1        
*0  y1
Codes:  'y':01 'D':1 

*3
*2  D1
*1  y1
*0  n1
Codes:  'n':001 'y':01 'D':1

*4
*2  *2
D1  y1  *1  n1
*0  a1
Codes:  'D':00 'y':01 'a':101 'n':11 

*5
*2  *3
D1  y1  *2  n1
*1  a1
*0  m1
Codes:  'D':00 'y':01 'm':1001 'a':101 'n':11

*6
*2  *4  
D1  y1  *2  *2
n1  a1  *1  m1
*0  i1
Codes:  'D':00 'y':01 'n':100 'a':101 'i':1101 'm':111

*7
*3  *4
D1  *2  *2  *2  
*1  i1  n1  a1  y1  m1
*0  c1
Codes:  'D':00 'c':0101 'i':011 'n':100 'a':101 'y':110 'm':111
*/
