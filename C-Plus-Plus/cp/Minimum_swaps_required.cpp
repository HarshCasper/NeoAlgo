// Defining the header files used for the program

#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// making a function that counts swap times minimum

int swap(int a[], int n)
{
      vector<pair<int,int> > v(n);
     
    for(int i=0; i<n; i++)
      v[i] = {a[i],i};
    
    sort(v.begin(),v.end());
    
    int c=0;
    
    for(int i=0; i<n; i++)
    {
        if(v[i].second == i)
          continue;
        
        else
        {
            c++;
            swap(v[i],v[v[i].second]);
            i--;
        }
        
    }
   return c; // returns the minimum swap count
}

// Driver Code

int main()
{
    int n;
    cin>>n;  //No of elements to be stored
    int a[n];  //array defined
   
    for(int i=0; i<n; i++)
     cin>>a[i];   //loop for storing array elements

    int c = swap(a,n); // Calling the function
    cout<<c;
    
}
