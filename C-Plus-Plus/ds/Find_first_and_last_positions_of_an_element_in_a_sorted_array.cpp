/* Find first and last positions of an element in a sorted array

ALGORITHM: 
* Take n = array size and element by user input
* Take first = store first positions of an element and last = store last positions of an element
* For finding first positions of an element
   * First_positions:
      int i,first=-1
      for i=0 to i<n
        if a[i]==element
           first = i
           break
      return first
   ** here first stored 1st index of an element
* For finding last positions of an element
   * Last_positions:
      int i,last=-1
      for i=n-1 to i>=0
        if a[i]==element
           last = i
           break
      return last
   ** here last stored last index of an element
* print first and last.

*/

#include <bits/stdc++.h>
using namespace std;

//Finding first positions of an element
int First_positions(int a[],int n,int element)
{
    int i,first=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]==element)
        {
           first = i;
           break;
        }
    }
    return first;
}

//Finding last positions of an element
int Last_positions(int a[],int n,int element)
{
    int i,last=-1;
    for(i=n-1;i>=0;i--)
    {
        if(a[i]==element)
        {
           last = i;
           break;
        }
    }
    return last;
}

 int main()
{
    int n,element,i,first,last;
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
    first = First_positions(a,n,element);
    //Finding last positions of an element
    last = Last_positions(a,n,element);

    cout<<"first position of an element is : "<<first<<endl;
    cout<<"last position of an element is : "<<last<<endl;

}

/*
INPUT:  
array size : 10
element : 4
1 2 4 4 4 4 4 4 50 90

OUTPUT: 
first position of an element is : 2
last position of an element is : 7

Time Complexity: O(n)
Space Complexity: O(n)
*/
