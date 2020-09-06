class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arrLL;
        
        //EDGE CASE
        if (matrix.size()  == 0) return arrLL;
        
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        
        if (m == 1 && n == 1) {
            arrLL.push_back(matrix[0][0]);
            return arrLL;
        }
        
        if (m == 1) {
            for (int j = 0; j < n; j++){
                arrLL.push_back(matrix[0][j]);
                
            }
            return arrLL;
        }
        
        if (n == 1){
            for (int i = 0; i < m; i++){
                arrLL.push_back(matrix[i][0]);
                
            }
            return arrLL;
        }
        
        int i, j, k1, k2, itr = 0;
        while (j < n || i < m || j > k1 || i > k2){
           
            bool one = false;
            while (j < n ){
                if (i != itr || i >= m) break;
                arrLL.push_back(matrix[i][j]);
                j++;
                one = true;
            }
        
            i++; j--; n--;
            bool b = false;
            while (i < m && one == true){
                arrLL.push_back(matrix[i][j]);
                b = true;
                i++;
            }
            
            j--; i--; m--;
            
            bool bk = false;
            while ( j>= k1  && b == true){
                arrLL.push_back(matrix[i][j]);
                j--;
                bk = true;
            }
            
            j++; i--; k1++;
            
            
            while ( i > k2 && bk == true) {
                arrLL.push_back(matrix[i][j]);
                i--;
            }
            
            j++; i++; k2++;
            itr ++;
        }
        
        return arrLL;
        
    
    }
};

/*
TEST CASE

TIME COMPLEXITY : 0(N*M) 
SPACE COMPLEXITY: 0(N+M)

where N is number of rows and M is number of columns

INPUT
[[ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]]

OUTPUT
[1,2,3,6,9,8,7,4,5]

INPUT
[[1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]]

OUTPUT
[1,2,3,4,8,12,11,10,9,5,6,7]
*/
