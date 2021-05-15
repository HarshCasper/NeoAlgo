/*
WE have to find the Intersection Point of Y shaped LinkedList                                   
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next1, *next2;
};
//pointers to the Node
Node *head1 = NULL, *head2 = NULL;
Node *temp1, *temp2, *ptr;

// function declaration
void Insert_1();
void Insert_2();
void Display_All();
void Intersect();
int Find_Intersection();
int ele;

//  Main() function begins
int main()
{
    int ch;
    do
    {
        cout << "\n \n\n \t\t PROGRAM TO FIND INTERSECTION POINT" << endl;
        cout << "\t********************************************************************" << endl;
        cout << "\t 1) INSERT IN LIST 1 \t \t 2) INSERT IN LIST 2" << endl;
        cout << "\t 3) DISPLAY ALL LIST \t \t 4) INTERSECT LISTS AT SPECIFIC POSITION" << endl;
        cout << "\t 5) EXIT \t \t\t 6) FIND THE INTERSECTION POINT " << endl;
        cout << "ENTER YOUR CHOISE :";
        cin >> ch;
        switch (ch)
        {
        case 1:
            //inserting values in List 1
            Insert_1();
            break;

        case 2:
            //inserting values in List 2
            Insert_2();
            break;

        case 3:
            //returns the list
            Display_All();
            break;

        case 4:
            //this function is used to intersect both list as per user's choise
            Intersect();
            break;

        case 6:
            // returns the point of intersection
            cout << "Point Of Intersection : " << Find_Intersection();
            break;

        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid Input" << endl;
        };
    } while (1);
    return 0;
}

void Insert_1()
{
    ptr = new Node();
    cout << "ENTER THE ELEMENT : ";
    cin >> ele;
    ptr->data = ele;
    ptr->next1 = NULL;
    if (head1 == NULL)
    {
        head1 = ptr;
    }
    else
    {
        temp1 = head1;
        while (temp1->next1 != NULL)
        {
            temp1 = temp1->next1;
        }
        temp1->next1 = ptr;
    }
    cout << "Inserted succesfully" << endl;
}
//----------------------------------------------------------------------------------
void Insert_2()
{
    ptr = new Node();
    cout << "ENTER THE ELEMENT : ";
    cin >> ele;
    ptr->data = ele;
    ptr->next2 = NULL;
    if (head2 == NULL)
    {
        head2 = ptr;
    }
    else
    {
        temp2 = head2;
        while (temp2->next2 != NULL)
        {
            temp2 = temp2->next2;
        }
        temp2->next2 = ptr;
    }
    cout << "Inserted succesfully" << endl;
}
//------------------------------------------------------------------------------------
void Display_All()
{
    cout << "LIST 1 : ";
    temp1 = head1;

    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next1;
    }
    cout << "\nLIST 2 : ";
    temp2 = head2;

    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next2;
    }
}
//--------------------------------------------------------------------------------------
void Intersect()
{
    int length1 = 0, length2 = 0;
    string list = "";
    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL)
    {
        length1++;
        temp1 = temp1->next1;
    }
    while (temp2 != NULL)
    {
        length2++;
        temp2 = temp2->next2;
    }
    if (length1 > length2)
    {
        list = "LIST 1";
    }
    else
    {
        list = "LIST 2";
    }
    cout << "***********************************************************************" << endl;
    cout << "Since " << list << " is bigger in length." << endl;
    cout << "Tell the position of node in " << list << " on which you want to intersect : " << endl;
    cout << "***********************************************************************" << endl;

    int pos;
    cout << "ENTER THE POSITION : ";
    cin >> pos;
    temp1 = head1;
    temp2 = head2;

    if (length1 > length2)
    {
        while (temp2->next2 != NULL)
        {
            temp2 = temp2->next2;
        }
        for (int i = 0; i < pos - 1; i++)
        {
            temp1 = temp1->next1;
        }
        while (temp1 != NULL)
        {
            temp2->next2 = temp1;
            temp1 = temp1->next1;
            temp2 = temp2->next2;
        }
        cout << "Intersection Successfull" << endl;
    }
    else
    {
        while (temp1->next1 != NULL)
        {
            temp1 = temp1->next1;
        }
        for (int i = 0; i < pos - 1; i++)
        {
            temp2 = temp2->next2;
        }
        while (temp2 != NULL)
        {
            temp1->next1 = temp2;
            temp1 = temp1->next1;
            temp2 = temp2->next2;
        }
        cout << "Intersection Successfull" << endl;
    }
}
//--------------------------------------------------------------------------------------
/*
        Till now we have just work on intersecting two Linked List 
        Now, the main aim of this program is in the next function to find the Intersection point.
        
        Approach to solve this problem :- 
        ------------------------------
        We will calculate the length of individual and will iterate the longer List till it's 
        difference and then we wil iterate both the list together checking the pointer of next node 
        is same or not.       
*/
//---------------------------------------------------------------------------------------
int Find_Intersection()
{
    int length1 = 0, length2 = 0;
    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL)
    {
        length1++;
        temp1 = temp1->next1; //finding length of list
    }
    while (temp2 != NULL)
    {
        length2++;
        temp2 = temp2->next2;
    }
    int diff = abs(length1 - length2); //difference of both Lists
    temp1 = head1;
    temp2 = head2;

    if (length1 > length2)
    {
        for (int i = 0; i < diff; i++)
        {
            temp1 = temp1->next1;
        }
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            temp2 = temp2->next2;
        }
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
            return temp1->data;

        temp1 = temp1->next1;
        temp2 = temp2->next2;
    }
    return -1;
}

/*
Time complexity - O(n)
Space complexity - O(n)
*/

/*
Input :
 ENTER THE LIST 1 : 10 -> 3 -> 7 -> 40 -> 15 -> 6
 ENTER THE LIST 2 : 11 ->12 -> 20 
 ENTER THE POSTION FOR INTERSECTION  w.r.t BIGGER LIST (i.e LIST 1): 5 

 Output :
 DISPLAY THE LIST AFTER INTERSECTION : LIST 1:  10 ->3 ->7 ->40 ->15 ->6
                                      LIST 2:  11 ->12 ->20 ->15 ->6                 
 INTERSECTION POINT IS : 5 
*/

