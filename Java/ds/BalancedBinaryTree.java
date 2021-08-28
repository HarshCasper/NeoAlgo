/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.*/





	class Solution {
	    private class IsBalanced{
	        int ht=-1;
	        boolean bal=true;
	    }
	    public boolean isBalanced(TreeNode node) {
	        if(node==null)
	        {
	            return true;
	        }
	        return isBalanced2(node).bal;
	        
	    }
	    private IsBalanced isBalanced2(TreeNode node)
	    {
	        if(node==null)
	        {
	            return new IsBalanced();
	        }
	        IsBalanced lbp=isBalanced2(node.left);
	        IsBalanced rbp=isBalanced2(node.right);
	        IsBalanced sbp=new IsBalanced();
	        int bf=Math.abs(lbp.ht-rbp.ht);
	        sbp.ht=Math.max(lbp.ht,rbp.ht)+1;
	        sbp.bal=(lbp.bal && rbp.bal && bf<=1);
	        return sbp;
	    }
	}

