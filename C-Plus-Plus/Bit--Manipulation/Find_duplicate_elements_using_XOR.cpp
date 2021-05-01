/*
Finding duplicate elements:

Some integral elements are taken in input, which may occur once or twice, the repeated 
element is considered as duplicate and this code prints the repeated elements in output.
*/

#include <bits/stdc++.h>
using namespace std;

void find_duplicate_elements(int *arr,int n)
{
    cout<< "Enter again the total number of integral elements:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x=arr[i]^arr[j];
            if (x==0)
            {
                cout<< "Repeated Element = "<<arr[i]<<endl;
            }
        }
    }  
}
int main()
{
    int n;
    cout<< "Enter total number of integral elements:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the integral elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    find_duplicate_elements((int*)arr,n);
    
    return 0;
}

/*
Sample Input:
Enter total number of integral elements:
10
Enter the integral elements:
1 5 6 4 5 4 1 2 3 2

Sample Output:
Repeated Element = 1
Repeated Element = 5
Repeated Element = 4
Repeated Element = 2

Time Complexity - O(n^2)
Space Complexity - O(n^2)

*/

