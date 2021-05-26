/*
  Problem:
    We have to determine what is the minimum time required to rot all oranges.
    We can go in four directions i.e. up, down, left and right.
    The problem can also be found on geeksforgeeks fro reference.

    Input: 
        3 3 
        0 1 2
        0 1 2  
        2 1 1
    Output: 1

  Explanation:
    We will use bfs using a queue to find the time to rot all the oranges.
    Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.
*/

import java.util.*;
import java.lang.*;
import java.io.*;
class BFS_RottenOranges
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc= new Scanner(System.in);
            
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] grid = new int[n][m];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    grid[i][j] = sc.nextInt();
                }
            }
            BFS_RottenOranges1 obj = new BFS_RottenOranges1();
            int ans = obj.orangesRotting(grid);
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
    Time complexity- O(n*m)
    As we are traversing the array only once.
    Space complexity- O(n*m)

*/