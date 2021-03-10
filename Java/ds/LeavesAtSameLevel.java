/*Given a binary tree root, we have to check whether all leaves in a tree are at the same level or not.
Input
root = [3, [4, null, [2, null, null]], [1, [0, null, null], null]]
Output
true
Explanation
Leaves 2 and 0 are on the same level.*/
  
public class LeavesAtSameLevel
{
static class Node 
{
    int data;
    Node left, right;
    Node(int item) 
    {
        data = item;
        left = right = null;
    }
}
static class Leaves
{
    int leaflevel=0;
}
    Node root;
    Leaves mylevel = new Leaves();
    boolean solve(Node node, int level, Leaves leafLevel) 
    {
        if (node == null)
            return true;
        if (node.left == null && node.right == null) 
        {
            if (leafLevel.leaflevel == 0) 
            {
                leafLevel.leaflevel = level; 
                return true;
            }
            return (level == leafLevel.leaflevel);
        }

        return solve(node.left, level + 1, leafLevel)
                && solve(node.right, level + 1, leafLevel);
    }
   
    boolean ans(Node node) 
    {
        int level = 0;
        return solve(node, level, mylevel);
    }
  
    public static void main(String args[]) 
    {
        LeavesAtSameLevel tree = new LeavesAtSameLevel();
        tree.root = new Node(3);
        tree.root.left = new Node(4);
        tree.root.left.right=new Node(2);
        tree.root.right=new Node(1);
        tree.root.right.left = new Node(0);
        if (!tree.ans(tree.root))
            System.out.println("Leaves are not at the same level");
        else
            System.out.println("Leaves are all at same level");
    }
}
 