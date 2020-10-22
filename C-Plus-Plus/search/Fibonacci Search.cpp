#include<iostream>
using namespace std;
void FibonacciSearch(int *a, int start, int end, int *fib, int index, int item) {
   int i, mid;
   mid = start+fib[index-2];
   if(item == a[mid]) {
      cout<<"\n item found at "<<mid<<" index.";
      return;
   } else if(item == a[start]) {
      cout<<"\n item found at "<<start<<" index.";
      return;
   } else if(item == a[end]) {
      cout<<"\n item found at "<<end<<" index.";
      return;
   } else if(mid == start || mid == end) {
      cout<<"\nElement not found";
      return;
   } else if(item > a[mid])
         FibonacciSearch(a, mid, end, fib, index-1, item);
      else
         FibonacciSearch(a, start, mid, fib, index-2, item);
   }
   main() {
      int n, i, fib[20];
      int k;
      cout<<"Enter the number of elements in which you want to search";
      cin>>k;
      int a[k];
      cout<<endl<<"Enter the elements";
      for(int i=0;i<k;i++)
      {
      	cin>>a[i];
	  }
      char ch;
      fib[0] = 0;
      fib[1] = 1;
      i = 1;
      while(fib[i] < k) {
         i++;
         fib[i] = fib[i-1] + fib[i-2];
      }
      up:
         cout<<"\nEnter the Element to be searched: ";
         cin>>n;
         FibonacciSearch(a, 0, k-1, fib, i, n);
         cout<<"\n\n\tDo you want to search more...enter choice(y/n)?";
         cin>>ch;
         if(ch == 'y' || ch == 'Y')
            goto up;
         return 0;
         //sample input
         //6 1 2 3 4 5 6 
         //4
         //sample output
         // item found at 3 index.
   }
   
