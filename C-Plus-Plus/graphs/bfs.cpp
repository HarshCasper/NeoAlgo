/*
    Author: Davide Pollicino (@omonimus1)
    Date: 07/07/2020
    Summary: Implement Level Traverse of a tree, applying the Breath First Search Algorithm (BFS)
             algorithm
*/

void level_order(Node *root)
{
    if(root == NULL)
        return; 
    
    // Create queue and push in the root node
    queue<Node *>q;
    q.push(root);

    // Create a temporary node
    Node *temp;
    // Until the queue is not empty
    while(!q.empty())
    {
        // Fetch the front Node of the queue and store it in temp;
        temp = q.front();
        // Remove the front element from the queue
        q.pop();
        // Print the data stored in the temporary value
        cout << temp-data << " ";
        // If the temporary node has a left-child, push it in the queue
        if(temp->left != NULL) q.push(temp->left);
        // If the temporary node has a right-child, push it in the queue
        if(temp->right != NULL) q.push(temp->right);
    }
}
