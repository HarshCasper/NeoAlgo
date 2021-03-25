//Linear probing is a collision resolution technique in hashtables
//In linear probing, we linearly probe for next empty slot in the hashtable for inserting an element
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef int *HashTable;
//hash function
int hash(int val)
{
    return val % SIZE;
}
//Linear Probing function inserts an element in the hashtable by linear probing
void LinearProbing(HashTable ht, int val)
{
    int index = hash(val);
    if (*(ht + index) == 0)
    {
        *(ht + index) = val;
    }
    else
    {
        int i = index;
        i = (i + 1) % SIZE;
        while (*(ht + i) != 0 && i != index)
        {
            i = (i + 1) % SIZE;
        }
        if (*(ht + i) == 0)
        {
            *(ht + i) = val;
        }
    }
}

//doesExists function searches the hashtable using Linear probing
int doesExist(HashTable ht, int val)
{
    int index = hash(val);
    if (*(ht + index) == val)
    {
        return 1;
    }
    int i = index;
    i = (i + 1) % SIZE;
    while (*(ht + i) != 0 && index != i)
    {
        if (*(ht + i) == val)
        {
            return 1;
        }
        i = (i + 1) % SIZE;
    }
    return 0;
    //return 1 if exists and 0 if not
}

void print(HashTable ht)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d %d\n", i, *(ht + i));
    }
}

int main()
{
    HashTable ht = (int *)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
        *(ht + i) = 0;
    int opt, val, exists;

    do
    {
        printf("Enter your choice \n1.insert \n2.Does Exist \n3.Print Hashtable\n4.Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter the element to insert into the hashtable\n");
            scanf("%d", &val);
            LinearProbing(ht, val);
            break;
        case 2:
            printf("\nEnter the element to search for \n");
            scanf("%d", &val);
            exists = doesExist(ht, val);
            if (exists)
                printf("Exists\n");
            else
                printf("Doesn't Exist\n");
            break;
        case 3:
            print(ht);
            break;
        }

    } while (opt != 4);

    return 0;
}

// Sample I/O:

// Enter your choice
// 1.insert
// 2.Does Exist
// 3.Print Hashtable
// 4.Exit
// 1

// Enter the element to insert into the hashtable
// 1
// Enter your choice
// 1.insert
// 2.Does Exist
// 3.Print Hashtable
// 4.Exit
// 1

// Enter the element to insert into the hashtable
// 2
// Enter your choice
// 1.insert
// 2.Does Exist
// 3.Print Hashtable
// 4.Exit
// 1

// Enter the element to insert into the hashtable
// 3
// Enter your choice
// 1.insert
// 2.Does Exist
// 3.Print Hashtable
// 4.Exit
// 2

// Enter the element to search for
// 3
// Exists
// Enter your choice
// 1.insert
// 2.Does Exist
// 3.Print Hashtable
// 4.Exit
// 3
// 0 0
// 1 1
// 2 2
// 3 3
// 4 0
// 5 0
// 6 0
// 7 0
// 8 0
// 9 0
// Enter your choice
// 1.insert
// 2.Does Exist
// 3.Print Hashtable
// 4.Exit
// 4

// Time complexity : O(n)
// Space complexity : O(1)
