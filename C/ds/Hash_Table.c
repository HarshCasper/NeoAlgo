/*  HASH TABLE USING LINEAR PROBING
    * Hash table is a type of access table which contains key-value pairs
    * Each value is placed into a location in the hash table
    * This location will be calculated from the value itself
    * The mapping between a value and an index in the hash table is known as hashing
    * Allotment of more than one key value in one location in hash table is called collision
    * Linear Probing / Closed Hashing is a collision resolution technique

    Closed hashing works as follows:
        1. Start with the index where collision has occured, say i
        2. Continue the sequential search in the following locations:
            i, i+1, i+2,...., h,1,2,...i-1
        3. Here the table is considered circular, ie,when the last location is reached,
           search proceeds to first location of table
*/

#include <stdio.h>
#include <stdlib.h>

//Declare a hash table of preferred size
#define SIZE 10
typedef int* HashTable;

//Hashing function to get index for a given value
int hash(int val)
{
    return val % SIZE;
}

//to insert into hash table
void insert(HashTable ht, int val)
{
    /*Compute the index and search for an empty location
      from key in a circular manner*/
    int key = hash(val);
    int i = key;
    do
    {
        if (ht[i] == 0)
        {
            ht[i] = val;
            return;
        }
        i = (i + 1) % SIZE;
    } while (i != key);
}

//to check if a value exists in the hash table
int doesExist(HashTable ht, int val)
{
    //return 1 if exists and 0 if not
    int k = hash(val), i = k;
    do
    {
        if (ht[i] == val)
            return 1;
        i = (i + 1) % SIZE;
    } while (i != k);
    return 0;
}

//to print hash table as key-value pairs
void print(HashTable ht)
{
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, ht[i]);
}

// driver code
int main()
{
    HashTable ht = (int*)malloc(sizeof(int) * SIZE);
    int opt, val, exists;
    // menu-driven program to insert to,check for existence and print the hash table
    do
    {
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                scanf("%d", &val);
                insert(ht, val);
                break;
            case 2:
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

/*
    Sample Input:
    1                                                                                                                                               
    2                                                                                                                                               
    1                                                                                                                                               
    3                                                                                                                                               
    1                                                                                                                                               
    12                                                                                                                                              
    1                                                                                                                                               
    4                                                                                                                                               
    1                                                                                                                                               
    8                                                                                                                                               
    3  

    Sample Output:
    0 -> 0                                                                                                                                          
    1 -> 0                                                                                                                                          
    2 -> 2                                                                                                                                          
    3 -> 3                                                                                                                                          
    4 -> 12                                                                                                                                         
    5 -> 4                                                                                                                                          
    6 -> 0                                                                                                                                          
    7 -> 0                                                                                                                                          
    8 -> 8                                                                                                                                          
    9 -> 0  

*/

/*
    Time Complexity: O(SIZE)
    Space Complexity: O(n) , n-no of values
*/
