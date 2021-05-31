/* Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, 
return the volume of water it can trap after raining. */

import java.util.*;

class Trapping_rain_water_2D {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        // Taking user input
        System.out.println("Enter the number of rows: ");
        int rows = scn.nextInt();
        System.out.println("Enter the number of columns: ");
        int columns = scn.nextInt();
        
        // creating 2D Matrix
        int[][] arr = new int[rows][columns];

        // Filling the array
        System.out.println("Enter the Elements: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                arr[i][j] = scn.nextInt();
            }
        }

        int water = trapRainWater(arr);
        System.out.println("Water it can trap is: " + water +" units");

        scn.close();
    }

    // Creating helper class to store value and row, column numbers
    public static class Pair implements Comparable<Pair> {
        // declaring instance variables
        int i;
        int j;
        int val;

        // constructor
        public Pair(int i, int j, int val) {
            this.i = i;
            this.j = j;
            this.val = val;
        }

        // Overriding method of Comparable interface to compare objects on basis of val
        @Override
        public int compareTo(Pair object) {
            return this.val - object.val;
        }
        // if +ve value returned -- object.val is selected
        // if -ve value returned -- this.val is selected
        // if 0 is returned -- any value between the two can be selected
    }

    public static int trapRainWater(int[][] heightMap) {
        // storing the lengths of row and column in m and n respectively
        int m = heightMap.length, n = heightMap[0].length;
        
        // edge case
        if (m == 1 || n == 1)
            return 0;

        // Minimum Priority Queue
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        boolean[][] visited = new boolean[m][n];
        
        // marking the corners of the elevation map as true
        visited[0][0] = true;
        visited[0][n - 1] = true;
        visited[m - 1][0] = true;
        visited[m - 1][n - 1] = true;

        // Adding the boundary in priority queue
        // Marking the cells of boundary true in visited array
        // left and right walls
        for (int i = 1; i < n - 1; i++) {
            pq.add(new Pair(0, i, heightMap[0][i]));
            pq.add(new Pair(m - 1, i, heightMap[m - 1][i]));
            visited[0][i] = true;
            visited[m - 1][i] = true;
        }

        // top and bottom walls
        for (int i = 1; i < m - 1; i++) {
            pq.add(new Pair(i, 0, heightMap[i][0]));
            pq.add(new Pair(i, n - 1, heightMap[i][n - 1]));
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        // Distance between four adjacent cells of current cell(x,y)
        int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        
        // init result
        int ans = 0;

        // Calculating result by shifting boundary inward
        while (!pq.isEmpty()) {
            Pair cell = pq.remove();
            for (int[] dir : directions) {
                int r = cell.i + dir[0];
                int c = cell.j + dir[1];
                if (r >= 0 && r <= m - 1 && c >= 0 && c <= n - 1 && visited[r][c] == false) {
                    ans += Math.max(0, cell.val - heightMap[r][c]);
                    pq.add(new Pair(r, c, Math.max(heightMap[r][c], cell.val)));
                    visited[r][c] = true;
                }
            }
        }

        // return ans
        return ans;
    }
}

/*
Time Complexity: O(m*n*log(m*n))
Space Complexity: O(m*n)

Sample Input/Output

Example 1:

Enter the number of rows: 
3
Enter the number of columns:
6
Enter the elements: 
1 4 3 1 3 2
3 2 1 3 2 4
2 3 3 2 3 1
Water it can trap is: 4 units

Example 2:

Enter the number of rows: 
5
Enter the number of columns:
5
Enter the elements: 
3 3 3 3 3 
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
Water it can trap is: 10 units
*/