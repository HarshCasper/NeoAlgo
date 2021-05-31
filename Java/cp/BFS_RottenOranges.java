/*
  Rotten Oranges:
    We have to determine what is the minimum time required to rot all oranges. So basically we will use breadth first search using queue.
    We can go in four directions i.e. up, down, left and right. We traverse each node and if it is fresh or no oranges then we don't go to the
    breadth first search else we go and traverse through the matrix. 
    
    Hence we get the time by updating the level variable each time we put
    something in our queue that is the next iteration and hence we follow the same procedure starting from each rotten orange.
    The problem can also be found on geeksforgeeks for reference.

*/

import java.util.*;
import java.lang.*;
import java.io.*;
class BFS_RottenOranges
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc= new Scanner(System.in);
            System.out.println("Enter the dimention of the matrix: ");
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] grid = new int[n][m];
      
            System.out.println("Enter values of the matrix which consists of 1 for fresh, 0 for no oranges, 2 for rotten oranges: ");
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    grid[i][j] = sc.nextInt();
                }
            }
            BFS_RottenOranges1 obj = new BFS_RottenOranges1();
            int ans = obj.orangesRotting(grid);
            System.out.println("The time taken to rot all oranges is: ");
            System.out.println(ans);

        sc.close();
    }
}// } Driver Code Ends


class BFS_RottenOranges1
{
    class Node{
        int i;
        int j;
        public Node(int i, int j){
            this.i=i;
            this.j=j;
        }
    }
    public int orangesRotting(int[][] grid)
    {
        int n= grid.length;
        int m= grid[0].length;
        
        Queue<Node> queue= new LinkedList<>();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2)
                    queue.add(new Node(i, j));
            }
        }
        // Adding the node in the queue only when it is a rotten orange that is its value is 2 in the matrix.
      
        int level=0;
        while(queue.isEmpty()==false){
            int size= queue.size();
            int flag=0;
            
            while(size>0){
                Node curr= queue.poll();
                grid[curr.i][curr.j]=2;
                
                if(isValid(curr.i, curr.j+1, grid)){
                    grid[curr.i][curr.j+1]=2;
                    queue.add(new Node(curr.i, curr.j+1));
                    flag=1;}
                    
                if(isValid(curr.i+1, curr.j, grid)){
                    grid[curr.i+1][curr.j]=2;
                    queue.add(new Node(curr.i+1, curr.j));
                    flag=1;}
                    
                if(isValid(curr.i, curr.j-1, grid)){
                    grid[curr.i][curr.j-1]=2;
                    queue.add(new Node(curr.i, curr.j-1));
                    flag=1;}
                    
                if(isValid(curr.i-1, curr.j, grid)){
                    grid[curr.i-1][curr.j]=2;
                    queue.add(new Node(curr.i-1, curr.j));
                    flag=1;}
                    
                size-=1;
            }
            if(flag==1)
            level++;
        }
      
      // Checking if all the oranges are rotten or not through traversing the matrix.
      
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return level;
    }
    
    public static boolean isValid(int i, int j, int[][]grid){
        if(i>=0 && i<grid.length && j>=0 && j<grid[0].length && grid[i][j]==1)
            return true;
            
        return false;
    }
}

/* 

    Input: 
        3 3 
        0 1 2
        0 1 2  
        2 1 1
    Output: 1

    Input/Output Explanation:
    We will use bfs using a queue to find the time to rot all the oranges.
    Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time and hence within
    1 sec all the oranges present will be rotten.
    
    
    
    Time complexity- O(n*m)
    As we are traversing the array only once.
    Space complexity- O(n*m)

*/
