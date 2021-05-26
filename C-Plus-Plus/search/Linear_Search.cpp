// Liner Search

#include<iostream>
using namespace std;

int main()
{
  int n,i,a;
  // initialize position variable as -1
  int pos=-1;      
  cout<<"Enter number of elements: ";
  cin>>n;
  cout<<"Enter the elements "<<endl;
  int arr[n];

  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  cout<<"Enter element to search ";
  cin>>a;

  //loop from 0th to nth element of array
  for(i=0;i<n;i++)    
  {
    //check whether number is present
    if(arr[i]==a)       
    {
      //if found update pos to i i.e. position of the element
      pos = i;       
      cout<<"Found at "<<pos;
      //terminate the for loop
      break;        
    }
  }

// if pos=-1 then element is not found
  if(pos == -1)    
  {
    cout<<"Not Found";
  }
  return 0;
}

/*
Time complexity : O(N)
Space complexity :O(1)
*/

/*
Test Case :
  Input :
  Enter number of elements: 
  4
  Enter the elements 
  1 2 4 5
  Enter element to search 
  9

  Output :
  Not Found
*/

