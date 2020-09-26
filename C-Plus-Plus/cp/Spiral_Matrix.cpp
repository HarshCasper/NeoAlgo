class Spiral_Matrix {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arrLL;
        
        //EDGE CASE
        if (matrix.size()  == 0) return arrLL;
        
        int rows = matrix.size() ;
        int columns = matrix[0].size() ;
        
        if (rows == 1 && columns == 1) {
            arrLL.push_back(matrix[0][0]);
            return arrLL;
        }
        
        if (rows == 1) {
            for (int j = 0; j < columns; j++){
                arrLL.push_back(matrix[0][j]);  
            }
            return arrLL;
        }
        
        if (columns == 1){
            for (int i = 0; i < rows; i++){
                arrLL.push_back(matrix[i][0]);  
            }
            return arrLL;
        }
        
        int i, j, k1, k2, itr = 0;
        while (j < columns || i < rows || j > k1 || i > k2){
           
            bool cond1 = false;
            while (j < columns ){
                if (i != itr || i >= rows) break;
                arrLL.push_back(matrix[i][j]);
                j++;
                cond1 = true;
            }
        
            i++; j--; n--;
            bool cond2 = false;
            while (i < rows && cond1 == true){
                arrLL.push_back(matrix[i][j]);
                cond2 = true;
                i++;
            }
            
            j--; i--; m--;
            bool cond3 = false;
            while ( j>= k1  && cond2 == true){
                arrLL.push_back(matrix[i][j]);
                j--;
                cond3 = true;
            }
            
            j++; i--; k1++;
            while ( i > k2 && cond3 == true) {
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
