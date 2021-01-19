
class IntersectionPointOfLL {
    static class Node {

        int data;
        Node next;
    };

    static int intesection(Node head1, Node head2) {
        Node curr1 = head1;
        Node curr2 = head2;

        if (curr1 == null || curr2 == null)
            return -1;

        while (curr1 != null && curr2 != null && curr1 != curr2) {
            curr1 = curr1.next;
            curr2 = curr2.next;

            if (curr1 == curr2)
                return curr1.data;
            if (curr1 == null)
                curr1 = head2;
            if (curr2 == null)
                curr2 = head1;
        }

        return curr1.data;
    }

    public static void main(String[] args) {

        Node newNode;

        Node head1 = new Node();
        head1.data = 10;

        Node head2 = new Node();
        head2.data = 3;

        newNode = new Node();
        newNode.data = 6;
        head2.next = newNode;

        newNode = new Node();
        newNode.data = 9;
        head2.next.next = newNode;

        newNode = new Node();
        newNode.data = 15;
        head1.next = newNode;
        head2.next.next.next = newNode;

        newNode = new Node();
        newNode.data = 30;
        head1.next.next = newNode;

        head1.next.next.next = null;

        System.out.print(intesection(head1, head2));
    }

}
// O/P: 15

// Other examples

// if we put the values of 1st and 2nd Linked List as :
// 1st : 1->2->3->4->5->6
// 2nd : 7->4->9->3

// 4 is the intersection point

// if we put the values of 1st and 2nd Linked List as :
// 1st 3->8->9->12->10
// 2nd 10->12->80

// 12 is the intersection point
