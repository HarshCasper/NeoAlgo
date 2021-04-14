/*
___Implement Open Hashing___
Hashing is an important data structure that is used to map a given value with a particular index
for faster access of elements. But sometimes more than one value gets mapped with a particular index.
This can be resolved using open hashing.
In open hashing, keys are stored in linked lists attached to cells of a hash table.
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node
{
    int data;
    struct node *next;
};
//array of pointers
struct node *head[SIZE]={NULL},*c;
void openDisplay();
void openInsert();
void openSearch();
void main()
{
    //prints the hash function used in the program
    printf("\nHash function : h(k)=k (mod 10)+1");
    int size,i,temp,ch=0;
    while(ch!=4)
    {
        printf("\n");
        printf("1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
           openInsert();
           break;
        case 2:
           openSearch();
           break;
        case 3:
           openDisplay();
           break;
        case 4:
           break;
        default:
            printf("Invalid choice\n");
        }
    }
}

/*
This function inserts elements into the hash table.
Duplication is not allowed in hash table.
We use an array of linked list to store the elements.
*/
void openInsert()
{
    int i,j,key;
    printf("Enter the element  :  ");
    scanf("%d",&key);
    i=key%SIZE+1;
    for(c=head[i];c!=NULL;c=c->next)
        {
            if(c->data==key)  //checks for duplication
            {
                printf("Duplication\n");
                return;
            }
        }
    //dynamically allocates memory for the node
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=NULL;
    //if head is empty then element made as head
    if(head[i]==NULL)
        head[i]=newnode;
    else
    {
        c=head[i];
        while(c->next!=NULL)
            c=c->next;
        c->next=newnode;
    }
}

/*
This function search for an element in the hash table.
The index corresponding to that particular value is found.
Search is made in the linked list whose head is at that index of the array.
*/
void openSearch()
{
    int key,index;
    printf("Enter the element  :  ");
    scanf("%d",&key);
    index=key%SIZE+1;  //finds the index of the key value
    //checks whether the head of the linked list is empty or not
    if(head[index]==NULL)  
        printf("Element not found\n");
    else
    {
        //traverse through the linked list
        for(c=head[index];c!=NULL;c=c->next)
        {
            if(c->data==key)  
            {
                printf("%d found at index %d\n",key,index);
                break;
            }
        }
        if(c==NULL)
            printf("Element not found\n");
    }
}

/*
This function displays elements in the hash table.
If no element is present the it displays "--" in the column value.
*/
void openDisplay()
{
    int i;
    printf("Index\tValue\n");
    printf("---------------\n");
    for(i=1;i<=SIZE;i++)
    {
        if(head[i]==NULL)
        {
            printf("%d\t--",i);
            printf("\n");
            continue;
        }
        else
        {
            c=head[i];
            printf("%d\t%d",i,c->data);
            c=c->next;
            for(;c!=NULL;c=c->next)
                printf("->%d",c->data);
        }
        printf("\n");
    }
}

/*
Sample Input and Output:
Hash function : h(k)=k (mod 10)+1
1.Insert
2.Search
3.Display
4.Exit
Enter your choice
1
Enter the element  :  44

1.Insert
2.Search
3.Display
4.Exit
Enter your choice
1
Enter the element  :  14

1.Insert
2.Search
3.Display
4.Exit
Enter your choice : 1
Enter the element  :  12

1.Insert
2.Search
3.Display
4.Exit
Enter your choice : 1
Enter the element  :  89

1.Insert
2.Search
3.Display
4.Exit
Enter your choice : 1
Enter the element  :  90

1.Insert
2.Search
3.Display
4.Exit
Enter your choice : 1
Enter the element  :  11

1.Insert
2.Search
3.Display
4.Exit
Enter your choice : 3
Index   Key
---------------
1       90
2       11
3       12
4        --
5        44->14
6        --
7        --
8        --
9        --
10      89

Time complexity :
Insertion - O(1)
Deletion - O(1)
*/
