'''
A matrix[m][n] & an integer k returns matrix where each matrix[i][j] is the sum of all element of matrix[r][c]
for i - k <= r <= i+k , j - k <= c <= j+k where r,c are valid positions in matrix.
'''

// C++ Code:

#include <bits/stdc++.h>
using namespace std;
void print_blocksum(vector<vector<auto> > sz)  // Block matrix representation of each sum
{
   cout << "[";
   for(int i = 0; i<sz.size(); i++){
      cout << "[";
      for(int j = 0; j <sz[i].size(); j++){
         cout << sz[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]"<<endl;
}
class Solution {
public:
   vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
      int n = mat.size();
      int m = mat[0].size();
      vector < vector <int> > res(n , vector <int> (m));  // Computing the matrix
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            for(int r = i - k;r <= i + k; r++){
               for(int c = j - k; c <= j + k; c++){
                  if(r>= 0 && r < n && c >= 0 && c < m){
                     res[i][j] += mat[r][c]; //result add
                  }
               }
            }
         }
      }
      return res;
   }
};
main(){
   std::vector<vector<int>> sz1;  //Enter the input from user
   int size,temp;
   cin>>size;
   for(int i=0; i< size; i++){
      vector<int>v1;
      for(int j=0; j< size; j++){
         cin>>temp;
         v1.push_back(temp); 
      }
      sz1.push_back(v1);
   }
   Solution ob;
   print_blocksum(ob.matrixBlockSum(sz1, 1));
}


/*
Test Case1:
Input: mat= [[1,2,3], [4,5,6], [7,8,9]] , k=1

Output: [[12,21,16], [27,45,33], [24,39,28]]

Test Case2:
Input: mat= [[1,2,3], [4,5,6], [7,8,9]] , k=2

Output: [[45,45,45], [45,45,45], [45,45,45]]

Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/
