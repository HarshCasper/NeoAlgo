class Solution {
    public void deleteNode(ListNode node) {

        ListNode currentNode = node; //Setting currentNode to given Node
        ListNode nextNode = node.next; // Grabbing NextNode to the currentNode
        currentNode.val = nextNode.val; // Assigning next Node value to the currentNode
        currentNode.next = nextNode.next; // Pointing next node of currentNode to Next of the Next Node
    }
}
