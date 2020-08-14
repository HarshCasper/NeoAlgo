class reverse
{
    
    Node reverseList(Node head)
    {
       Node prev=null;
        Node curr=head;
        Node forw=curr;
        while(curr!=null){
            forw=forw.next;
            curr.next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
}