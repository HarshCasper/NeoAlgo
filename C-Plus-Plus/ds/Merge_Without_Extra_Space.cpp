/* Merge Without Extra Space

  ALGORITHM:
* 1st initialize p,q,i where p is the length of array a1 and q is the length of array a2 and i is the iterator
* Then we sorted both the arrays a1 and a2 by C++ STL
* Then we created a function merge_both_arrays
  * merge_both_arrays = 1. 1st initialize i=p-1,j=0
                        2. Now i traverse from the end element of array a1 and j traverse from the 1st element of array a2
                            if a1[i] is greater than a2[j]
                                swap the a1[i] and a2[j]
                                decrement i
                                increment j
                            else
                                break
                        3. Sort both a1 and a2 arrays

*/



#include <bits/stdc++.h>
using namespace std;

// here Merge the two arrays
void merge_both_arrays(int a1[], int a2[], int p, int q)
{
    int i = p - 1, j = 0;

    while (i >= 0 && j < q)
    {
        if (a1[i] > a2[j])
        {
            swap(a1[i], a2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    // Here we sort both the arrays
    sort(a1, a1 + p);
    sort(a2, a2 + q);
}

int main()
{
    int p, q, i;
    // Here p and q, length of the a1 and a2 arrays
    cout << "p is : ";
    cin >> p;
    cout << "q is : ";
    cin >> q;
    int a1[p], a2[q];
    cout << "Taking input for a1 : ";
    for (i = 0; i < p; i++)
    {
        cin >> a1[i];
    }
    cout << "Taking input for a2 : ";
    for (i = 0; i < q; i++)
    {
        cin >> a2[i];
    }
    sort(a1, a1 + p);
    sort(a2, a2 + q);
    merge_both_arrays(a1, a2, p, q);
    cout << "Output : ";
    for (i = 0; i < p; i++)
    {
        cout << a1[i] << " ";
    }
    for (i = 0; i < q; i++)
    {
        cout << a2[i] << " ";
    }
    cout << endl;
}

/*
INPUT:
p is : 3
q is : 5
Taking input for a1 : 2 5 8
Taking input for a2 : 1 4 10 0 6

OUTPUT: 0 1 2 4 5 6 8 10


Time Complexity : O((p+q)log(p+q))
Space Complexity : O(1)

*/