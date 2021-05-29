/* Find first and last positions of an element in a sorted array

ALGORITHM: 
* Take n = array size and element by user input
* Take first = -1 and last = -1 
* For finding first positions of an element
   1.for i=0 to i<n
        if a[i]==element
           first = i
           break
   ** here first stored 1st index of an element
* For finding last positions of an element
   1.for i=n-1 to i>=0
        if a[i]==element
           last = i
           break
   ** here last stored last index of an element
* print first and last.

*/



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,element,i,first=-1,last=-1;
    cout<<"array size : ";
    cin>>n;
    cout<<"element : ";
    cin>>element;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i]; 
    }
    //Finding first positions of an element
    for(i=0;i<n;i++)
    {
        if(a[i]==element)
        {
           first = i;
           break;
        }
    }
    //Finding last positions of an element
    for(i=n-1;i>=0;i--)
    {
        if(a[i]==element)
        {
           last = i;
           break;
        }
    }

    cout<<"first positions of an element is : "<<first<<endl;
    cout<<"last positions of an element is : "<<last<<endl;

}

/*

INPUT:  
array size : 10
element : 4
1 2 4 4 4 4 4 4 50 90

OUTPUT: 
first positions of an element is : 2
last positions of an element is : 7

Time Complexity: O(n)
Space Complexity: O(1)
*/



