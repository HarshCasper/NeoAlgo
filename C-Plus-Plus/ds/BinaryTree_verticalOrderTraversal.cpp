/*Given the level order input for the binary tree,for the binary tree consisting of N nodes, print a Two-dimensional array denoting the vertical order traversal of A.

Key Points:
1.In case of 2 or more Tree Nodes have the same vertical level then the one with earlier occurence in the level-order traversal of tree comes first in the output.
2.First Row of the output array will be the nodes on leftmost vertical line ,similarly last row of the output array will be the nodes on the rightmost vertical line.
*/

#include <iostream>
#include<map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *node(int val)
{
    TreeNode *c = new TreeNode;
    c->val = val;
    c->left = c->right = NULL;
    return c;
}

TreeNode *insert_value(TreeNode *root, int val, queue<TreeNode *> &t) //code for inserting the required value to every node of tree to be formed.
{
    TreeNode *temp = node(val);
    if (val == -1)
    {
        temp = NULL;
    }
    if (root == NULL)
    {
        root = temp;
    }
    else if (t.front()->left == NULL)
        t.front()->left = temp;
    else
    {
        t.front()->right = temp;
        t.pop();
    }
    t.push(temp);
    return root;
}

TreeNode *form_tree(vector<int> v) //code for creating tree
{
    TreeNode *root = NULL;
    queue<TreeNode *> t;
    for (int i = 0; i < v.size(); i++)
    {
        root = insert_value(root, v[i], t);
    }
    return root;
}
void ans(TreeNode* A,map<int,vector<int>>& m,int hd)
{if(A==NULL)
{
    return;
}
queue<pair<TreeNode*,int>>q;
q.push(make_pair(A,hd));
while(!q.empty())
{pair<TreeNode*,int> front=q.front();
q.pop();
  hd=front.second;
  TreeNode* t=front.first;
  m[hd].push_back(t->val);
  if(t->left!=NULL) q.push(make_pair(t->left,hd-1));
  if(t->right!=NULL) q.push(make_pair(t->right,hd+1));
}
}

vector<vector<int> > verticalOrderTraversal(TreeNode* A) {
    map<int,vector<int>>m;
    vector<vector<int>>v;
    ans(A,m,0);
    map<int,vector<int>>::iterator it=m.begin();
   for(;it!=m.end();it++)
   {v.push_back(it->second);
   }
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input;
    while (n--)
    {
        int u;
        cin >> u;
        input.push_back(u);
    }
    TreeNode *A = form_tree(input);
    vector<vector<int>> res=verticalOrderTraversal(A);
    cout<<"[";
    cout<<endl;
    for(int i=0;i<res.size();i++)
    {cout<<"[";
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j];
            if(j!=res[i].size()-1) cout<<",";
        }
        cout<<"]";
        if(i!=res.size()-1) cout<<",";
        cout<<endl;
    }
    cout<<"]";
    cout<<endl;
}


/*
Example:
Input:
13 1 2 3 4 5 -1 7 -1 -1 -1 -1 -1 -1
output:
[
[4],
[2],
[1,5,7],
[3]
]

Input:
15 1 3 7 2 5 8 9 -1 -1 -1 -1 -1 -1 -1 -1
Output:
[
[2],
[3],
[1,5,8],
[7],
[9]
]

Code Complexity:
Time Complexity- O(nlogn)
Space Complexity- O(n)
*/