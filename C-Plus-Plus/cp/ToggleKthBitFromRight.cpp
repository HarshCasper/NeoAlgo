//toggle kth bit from the right//

#include <iostream>
using namespace std;

int main()
{
  int n,k;
  //n=integer
  cin>>n>>k;
  int ans=(n^(1<<(k-1)));
  cout<<ans;
  return 0;
}
/*
  input:
    6 2
  ouput:
    4
  constraint:
    n is positive  
*/	
/*
  time-complexity: O(1)
*/ 
