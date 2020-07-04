#include<iostream>
using namespace std;

int main()
{
  int n,i,a;
  int pos=-1;      // initialize position variable as -1
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

  for(i=0;i<n;i++)    //loop from 0th to nth element of array
  {
    if(arr[i]==a)       //check whether number is present
    {
      pos = i;       //if found update pos to i i.e. position of the element
      cout<<"Found at "<<pos;
      break;        //terminate the for loop
    }
  }

  if(pos == -1)    // if pos=-1 then element is not found
  {
    cout<<"Not Found";
  }
  return 0;
}
