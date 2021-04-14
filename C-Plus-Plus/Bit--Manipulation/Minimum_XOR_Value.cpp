//Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

/*Sample Input :
Example 1:
Enter the size of array : 4
Enter the array : [0, 2, 5, 7]
Output 1:
The Minimum xor value is : 2
The corresponding elements are : 0 and 2

Example 2:
Enter the size of array : 5
Enter the array : [0, 4, 7, 9, 8]
Output 2:
The Minimum xor value is : 1
The corresponding elements are : 8 and 9
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,ele1,ele2;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    sort(A,A+n);
    int ans=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        int x=A[i]^A[i+1];
        if(x<ans)
        {
            ans=x;
            ele1=A[i];
            ele2=A[i+1];
        } 
    }
    cout<<"The Minimum xor value is : "<<ans<<endl;
    cout<<"The corresponding elements are : "<<ele1<<" and "<<ele2;
    return 0;
}
