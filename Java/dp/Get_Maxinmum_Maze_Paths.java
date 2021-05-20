// Problem Link- https://www.geeksforgeeks.org/count-number-ways-reach-destination-maze/ 
/* You are given a number n and a number m representing number of rows and columns in a maze.
 * You are standing in the top-left corner and have to reach the bottom-right corner.
 * Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
 * you need to find out the total number of ways you can reach from current position to the destination
 */
 
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList <String> paths = getMazepaths(1,1,n,m);
        
        System.out.println(paths);
    }
    
    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static ArrayList <String> getMazepaths(int sr, int sc, int dr, int dc) {
        
        if(sr == dr && sc == dc){
        ArrayList <String> bres = new ArrayList<>();
        bres.add("");
        return bres;
        }
        
        ArrayList <String> hpaths = new ArrayList<>();
        ArrayList <String> vpaths = new ArrayList<>();
        
        if(sc < dc){
            hpaths = getMazepaths(sr, sc+1, dr, dc);
        }
        if(sr < dr){
            vpaths = getMazepaths(sr+1, sc, dr, dc);
        }
        
        ArrayList <String> paths = new ArrayList<>();
        
        for(String hpath : hpaths){
            paths.add("h" + hpath);
        }
        for(String vpath : vpaths){
            paths.add("v" + vpath);
        }
        return paths;
}
}

/*
 * Sample input- 3 3
 * Sample Output- [hhvv, hvhv, hvvh, vhhv, vhvh, vvhh]
 * Sample input- 4 4
 * Sample Output- [hhhvvv, hhvhvv, hhvvhv, hhvvvh, hvhhvv, hvhvhv, hvhvvh, hvvhhv, hvvhvh, hvvvhh, vhhhvv, vhhvhv, vhhvvh, vhvhhv, vhvhvh, vhvvhh, vvhhhv, vvhhvh, vvhvhh, vvvhhh]
 */

 /* Time Complexity: O(N^2) 
  * Auxiliary Space: O(N)
*/