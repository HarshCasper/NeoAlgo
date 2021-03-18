/*
Given an array of N elements, each element's occurrence in the array can be more than once. Find all elements whose occurrence is more than 1.
Formally find all duplicate elements of the array. This can be done with the help of map and set data structure.
*/

#include <bits/stdc++.h>
using namespace std;

void dupicate_elements(int ar[] ,int N)
{
    /* we will insert the array elements into the map. if current element already in the map,
    then definitely that element's occurrence is more than 1. 
    Hence it is duplicate and will insert in the set*/
    map < int, int > unique_elements;
    set < int > duplicates;
    for(int i = 0; i < N; i++)
    {
        if(!unique_elements[ar[i]])
            unique_elements[ar[i]]++;
       else
       {
           // this is a duplicate
           duplicates.insert(ar[i]);
       }
    }
    cout << "Duplicate elements are : ";
    for(auto i : duplicates)
        cout << i << ' ';
    cout << endl;
    return;
}

int main()
{
    cout << "Enter the size of the array : ";
    int N; 
    cin >> N;
    int ar[N + 1];
    cout << "Enter array elements :\n";
    for(int i = 0; i < N; i++)
    {
        cin >> ar[i];
    }
    dupicate_elements(ar , N);
}

/*
Standard Input and Output

Enter the size of the array : 12
Enter array elements
1 5 2 1 4 3 1 7 2 8 9 5
Duplicate elements are : 1 2 5

Time Complexity : O(logN)
Space Complexity : O(N)

*/
