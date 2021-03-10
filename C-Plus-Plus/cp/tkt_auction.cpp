/*
@Author: Suvraneel Bhuin    (@Suvraneel)

Problem Statement:
* There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
* Each customer announces the maximum price he or she is willing to pay for a ticket (like an auction)
* They will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input:
* The first line contains integers n and m: the number of tickets and the number of customers.
* The next line contains n integers h1,h2,…,hn: the price of each ticket.
* The last line contains m integers t1,t2,…,tm: the maximum price for each customer.

Output:
For each customer, the price that they'll pay for their ticket. Same ticket can't be purchased again.
If a customer cannot get any ticket, print −1.

Constraints:
*   1   ≤   n,m    ≤2⋅105
*   1   ≤  hi,ti   ≤109

Example:
Input:
5 3
5 3 7 8 5
4 8 3
Output:
3
8
-1
*/


#include <iostream>
using namespace std;                            //For cin and cout

//Swap function --> simply exchanges the values of inputs
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int partition(int array[], int lo, int hi)
{
    int i = (lo - 1);
    // Select the pivot element
    int pivot = array[hi];

    //Traverses the array - whenever an element < pivot occurs, swap it with (i+1)th element 
    //This leads to elements < pivot on the left & elements > pivot on the right wrt the pivot
    for (int j = lo; j < hi; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    //Place the pivot element at i+1 (between smaller and larger elements)
    swap(&array[i + 1], &array[hi]);
    //Returns the pivot position
    return (i + 1);
}

void quickSort(int array[], int lo, int hi) {

    //If starting index crosses end index, then there're no elements to sort further, thus return
    if( lo >= hi ){
        return;
    }
    
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pivot = partition(array, lo, hi);

    // Sort the elements on the left of pivot
    quickSort(array, lo, pivot - 1);

    // Sort the elements on the right of pivot
    quickSort(array, pivot + 1, hi);
}
  
//Main driver program
int main() {
    int n, m, i, j;                            // n= no. of tickets; m = no. of customers
    int sold = -1;                             //implies initially no customer had any ticket
	cin >> n >> m;
    int h[n], t[n];
    for (j = 0; j < n; j++)
        {
            cin >> h[j];                       //accepts price of each ticket
        }

    for (i = 0; i < m; i++)
        {
            cin >> t[i];                       //accepts maximum bid by each customer
        }
    quickSort(h, 0, n-1);                      //calls sorting algorithm on ticket price array

    for ( i = 0; i < m; i++)                   //loop for examining each ticket
    {
        for ( j = n-1; j >= 0; j--)            //loop for considering each customer
        {
            if (t[i]>=h[j])                    //for each ticket sold
            {   
                sold = h[j];                   //tracks successful bids
                h[j] = INT_MAX;                //set the price as max integer possible
                                               //so that noone else can buy the same ticket 
                break;
            }
        
        }

        cout << sold << endl;                  //outputs successful bids for each customer
                                               //(-1) indicates the customer was unable to acquire a ticket
        sold = -1;                             //resets the parameter for the next ticket
    }
    
	return 0;   
}
