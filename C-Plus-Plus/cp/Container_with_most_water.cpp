class Container_with_most_Water {
public:
    int calculate(int i, int j, int x1, int x2){
        int part1 = min(x1,x2);
        return part1 * abs(j - i);
    }
    
    int maxArea(vector<int>& height) {
        
        int max  = 0;
        int i = 0;    // left pointer
        int j = height.size() - 1;    // right pointer
        
        while (i < j){
            int curr = calc(i,j, height[i], height[j]);
            if (curr > max) max = curr;
            if (height[i] < height[j]) i++;     
            else j--;
        }
        return max;  // Returning maxarea
    
    }
};

/*

TIME COMPLEXITY
2 POINTER APPROACH USED
O(N) where n is the size of the array

TEST CASE

INPUT
[1,8,6,2,5,4,8,3,7]
OUTPUT
49
*/


