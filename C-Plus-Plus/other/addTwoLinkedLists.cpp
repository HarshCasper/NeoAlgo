/* 
Add two numbers in a Linked list

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/

#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
class node {
    public:
        int value;
        node* next;
        node(int input) {
            value = input;
            next = NULL;
        }
};
//function to add the element in linked list
void Insertion(node *&head, int input)
{
    node *new_link = new node(input);
    if (head == NULL)
    {
        head = new_link;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_link;
}
// function to add calculate the sum of two non-empty linked lists which will return the answer as reversed.
node* AddTwoNumbers(node* list1,node* list2){
    // initialize a list to store the result.
    node* answer_list = NULL;
    // Two temporary pointers of 'type' node pointing to list 1 and 2 respectively.
    node *pointer1 = list1;        
    node *pointer2 = list2;
    // to store the carry obtain if the sum exceeds 9.
    int carry = 0; 
    while (pointer1 != NULL || pointer2 != NULL)
    {
        // a temporary variable 'x' to store the value at the current node of list1
        int x = (pointer1 != NULL) ? pointer1->value : 0; 
        // a temporary variable 'y' to store the value at the current node of list2
        int y = (pointer2 != NULL) ? pointer2->value : 0; 
        // calculating sum of the respective nodes
        int sum = carry + x + y;
        // calculating the carry
        carry = sum / 10;
        // storing the sum obtained in the answerList;
        Insertion(answer_list,(sum % 10)); 
        if (pointer1 != NULL)
            pointer1 = pointer1->next;
        if (pointer2 != NULL)
            pointer2 = pointer2->next;
    }
    if (carry > 0)
        Insertion(answer_list,carry); 
    return answer_list;
}
node* ReverseTheList(node* &head){
    node* prev_ptr = NULL;
    node* current_ptr = head;
    node* next_ptr;
    while(current_ptr != NULL)
    {
        next_ptr = current_ptr -> next;
        current_ptr -> next = prev_ptr;
        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }
    return prev_ptr;
}
// main function
int main()
{
    int testCases;
    cout << "Enter the number of testcases: ";
    cin >> testCases;

    while (testCases--)
    {
        // intialization of the input list1
        node* input1 = NULL;
        // intialization of the input list1
        node* input2 = NULL; 
        int number1;
        cout << "Enter the size of the linked list 1: "<<endl;
        cin >> number1;
        int number2;
        cout << "Enter the size of the linked list 2: "<<endl; 
        cin>>number2;
        cout<<"Enter the elements of linked list 1: "<<endl;
        while(number1--)
        {
            int temp;
            cin>>temp;
            Insertion(input1, temp);
        }
        cout << "Enter the elements of linked list 2: " << endl;
        while(number2--){
            int temp;
            cin>>temp;
            Insertion(input2,temp);
        }
        node* ans = AddTwoNumbers(input1, input2);
        ans = ReverseTheList(ans);
        cout<<"The resulting sum of the two lists is: "<<endl;
        while(ans != NULL)
        {
            cout<<ans->value<<"";
            ans = ans->next;
        }
        cout<<endl;
    }

    return 0;
}

/*

FOR EXAMPLE:--

Example 1:
Input:-
Enter the number of testcases: 3
Enter the size of the linked list 1: 
7
Enter the size of the linked list 2: 
4
Enter the elements of linked list 1: 
9 9 9 9 9 9 9
Enter the elements of linked list 2: 
9 9 9 9
The resulting sum of the two lists is: 
10009998
Enter the size of the linked list 1: 
3
Enter the size of the linked list 2: 
3
Enter the elements of linked list 1: 
2 4 3
Enter the elements of linked list 2: 
5 6 4
The resulting sum of the two lists is: 
807
Enter the size of the linked list 1: 
1
Enter the size of the linked list 2: 
1
Enter the elements of linked list 1: 
0
Enter the elements of linked list 2: 
0
The resulting sum of the two lists is: 
0


SPACE COMPLEXITY = O(max(m,n))(where m and n are the sizes of the list1 and list2 respectively)
TIME COMPLEXITY = O(max(m,n))

*/

