/*
Hashtable chaining is a collision resolution technique in hashtables
The chaining method uses a hashtable as an array of pointers ; each pointer points a linked list.
For a given key value , the hash address is calculated . It then searches the linked list pointed by
the pointers at that location. If the element is found it returns the pointer to the node containing
that key value else inserts the element at the end of that list.
*/
import java.util.Scanner;

//class for the hashtable
class HashTable {
    int data;
    HashTable link;
}

// hash function
class Code {
    static int hashingFunction(int value) {
        return value % 10;
    }

    // Chaining function inserts an element in the hashtable by hashtable chaining
    static void Chaining(HashTable t[], int value) {
        int index = hashingFunction(value);
        HashTable ptr = t[index];
        while (ptr.link != null)
            ptr = ptr.link;
        HashTable New = new HashTable();
        New.data = value;
        New.link = null;
        ptr.link = New;
    }

    // print_table function prints the hashtable
    static void print_table(HashTable t[]) {
        HashTable ptr = t[0];
        for (int i = 0; i < 10; i++) {
            if (ptr.link != null) {
                System.out.print(i + " -> ");
                HashTable temp = ptr;
                while (temp.link != null) {
                    temp = temp.link;
                    System.out.print(temp.data + " ");
                }
                System.out.println();
            }
            ptr = t[i];
        }
    }

    // doesExists function searches the hashtable in the chained linked lists
    static int does_exist(HashTable t[], int value) {
        int index = hashingFunction(value);
        HashTable ptr = t[index];
        while (ptr.link != null) {
            ptr = ptr.link;
            if (ptr.data == value)
                return 1;
        }
        return 0;
    }

    // Main function
    public static void main(String[] args) {
        HashTable t[] = new HashTable[11];
        for (int i = 0; i < 10; i++) {
            t[i] = new HashTable();
            t[i].link = null;
        }
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println(
                    "Enter your choice\n1.insert into hashtable\n2.check whether the element is in the hashtable\n3.print hashtable\n4.Exit");
            int choice;
            choice = sc.nextInt();
            switch (choice) {
                case 1: {
                    System.out.println("Enter the value to be inserted");
                    int value;
                    value = sc.nextInt();
                    Chaining(t, value);
                }
                    break;

                case 2: {
                    System.out.println("Enter the value to check whether the element is in the hashtable");
                    int value;
                    value = sc.nextInt();
                    int exists = does_exist(t, value);
                    if (exists == 1) {
                        System.out.println("The element exists in the hashtable");
                    } else {
                        System.out.println("The element doesn't exist in the hashtable");
                    }
                }
                    break;

                case 3: {
                    print_table(t);
                }
                    break;

                case 4: {
                    return;
                }
            }
        }
    }

}


/*
Sample I/O:
Enter your choice
1.insert into hashtable
2.check whether the element is in the hashtable
3.print hashtable
4.Exit
1
Enter the value to be inserted
1
Enter your choice
1.insert into hashtable
2.check whether the element is in the hashtable
3.print hashtable
4.Exit
1
Enter the value to be inserted
2
Enter your choice
1.insert into hashtable
2.check whether the element is in the hashtable
3.print hashtable
4.Exit
1
Enter the value to be inserted
3
Enter your choice
1.insert into hashtable
2.check whether the element is in the hashtable
3.print hashtable
4.Exit
2
Enter the value to check whether the element is in the hashtable
3
The element exists in the hashtable
Enter your choice
1.insert into hashtable
2.check whether the element is in the hashtable
3.print hashtable
4.Exit
3
2 -> 1
3 -> 2
4 -> 3
Enter your choice
1.insert into hashtable
2.check whether the element is in the hashtable
3.print hashtable
4.Exit
4

Time Complexity : O(n)
Space Complexity : O(n)
*/