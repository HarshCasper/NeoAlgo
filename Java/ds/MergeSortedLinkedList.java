/*
1) The list contains one or fewer elements, return the same list.
2) Divide the list into halves using the splitting function.
3) Sort ​the two halves of the list.
4) At the end, merge the sorted lists.

How Merge Sort work with Linked List:-

 10-> 5-> 8-> 12-> 15-> 2-> 30
 10-> 5-> 8-> 12   15-> 2-> 30
 10-> 5   8-> 12   15   2-> 30
 5-> 10   8-> 12   15   2-> 30
 5-> 8-> 10-> 12   2-> 15-> 30
 2-> 5-> 8-> 10-> 12-> 15-> 30 
*/

public class linkedList {
    node head = null;
    static class node {
        int val;
        node next;

        public node(int val)
        {
            this.val = val;
        }
    }

    node sortedMerge(node a, node b)
    {
        node result=null;
        
        if (a != null) {
            if (b == null)
                return a;
            if (a.val <= b.val) {
                result = a;
                result.next = sortedMerge(a.next, b);
            } else {
                result = b;
                result.next = sortedMerge(a, b.next);
            }
            return result;
        } else {
            return b;
        }
    }

    node mergeSort(node h)
    {
        if (h == null || h.next == null) {
            return h;
        }
        node middle = getMiddle(h);

        node nextofmiddle = middle.next;
        middle.next = null;

        node left = mergeSort(h);
        node right = mergeSort(nextofmiddle);
 
        node sortedlist = sortedMerge(left, right);
        return sortedlist;
    }
    node getMiddle(node h)
    {
        if (h == null)
            return h;

        node fastptr = h.next;
        node slowptr = h;

        while (fastptr != null) {
            fastptr = fastptr.next;
            if (fastptr != null) {
                slowptr = slowptr.next;
                fastptr = fastptr.next;
            }
        }

        return slowptr;
    }

    void push(int new_data)
    {
        node new_node = new node(new_data);
        new_node.next = head;
        head = new_node;
    }
    void printList(node headref)
    {
        while (true) {
            if (headref == null) break;
            System.out.print(headref.val + " ");
            headref = headref.next;
        }
    }

    public static void main(String[] args)
    {

        linkedList li = new linkedList();
        li.push(15);
        li.push(9);
        li.push(5);
        li.push(20);
        li.push(3);
        li.push(4);
        System.out.println("Linked List without sorting is :");
        li.printList(li.head);
        li.head = li.mergeSort(li.head);
        System.out.print("\n Sorted Linked List is: \n");
        li.printList(li.head);
    }
} 

/*
Example:-

Linked List without sorting is :
15 9 5 20 3 4

Sorted Linked List is:
3 4 5 9 15 20

*/ 

/*
Time Complexity: O(nLogn)

*/
