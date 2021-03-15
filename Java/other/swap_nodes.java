/*
Swapping nodes in a linkedlist can be done using traversing the linkedlist
till (k)th node and (n-k)th. After finding the nodes the node values can be swapped
and the head of the new linkedlist should be returned.
*/
import java.util.*;
import java.lang.*;
class swap_nodes {
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    static ListNode swapNodes(ListNode head, int k){
        ListNode temp=head,ptr=head;
        int n=0,a1=1,x=0,y=0;
        while(temp!=null)
        {
            n+=1;
            temp=temp.next;
        }
        if(n==1 || k==(n-k+1)){
            return head;
        }
        temp=head;
        int a=0,b=0;
       if(k<n-k+1){
           x=k;
           y=n-k+1;
       }
        else{
            x=n-k+1;
            y=k;
        }
        while(a1<x || a1<(y)){
            if(a1==x){
                a=temp.val;
                ptr=temp;
            }
            a1+=1;
            temp=temp.next;
        }
        b=temp.val;
        ptr.val=temp.val;
        temp.val=a;
        return head;   
    }
    static ListNode createlist(int[] arr,int n){
    int i;
    ListNode head=new ListNode(0,null),temp,ptr=new ListNode(0,null);
    for(i=0;i<n;i++){
        temp=new ListNode(arr[i],null);
        if(i==0){
            head=temp;
            ptr=head;
        }
        else{
   ptr.next=temp;
   ptr=ptr.next;
        }
    }
  return head;
   }
    static void display(ListNode head){
    ListNode temp=head;
    while(temp!=null){
        System.out.print(temp.val+" ");
        temp=temp.next;
    }
    System.out.println();
   }
    public static void main(String[] args){
        int n,i,k;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the  number of elements you want to insert into linkedlist:");
        n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the elements into LinkedList:");
        for(i=0;i<n;i++)arr[i]=sc.nextInt();
        System.out.println("Enter the k value:");
        k=sc.nextInt();
        ListNode head=createlist(arr,n);
        System.out.println("The elements of linkedlist before swapping");
        display(head);
        head=swapNodes(head,k);
        System.out.println("The elements of linkedlist after swapping");
        display(head);
    }
}
/*
Sample input output:
Enter the  number of elements you want to insert into linkedlist:
10
Enter the elements into LinkedList:
7
9
6
6
7
8
3
0
9
5
Enter the k value:
5
The elements of linkedlist before swapping
7 9 6 6 7 8 3 0 9 5
The elements of linkedlist after swapping
7 9 6 6 8 7 3 0 9 5
Time Complexity:
O(n) where n is the number of nodes
Space complexity:
O(n) where n is the number of nodes

*/