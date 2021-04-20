/*
Hashtable chaining is a collision resolution technique in hashtables
The chaining method uses a hashtable as an array of pointers ; each pointer points a linked list.
For a given key value , the hash address is calculated . It then searches the linked list pointed by
the pointers at that location. If the element is found it returns the pointer to the node containing
that key value else inserts the element at the end of that list.
*/
#include <stdio.h>
#include <stdlib.h>
//structure for the hashtable
typedef struct HashTable
{
    int data;
    struct HashTable *link;
} HashTable;
//hash function
int hashingFunction(int value)
{
    return value % 10;
}

//Chaining function inserts an element in the hashtable by hashtable chaining
void Chaining(HashTable *t, int value)
{
    int index = hashingFunction(value);
    HashTable *ptr = t + index;
    while (ptr->link != NULL)
        ptr = ptr->link;
    HashTable *New = (HashTable *)malloc(sizeof(HashTable));
    New->data = value;
    New->link = NULL;
    ptr->link = New;
}
//print_table function prints the hashtable
void print_table(HashTable *t)
{
    HashTable *ptr = t;
    for (int i = 0; i < 10; i++)
    {
        if (ptr->link != NULL)
        {
            printf("%d -> ", i);
            HashTable *temp = ptr;
            while (temp->link != NULL)
            {
                temp = temp->link;
                printf("%d ", temp->data);
            }
            printf("\n");
        }
        ptr++;
    }
}
//doesExists function searches the hashtable in the chained linked lists
int does_exist(HashTable *t, int value)
{
    int index = hashingFunction(value);
    HashTable *ptr = t + index;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
        if (ptr->data == value)
            return 1;
    }
    return 0;
}
// Main function
int main()
{
    HashTable *t = (HashTable *)malloc(sizeof(HashTable) * 11);
    for (int i = 0; i < 10; i++)
        (t + i)->link = NULL;
    while (1)
    {
        printf("Enter your choice\n1.insert into hashtable\n2.check whether the element is in the hashtable\n3.print hashtable\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the value to be inserted\n");
            int value;
            scanf("%d", &value);
            Chaining(t, value);
        }
        break;

        case 2:
        {
            printf("Enter the value to check whether the element is in the hashtable\n");
            int value;
            scanf("%d", &value);
            int exists = does_exist(t, value);
            if(exists){
                printf("The element exists in the hashtable\n");
            }
            else{
                printf("The element doesn't exist in the hashtable\n");
            }
        }
        break;

        case 3:
        {
            print_table(t);
        }
        break;

        case 4:
        {
            return 0;
        }
        }
    }
    return 0;
}
/*
Sample I/O :
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
The element is in the hashtable
Enter your choice
1.insert into hashtable
2.check whether the element is in the hashtable
3.print hashtable
4.Exit
3
1 -> 1
2 -> 2
3 -> 3
Enter your choice
1.insert into hashtable
2.check whether the element is in the hashtable
3.print hashtable
4.Exit
4
Time Complexity = O(n)
Space Complexity = O(n)
*/

