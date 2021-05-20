/*
HASH TABLE USING LINEAR PROBING
 A hash function is a function that maps all the keys to the slots of an array. it is given a key and  an array, the hash function can make a suggestion as to where the index of the key should be stored in the   array.
 
 Linear probing -
 -starting with index j where collison occurred
 -it looks for next available index by using hash function
 -And all the attributes for the index will be inserted
 
Hash Table implemented in c which includes all CRUD operations (insert, display, update , delete)      which menu driven and also included to return the size of table instantly.
(here updating happens if the key already present in table )
*/

#include <stdio.h>
#include <stdlib.h>

//structure of the each element in the table 
struct set
{
  int key;
  int data;
  int collision;
};

//declare hash table and maximaum capacity
struct set *array;
int capacity = 10;
int size = 0;

//Hashing function to get the index for a given key
int hashFunction(int key)
{
  return (key % capacity);
}

//to check whether prime or not
int checkPrime(int n)
{
  int i;
  if (n == 1 || n == 0)
  {
  return 0;
  }
  for (i = 2; i < n / 2; i++)
  {
  if (n % i == 0)
  {
    return 0;
  }
  }
  return 1;
}

//here , next prime no of capacity is obtained ,this will be used in hashfunction to get the index
int getPrime(int n)
{
  if (n % 2 == 0)
  {
  n++;
  }
  while (!checkPrime(n))
  {
  n += 2;
  }
  return n;
}

//initialising the array(table) along with its attributes to 0
void init_array()
{
  capacity = getPrime(capacity);
  array = (struct set *)malloc(capacity * sizeof(struct set));
  for (int i = 0; i < capacity; i++)
  {
  array[i].key = 0;
  array[i].data = 0;
  array[i].collision = 0;
  }
}

//to insert to hash table
void insert(int key, int data)
{
  /*
  if index is already occupied then using linear probing to get the available index ,show if 
  collision occured and print index value where the key is being inserted
  */
  int index = hashFunction(key);
  if (array[index].data == 0)
  {
  array[index].key = key;
  array[index].data = data;
  size++;
  printf("\n Key (%d) has been inserted \n\n", key);
  }
  else if (array[index].key == key)
  {
  array[index].data = data;
  }
  else
  {
	  array[index].collision = array[index].collision+1;
  while(array[index].key != 0){
	  index=(index+1)%capacity;
	  if(array[index].key == key){
		  break;
	  }
  }
   if (array[index].data == 0)
  {
  array[index].key = key;
  array[index].data = data;
  size++;
   printf("\n Collision occured  \n\n");
   printf("\n Key (%d) has been inserted at %d using linear probing \n\n", key,index);
  }
  else if (array[index].key == key)
  {
  array[index].data = data;
  }
  }
}

//remove element from the table by using key
void remove_element(int key)
{
	/*
	if key exist, then using hashFunction ,we get the index .If not present at index then searching the table to find the key
	*/
  int index = hashFunction(key);
  if(array[index].collision>0){
	  while(array[index].key!=key){
		  index++;
	  }
  if (array[index].data == 0)
  {
  printf("\n This key does not exist \n");
  }
  else
  {
  array[index].key = 0;
  array[index].data = 0;
  array[index].collision--;
  size--;
  printf("\n Key (%d) has been removed \n", key);
  } 
  }
  else{
  if (array[index].data == 0)
  {
  printf("\n This key does not exist \n");
  }
  else
  {
  array[index].key = 0;
  array[index].data = 0;
  size--;
  printf("\n Key (%d) has been removed \n", key);
  }
  }
}

//display the hashtable
void display()
{
  int i;
  for (i = 0; i < capacity; i++)
  {
  if (array[i].data == 0)
  {
    printf("\n array[%d]: / ", i);
  }
  else
  {
    printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].data);
  }
  }
}

//to get the size of hashtable
int size_of_hashtable()
{
  return size;
}

//driver code
int main()
{
  int choice, key, data, n;
  int c = 0;
  init_array();
	printf("\n\t\t************HashTable implementation using linear probing************\n\n");
	
	/*
	Menu driven code which includes inserting,deleting,getting size of table, display the table.
	*/
  do
  {
  printf("\n1.Insert item in the Hash Table"
     "\n2.Remove item from the Hash Table"
     "\n3.Check the size of Hash Table"
     "\n4.Display a Hash Table"
	 "\n5.exit"
     "\n\n Please enter your choice: ");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    printf("Enter key -:\t");
    scanf("%d", &key);
    printf("Enter data -:\t");
    scanf("%d", &data);
    insert(key, data);
    break;
  case 2:
    printf("Enter the key to delete-:");
    scanf("%d", &key);
    remove_element(key);
    break;
  case 3:
    n = size_of_hashtable();
    printf("Size of Hash Table is-:%d\n", n);
    break;
  case 4:
    display();
	printf("\n\n");
    break;
  default:
    exit(0);
  }
  } while (1);
}
/*

Sample I/O and O/P
************HashTable implementation using linear probing************


1.Insert item in the Hash Table
2.Remove item from the Hash Table
3.Check the size of Hash Table
4.Display a Hash Table
5.exit

 Please enter your choice:1
 Enter key -:    33
Enter data -:   123

 Key (33) has been inserted


1.Insert item in the Hash Table
2.Remove item from the Hash Table
3.Check the size of Hash Table
4.Display a Hash Table
5.exit

 Please enter your choice:1
Enter key -:    34
Enter data -:   322

 Key (34) has been inserted


1.Insert item in the Hash Table
2.Remove item from the Hash Table
3.Check the size of Hash Table
4.Display a Hash Table
5.exit

 Please enter your choice:1
Enter key -:    33
Enter data -:   989

1.Insert item in the Hash Table
2.Remove item from the Hash Table
3.Check the size of Hash Table
4.Display a Hash Table
5.exit

 Please enter your choice:1
Enter key -:    45
Enter data -:   231

 Collision occured

 Key (45) has been inserted at 2 using linear probing

1.Insert item in the Hash Table
2.Remove item from the Hash Table
3.Check the size of Hash Table
4.Display a Hash Table
5.exit

 Please enter your choice:4
 key: 33 array[0]: 989
 key: 34 array[1]: 322
 key: 45 array[2]: 231
 array[3]: /
 array[4]: /
 array[5]: /
 array[6]: /
 array[7]: /
 array[8]: /
 array[9]: /
 array[10]: /

1.Insert item in the Hash Table
2.Remove item from the Hash Table
3.Check the size of Hash Table
4.Display a Hash Table
5.exit

 Please enter your choice:2
 Enter the key to delete-:45

 Key (45) has been removed

1.Insert item in the Hash Table
2.Remove item from the Hash Table
3.Check the size of Hash Table
4.Display a Hash Table
5.exit

 Please enter your choice:3
 Size of Hash Table is-:2

1.Insert item in the Hash Table
2.Remove item from the Hash Table
3.Check the size of Hash Table
4.Display a Hash Table
5.exit

 Please enter your choice:5
 

Time and space Complexities of a Hash Table/Map is O(n)
*/
