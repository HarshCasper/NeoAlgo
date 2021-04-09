/* The adjacent_difference algo produces a new sequence
 in which each element is difference between adjacent 
 elements in original sequence. */

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
	
	vector<int> v(10),r(10);
	int i;
	
	for(i=0; i<10; i++)
	 v[i] = i*2;
	 cout << " Original sequence";
	for(i=0; i<10; i++)
	  cout << v[i] << " ";
	cout<<endl;
	
	adjacent_difference(v.begin(),v.end(),r.begin());
	
	cout<<" Resulting sequence :";
	for(i=0; i<10; i++)
	 cout<< r[i] <<" ";
}
/* 
 Time-Complexity = O(N)
 Space-Complexity = O(N)
 */
 
/*
Input :- 0 2 4 6 8 10 12 14 16 18 
Output :- 0 2 2 2 2 2 2 2 2 2 
*/
