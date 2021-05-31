/*
Linear probing is a collision resolution technique in hash tables, data structures 
for maintaining a collection of key–value pairs and looking up the value associated 
with a given key.
In linear probing, we linearly probe for next empty slot in the hashtable for inserting an element
*/
import java.util.Scanner;
class Code{
    static int SIZE = 10;
    //hash function
    static int hashf(int val)
    {
        return val % SIZE;
    }
    //Linear Probing function inserts an element in the hashtable by linear probing
    static void LinearProbing(int ht[], int val)
    {
        int index = hashf(val);
        if (ht[index] == 0)
        {
            ht[index] = val;
        }
        else
        {
            int i = index;
            i = (i + 1) % SIZE;
            while (ht[index] != 0 && i != index)
            {
                i = (i + 1) % SIZE;
            }
            if (ht[index] == 0)
            {
                ht[index] = val;
            }
        }
    }

    //doesExists function searches the hashtable using Linear probing
    static int doesExist(int ht[], int val)
    {
        int index = hashf(val);
        if (ht[index] == val)
        {
            return 1;
        }
        int i = index;
        i = (i + 1) % SIZE;
        while (ht[index] != 0 && index != i)
        {
            if (ht[index] == val)
            {
                return 1;
            }
            i = (i + 1) % SIZE;
        }
        return 0;
        //return 1 if exists and 0 if not
    }

    static void print(int ht[])
    {
        for (int i = 0; i < SIZE; i++)
        {
            System.out.println(i+" "+ht[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ht[] = new int[SIZE];
        for (int i = 0; i < SIZE; i++){
            ht[i] = 0;
        }
        int opt, val, exists;
        do
        {
            System.out.println("Enter your choice \n1.insert \n2.Does Exist \n3.Print Hashtable\n4.Exit");
            opt = sc.nextInt();
            switch (opt)
            {
            case 1:
                System.out.println("\nEnter the element to insert into the hashtable");
                val = sc.nextInt();
                LinearProbing(ht, val);
                break;
            case 2:
                System.out.println("\nEnter the element to search for ");
                val = sc.nextInt();
                exists = doesExist(ht, val);
                if (exists == 1)
                    System.out.println("Exists");
                else
                    System.out.println("Doesn't Exist");
                break;
            case 3:
                print(ht);
                break;
            }

        }while (opt != 4);
        
    }
}


/*
Sample I/O:
Enter your choice
1.insert
2.Does Exist
3.Print Hashtable
4.Exit
1

Enter the element to insert into the hashtable
1
Enter your choice
1.insert
2.Does Exist
3.Print Hashtable
4.Exit
1

Enter the element to insert into the hashtable
2
Enter your choice
1.insert
2.Does Exist
3.Print Hashtable
4.Exit
1

Enter the element to insert into the hashtable
3
Enter your choice
1.insert
2.Does Exist
3.Print Hashtable
4.Exit
2

Enter the element to search for
3
Exists
Enter your choice
1.insert
2.Does Exist
3.Print Hashtable
4.Exit
3
0 0
1 1
2 2
3 3
4 0
5 0
6 0
7 0
8 0
9 0
Enter your choice
1.insert
2.Does Exist
3.Print Hashtable
4.Exit
4

Time complexity : O(n)
Space complexity : O(1)
*/
