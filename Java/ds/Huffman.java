/*
 Huffman Coding is a famous Greedy Algorithm.
 Huffman coding assigns codes to characters such that the length of the code depends on the relative frequency or weight of the corresponding character.
 It is a lossless data compression algorithm which uses a small number of bits to encode common characters.
 A Huffman tree, similar to a binary tree data structure, needs to be created having n leaf nodes and n-1 internal nodes·
 Priority Queue/heaps is used for the implmentation.

 Time complexity of the Huffman algorithm is O(nlogn).
 Space complexity = O(n)
 
*/

import java.util.Scanner;
import java.util.Vector;
import java.util.Comparator;


class huffman_node {

    int frequency;

    char character;

    huffman_node left;
    huffman_node right;

    huffman_node() {
        frequency = 0;
        character = ' ';
        left = null;
        right = null;
    }
}

class MyComparator implements Comparator < huffman_node > {
    public int compare(huffman_node x1, huffman_node y1) {
        return x1.frequency - y1.frequency;
    }
}

class priority_queue {
    
    Vector < huffman_node > v2;


    public priority_queue(int number1, MyComparator comp1) {
        v2 = new Vector();
    }

    int parent(int h) {
        // if i is  root 
        if (h == 0) {
            return 0;
        }
        return (h - 1) / 2;
    }
}

public class Huffman {

    // recursive function to print
    public static void printCode(huffman_node root, String s) {

        if (root.left == null && root.right == null &&
            Character.isLetter(root.character)) {

            System.out.println("   " + root.character + "      |      " + root.frequency +
                "        |     " + s);
            return;
        }

        // if left add "0" 
        printCode(root.left, s + "0");

        // if right add"1" 
        printCode(root.right, s + "1");
    }

  
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

       
        int n = 0;
        int choice = 0;

        do {
            System.out.println("HUFFMAN ENCODER");
            System.out.println("PRESS 1 FOR HUFFMAN ENCODER");
            System.out.println("PRESS 2 FOR EXIT");
            System.out.println("  ");
            choice = s.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("ENTER THE NUMBER OF CHARACTERS :");
                    do {
                        n = s.nextInt();
                        if (n < 0) {                        
                            System.out.println("THE VALUE CANNOT BE NEGATIVE. TRY AGAIN");
                        }
                    } while (n < 0);

                    System.out.println("  ");

                    //array to store characters
                    char[] arr1 = new char[n];

                    //array to store frequencies    	
                    int[] freq1 = new int[n];

                    System.out.println("ENTER THE  CHARACTERS AND FREQUENCIES :");

                    for (int i1 = 0; i1 < n; i1++) {
                        System.out.println("ENTER THE CHARACTER NUMBER " + (i1 + 1) + "  : ");
                        arr1[i1] = s.next().charAt(0);
                        System.out.println("ENTER THE FREQUENCY OF THe CHARACTER '" +
                            arr1[i1] + "' :");
                        freq1[i1] = s.nextInt();
                    }

                    System.out.println("  ");

                    System.out.print("CHARACTERS ARE : { ");
                    for (int i1 = 0; i1 < n; i1++) {
                        System.out.print(arr1[i1]);
                        if (i1 != n - 1) {
                            System.out.print(" , ");
                        }
                    }
                    System.out.print(" }");
                    System.out.println(" ");

                    System.out.println("  ");
                    System.out.print("FREQUENCIES ARE : { ");
                    for (int i1 = 0; i1 < n; i1++) {
                        System.out.print(freq1[i1] + "");
                        if (i1 != n - 1) {
                            System.out.print(" , ");
                        }
                    }
                    System.out.print(" }");
                    System.out.println(" ");
                    System.out.println(" ");

                    System.out.println("CHARACTER |  FREQUENCY    |  HUFFMAN CODE  ");

                    //create new object of class priority_queue
                    priority_queue q = new priority_queue(n, new MyComparator());

                    for (int i = 0; i < n; i++) {
                        //create new object of class huffman_node
                        huffman_node hn = new huffman_node();

                        hn.character = arr1[i];
                        hn.frequency = freq1[i];

                        hn.left = null;
                        hn.right = null;

                        //add the nodes in the priority queue
                        q.add(hn);
                    }

                    //Initialize root to null
                    huffman_node root = null;

                    //while loop when it is queue size is greater than one
                    while (q.size() > 1) {

                        huffman_node first = q.peek(); 
                        q.poll(); 

                        huffman_node second = q.peek(); 
                        q.poll(); 

                        huffman_node temp = new huffman_node();

                        //add the data of 2 nodes
                        temp.frequency = first.frequency + second.frequency;
                        temp.character = '-';

                        temp.left = first;

                        temp.right = second;

                        root = temp;

                        //add in the queue
                        q.add(temp);
                    }

                    // print the codes by traversing the tree 
                    printCode(root, " ");               
                    System.out.println(" ");
                    break;

                case 2:
                    System.out.println("THANK YOU !");
                    System.out.println("  ");
                    break;

                default:
                    System.out.println("WRONG CHOICE ! TRY AGAIN");
                    System.out.println(" ");
                    break;

            }
        } while (choice != 2);
    }
}
