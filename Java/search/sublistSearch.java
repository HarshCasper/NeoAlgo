/*
SUBLIST SEARCH
    to search if a given sublist is present in a mainList using LinkedList.
*/

import java.util.Scanner;

//A linkedlist Node
class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

class Main{

    //returns true if the given sublist is found in MainList.
    static Boolean searchSublist(Node mainList,Node subList){
        Node main = mainList, sub = subList;
        //if both the lists are empty, return true.
        if(main == null && sub == null)
            return true;
        //if one list is empty and other is not return false
        else if(main == null ||(main != null && sub == null))
            return false;
        
        while(mainList != null){
            main = mainList;
            //searching for the sublist in mainlist.
            while(sub != null){
                if(main == null)
                    return false;
                else if(main.data == sub.data){
                    main = main.next;
                    sub = sub.next;
                }else
                    break;
            }

            //if the sub list is completely found in Main list, succesful search.
            if(sub == null)
                return true;
            sub = subList;
            mainList = mainList.next;
        }
        return false;
    }

    static void displayList(Node head){
        Node ptr = head;
        while(ptr != null){
            System.out.print(ptr.data +" ");
            ptr = ptr.next;
        }
    }

    static Node insertToList(Node head,int data){
        if(head == null){
            head = new Node(data);
        }else{
            Node ptr = head;
            while(ptr.next != null){
                ptr = ptr.next;
            }
            ptr.next = new Node(data);
        }
        return head;
    }

    public static void main(String args[]){
        Node mainHead = null,subHead = null;
        Scanner scanner = new Scanner(System.in);

        //Input MainList in which search is to be done
        System.out.print("Enter number of elements in Main List: ");
        int sizeMainlist = scanner.nextInt();
        System.out.println("Enter Main List: ");
        for(int i=0;i<sizeMainlist;i++){
            int data = scanner.nextInt();
            mainHead = insertToList(mainHead,data);
        }
        //Input sublist which is to searched for
        System.out.print("Enter number of elements in Sub List: ");
        int sizeSublist = scanner.nextInt();
        System.out.println("Enter Sub List: ");
        for(int i=0;i<sizeSublist;i++){
            int data = scanner.nextInt();
            subHead = insertToList(subHead,data);
        }

        //Printing the search result
        if(searchSublist(mainHead,subHead))
            System.out.println("SEARCH SUCCESSFUL");
        else
            System.out.println("SEARCH UNSUCCESSFUL");
    }
}

/*
Time Complexity: O(sizeMainlist * sizeSublist)

CASE 1:
MAIN: 1 2 3 4 5 6 7 8
SUB: 2 3 4
Expected Output: SEARCH SUCCESSFUL

CASE 1:
MAIN: 1 44 3 13 12 6 19 8
SUB: 13 12 12
Expected Output: SEARCH UNSUCCESSFUL

*/
