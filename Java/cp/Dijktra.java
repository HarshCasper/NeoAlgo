
/*Java program to find the shortest path using Dijktra's algorithm */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class Dijktra {

    /*Fast Reader is a user defined method which uses the time advantage of BufferedReader 
    and StringTokenizer and the advantage of user-defined methods for less typing and therefore 
    a faster input altogether.*/

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
    
  public static void main(String[] args) {

    //initialize FastReader
      FastReader in=new FastReader();
      int t=in.nextInt();
        for(int j=0;j<t;j++){

        // initialize nodes and edges
        int a=in.nextInt();
        int b=in.nextInt();
        long arr[][]=new long [a+1][a+1];
        for (long[] row: arr)
          //Filling the array
            Arrays.fill(row, 1000000l);
         for(int i=0;i<b;i++){

            // Filling of edges
             int x=in.nextInt(),y=in.nextInt();
             long c=in.nextLong();
             if(arr[x][y]>c){
                arr[x][y]=c; arr[y][x]=c;
             }}
         Stack <Integer> stk=new Stack<Integer>();
          int src=in.nextInt();
        for(int i=1;i<=a;i++){
            if(i!=src){stk.push(i);}}
        Stack <Integer> p=new Stack<Integer>();
        p.push(src);
        arr[src][src]=0;
         while(!stk.isEmpty()){int min=989997979,loc=-1;

        // Checking the shortest path
        for(int i=0;i<stk.size();i++){
            arr[src][stk.elementAt(i)]=Math.min(arr[src][stk.elementAt(i)],arr[src][p.peek()]+arr[p.peek()][stk.elementAt(i)]);
            if(arr[src][stk.elementAt(i)]<=min){
                min=(int) arr[src][stk.elementAt(i)];loc=i;}
        }
        p.push(stk.elementAt(loc));stk.removeElementAt(loc);}
         for(int i=1;i<=a;i++){
             // Print the result
             if(i!=src && arr[src][i]!=1000000l){System.out.print(arr[src][i]+" ");}
             else if(i!=src){System.out.print("-1"+" ");}
         }System.out.println();
         }
  }}

/* Time Complexity: O(a*a)
   Space Complexity: O(a*a)

   Example:
   Input:
   1
   5 3
   1 2 10
   1 3 6
   2 4 8
   2

   Output:
   10 16 8 -1 
*/

