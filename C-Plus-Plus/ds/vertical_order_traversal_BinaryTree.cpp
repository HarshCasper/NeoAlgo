/*-----------------------VERTICAL ORDER TRAVERSAL---------------------------

In this we have to get the vertical order of the tree
-> The approach is to Level order traverse the Binary tree
-> keep a track of the horizontal distance and vertical distance of the nodes from the root which 
is at origin or say at (0,0)
-> All the nodes at same horizontal distance come in the same column of the vertical traversal

*CHECK*- In this there is also a possibility when we have more than two nodes at the same horizontal and
vertical distance then we have sorted the values in increasing order
 INPUT -> THE VALUES OF THE TREE
            (1)
           /   \
        (2)     (3)
       /  \    /   \
    (4)   (5) (6)   (7)
 
 OUTPUT -> 2-D VECTOR WHICH DISPLAYS THE VERTICAL ORDER
          [[4]
          [2]
          [1,5,6]
          [3]
          [7]]

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------THE BiNARY TREE NODE CLASS----------------------------
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

// --------------------FUNCTION TO TAKE INPUT THE TREE--------------------------------

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

// ----------------------FUNCTION TO PRINT THE TREE---------------------------------

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

// ---------------COMPARE FUNCTION FOR THE SORT FUNCTION----------------------------

bool cmp(pair<int, int> l, pair<int, int> r)
{
    // check for the vertical distance first
    if (l.second < r.second)
        return true;
    else if (l.second > r.second)
        return false;
    //then if vertical distance is same than check for the node value
    else
        return (l.first <= r.first);
}

// -------------------THE FUNCTION------------------------------------

vector<vector<int>> verticalTraversal(BinaryTreeNode<int> *root)
{
    // map -> horizontal distance , (nodeValue, vertical distance)
    // map keeps track of all the nodes in the same horizontal distance with their vertical distance too
    map<int, vector<pair<int, int>>> mp;

    // queue -> Node, (horizontal Distance, vertical distance)
    // queue contains the node with its hd and vd ( it helps in the level order traversal)
    queue<pair<BinaryTreeNode<int> *, pair<int, int>>> q;
    //hd and vd of root is (0,0)
    int hd = 0;
    int vd = 0;
    // push the root
    q.push(make_pair(root, make_pair(hd, vd)));

    while (!q.empty())
    {
        // get the front node
        pair<BinaryTreeNode<int> *, pair<int, int>> temp = q.front();
        q.pop();

        // destructure the front node
        BinaryTreeNode<int> *node = temp.first;
        hd = temp.second.first;
        vd = temp.second.second;
        // push it into the map
        mp[hd].push_back(make_pair(node->data, vd));

        if (node->left)
        {
            q.push(make_pair(node->left, make_pair(hd - 1, vd + 1)));
        }
        if (node->right)
        {
            q.push(make_pair(node->right, make_pair(hd + 1, vd + 1)));
        }
    }

    // create the vector of size map
    vector<vector<int>> vertical(mp.size());

    int j = 0;
    // iterator for the map
    map<int, vector<pair<int, int>>>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        sort(it->second.begin(), it->second.end(), cmp);
        for (int i = 0; i < it->second.size(); ++i)
            vertical[j].push_back(it->second[i].first);
        j++;
    }
    return vertical;
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);
    vector<vector<int>> ans = verticalTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

/* COMPLEXITY ANALYSIS
   TIME-
   1. First we iterate over each and every node in the tree which takes O(n) time
   2. we insert the nodes in the map which takes O(logn) time
   3. Next we iterate over the map and add the nodes into the vector which also takes O(n) time
       total= O(nLogn) + O(n) => O(nLogn)
   
   SPACE-
   We have used map and queue which takes O(n) space in all

   Sample Input-
     1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
   
   Sample Output
     4
     2 8
     1 5 6
     3 9
     7
*/
