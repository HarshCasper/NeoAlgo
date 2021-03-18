//finding duplicate elements 
/*elements occuring twice in array is considered duplicate
here and rest occur only once
*/

#include <iostream>
using namespace std;


int main(){
int n;
cin>>n;  
int arr[n]  ;  
for(int i=0;i<n ; i++){
cin>>arr[i];
}  
for (int i = 0; i < n; i++)  
{  
for (int j = i+1; j < n; j++)  
{  
int t = arr[i] ^ arr[j];  

if (t == 0)  
{  
cout<< "Duplicate Element in array = "<<arr[i]<<endl;  
}  
}  
}  
return 0;  
}  


// Time Complexity - O(n^2)
// Space Complexity - O(n^2)

/*Sample Input:

Example 1:- 
7
3 2 1 3 4 5 4 
Example 2:-
10
1 5 6 4 5 4 1 2 3 2

Sample Output:

Example 1:- 
Repeated Element in array = 3
Repeated Element in array = 4
Example 2:-
Repeated Element in array = 1
Repeated Element in array = 5
Repeated Element in array = 4
Repeated Element in array = 2

*/