//Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in decreasing order.
//
//        Input:
//        First line of input contains number of testcases T. For each testcase, first line of input conatains length of both linked lists N and M respectively. Next two lines contains N and M elements of two linked lists.
//
//        Output:
//        For each testcase, print the merged linked list which is in non-increasing order.
//
//        User Task:
//        The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.
//
//        Constraints:
//        1 <=T<= 50
//        1 <= N, M <= 1000
//
//        Example:
//        Input:
//        2
//        4 3
//        5 10 15 40
//        2 3 20
//        2 2
//        1 1
//        2 4
//
//        Output:
//        40 20 15 10 5 3 2
//        4 2 1 1




class Main
{
    Node mergeResult(Node node1, Node node2)
    {
        // Your code here
        Node temp1=node1;
        Node temp2=node2;
        Node c1=node1;
        Node c2=node2;
        int count=0;
        while(c1!=null){
            count++;
            c1=c1.next;

        }
        while(c2!=null){
            count++;
            c2=c2.next;

        }
        int[] arr=new int[count];
        int j=0;
        while(temp1!=null){
            arr[j++]=temp1.data;
            temp1=temp1.next;
        }
        while(temp2!=null){
            arr[j++]=temp2.data;
            temp2=temp2.next;
        }
        Arrays.sort(arr);
        Node head=null;
        for(int i=count-1;i>=0;i--){
            Node node=new Node(arr[i]);
            if (head == null) {
                head = node;
            }
            else {
                Node temp = head;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next =node;
            }

        }



        return head;
    }
}
