//C++ program to implement Selection Sort

include<bits/stdc++.h>
using namespace std;

void selection_sort(vector <int> &arr, int n) 
{
   int i=0;
   while(i<n)
   {
      //Initilizing mini as i
      int mini=i;
      int j=i+1;
      while(j<n)
      {
         //If element at j is smaller than mini then change mini to j
         if(arr[j]<arr[mini])mini=j;
         j++;
      }
      //swapping elements at mini and i
      swap(arr[mini],arr[i]);
      i++;
   }   
}

int main() {
   int n;
   cout << "Enter the size of array:";
   cin >> n;
   vector <int> arr(n);
   cout << "Enter the elements of array:";
   for(auto &e:arr)cin>>e;
   selection_sort(arr, n);
   for(auto e:arr)cout<<e<<" ";

   return 0;
}

/*
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

INPUT
Enter the size of array: 5
Enter the elements of array: 5 4 3 2 1

OUTPUT
1 2 3 4 5

*/