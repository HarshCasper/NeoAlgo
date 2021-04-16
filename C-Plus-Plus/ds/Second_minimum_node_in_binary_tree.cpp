/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. 
If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.
*/
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
void insert(TreeNode **root, int val)
{
    queue<TreeNode *> q;
    q.push(*root);
    while (q.size())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (!temp->left)
        {
            if (val != NULL)
                temp->left = new TreeNode(val);
            else
                temp->left = new TreeNode(0);
            return;
        }
        else
        {
            q.push(temp->left);
        }
        if (!temp->right)
        {
            if (val != NULL)
                temp->right = new TreeNode(val);
            else
                temp->right = new TreeNode(0);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}
TreeNode *make_tree(vector<int> v)
{
    TreeNode *root = new TreeNode(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        insert(&root, v[i]);
    }
    return root;
}
class Solution
{
public:
    int findSecondMinimumValue(TreeNode *root)
    {
        int min = (root && root->val != 0) ? root->val : -1;
        int nextMin = -1;
        TraverseNodes(root, min, nextMin);
        return nextMin;
    }
    void TraverseNodes(TreeNode *node, int min, int &nextMin)
    {
        if (!node || node->val == 0)
        {
            return;
        }
        if (node->val > min)
        {
            if (nextMin == -1 || node->val < nextMin)
            {
                nextMin = node->val;
            }
        }
        TraverseNodes(node->left, min, nextMin);
        TraverseNodes(node->right, min, nextMin);
    }
};
main()
{
    Solution ob;
    vector<int> v;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the value of the nodes :";
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        v.push_back(m);
    }
    TreeNode *root = make_tree(v);
    cout << (ob.findSecondMinimumValue(root));
}
/*
Sample Input:
Enter the number of nodes: 7
Enter the value of the nodes: 2 2 5 NULL NULL 5 7

Sample Output:
5

Time Complexity:  O(n)
Space Complexity: O(n)

*/