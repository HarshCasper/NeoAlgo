import java.util.*;
import java.lang.*;
import java.io.*;

class SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> arrLL = new ArrayList<>();
        
        //EDGE CASE
        if (matrix.length == 0) return arrLL;
        
        int m = matrix.length;      // Number of rows
        int n = matrix[0].length;  // Number of columns
        
        if (m == 1 && n == 1) {
            arrLL.add(matrix[0][0]);
            return arrLL;
        }
        
        if (m == 1) {
            for (int j = 0; j < n; j++){
                arrLL.add(matrix[0][j]);
                
            }
            return arrLL;
        }
        
        if (n == 1){
            for (int i = 0; i < m; i++){
                arrLL.add(matrix[i][0]);
                
            }
            return arrLL;
        }
        
        
        int i, j, k1, k2, itr = 0;
        while (j < n || i < m || j > k1 || i > k2){
            boolean one = false;
            while (j < n ){
                if (i != itr || i >= m) break;
                arrLL.add(matrix[i][j]);
                j++;
                one = true;
            }
        
            i++; j--; n--;
            boolean b = false;
            while (i < m && one == true){
                arrLL.add(matrix[i][j]);
                b = true;
                i++;
            }
            
            j--; i--; m--;
            
            boolean bk = false;
            while ( j>= k1  && b == true){
                arrLL.add(matrix[i][j]);
                j--;
                bk = true;
            }
            
            j++; i--; k1++;
            
            while ( i > k2 && bk == true) {
                arrLL.add(matrix[i][j]);
                i--;
            }
            
            j++; i++; k2++;
            itr ++;
        }
        return arrLL;
    }
}

/*
TEST CASE

TIME COMPLEXITY : 0(N*M) 
SPACE COMPLEXITY: 0(N+M)

where M is number of rows and N is number of columns

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

