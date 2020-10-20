
TreeNode<int>* maxDataNode(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    TreeNode<int>* max = root;
    
    for(int i = 0 ; i < root -> children.size() ; i++ )
    {
        TreeNode<int>* temp = maxDataNode(root -> children[i]);
        if(temp -> data > max -> data)
        {
            max = temp;
        }
    }
    
    return max;

}

