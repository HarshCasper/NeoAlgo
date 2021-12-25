/* 
The adjacent_difference algo produces a new sequence
in which each element is difference between adjacent 
elements in original sequence. 
*/

#include<bits/stdc++.h>
using namespace std;
 
void adjacent_difference()
{
      int num;
      cout << "Enter the no. of values :" << endl;
      cin >> num;
	vector<int> v(num), r(num);
	
	for(int i=0; i<num; i++)
	{
		v[i] = i*2;
	}

	cout << "Original sequence :" << endl;
	for(int i=0; i<num; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	
	adjacent_difference(v.begin(), v.end(), r.begin());
	
	cout<<"Resulting sequence :" << endl;
	for(int i=0; i<num; i++)
	{
		cout<< r[i] <<" ";
	}
}
 
int main()
{
	adjacent_difference();
	return 0; 
}
	
/*
Sample Output:
Enter the no. of values :                                                                                                                       
5                                                                                                                                               
Original sequence :                                                                                                                             
0 2 4 6 8                                                                                                                                       
Resulting sequence :                                                                                                                            
0 2 2 2 2 
*/

/*
Time-Complexity = O(N)
Space-Complexity = O(N)
*/
