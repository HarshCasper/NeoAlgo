/*
Author: @Suvraneel
	Suvraneel Bhuin

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
*/


#include <iostream>
//For cin and cout
using namespace std;

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
    //tkt = no. of tickets; cust = no. of customers
    int tkt, cust, i, j;
    //implies initially no customer had any ticket
    int sold = -1;
    cin >> tkt >> cust;
    int price[tkt], bid[cust];
    for (j = 0; j < tkt; j++)
    {
        //accepts price of each ticket
        cin >> price[j];                       
    }
    for (i = 0; i < cust; i++)
    {
        //accepts maximum bid by each customer
        cin >> bid[i];                       
    }
    //calls sorting algorithm on ticket price array
    quickSort(price, 0, tkt-1);
    //loop for considering each customer
    for ( i = 0; i < cust; i++)
    {
	//loop for examining each ticket starting from expensive so as to confirm maximum bid
        for ( j = tkt-1; j >= 0; j--)            
        {
	    //for each ticket sold
            if (bid[i]>=price[j])
            {
		//track successful bids
                sold = price[j];
                //set the price as max integer possible so that noone else can buy the same ticket
                price[j] = INT_MAX;                                     
                break;
            }
        }
        //output successful bids for each customer
        cout << sold << endl;                  
        //(-1) indicates the customer was unable to acquire a ticket
        //reset the 'sold' parameter for the next ticket
        sold = -1;
    }
    
	return 0;   
}

/*
Time complexity:    Sorting = O(n)          where n = no. of tickets
                    Auction = O(mn)         where m = no. of customer
Space Complexity:   O(n)

Sample Input:
5 3
5 3 7 8 5
4 8 3

Standard Output:
3
8
-1
*/
