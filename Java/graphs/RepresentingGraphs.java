/*
Introduction:
Graphs can be represented using adjacency lists in the memory.An adjacency list is basically a 2D array that mentions all the vertices connected to a particular vertex of the graph.
In Java,it could be implemented using arraylists(Dynamic array).
This program asks the user the number of vertices and edges in the graph(undirected) that the user wants to create.
It adds the vertex number in the list corresponding to which it is connected.
At last, it prints the vertices of the list along with their respective connected adjacent vertices one by one.
This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs.
For simplicity,the vertices are named in terms of natural numbers(1,2,3...)
*/
import java.util.*;
public class RepresentingGraphs {

    //This method adds the vertex to its adjacent vertex and vice versa in the list
    static void addEdge(ArrayList<ArrayList<Integer> >list ,int a, int b)
    {
        list.get(a).add(b);//connecting b to a
        list.get(b).add(a);//connecting a to b
    }

    //This method prints the list one by one
    static void printList(ArrayList<ArrayList<Integer> > list)
    {
        System.out.println("Adjacency list of vertices");
        for (int i = 0; i < list.size(); i++)
         {
            System.out.print(i+1);
            for (int j = 0; j < list.get(i).size(); j++) 
            {
                int t=list.get(i).get(j)+1;
                System.out.print(" -> "+ t);
            }
            System.out.println();
        }
    }
    public static void main(String[] args)
    {
        System.out.println("Enter the number of vertices");//input for the number of vertices
        Scanner sc=new Scanner(System.in);
        int v=sc.nextInt();

        ArrayList< ArrayList<Integer> > list = new ArrayList<ArrayList<Integer> >(v);//A 2D dynamic array of size equal to the number of vertices

        //The rows in the arraylist represent vertices
        for(int i=0;i<v;i++)
        {
            list.add(new ArrayList<Integer>());
        }

        System.out.println("Enter the number of edges");//input for the number of edges
        int e=sc.nextInt();

        for(int i=0;i<e;i++)
        {
            System.out.println("Enter the adjacent vertices of the edge: ");//input for the adjacent pair of vertices
            int a=sc.nextInt();
            int b=sc.nextInt();
            addEdge(list,a-1,b-1);
        }
        printList(list);
    }
    
}
/*
Test Case:

       1----2     
      /|   /|
     5 |  / |
      \| /  |
       4----3

Enter the number of vertices 5
Enter the number of edges    7
Enter the adjacent vertices of the edge: 
5 1
5 4
1 2
1 4
4 2
4 3
2 3
Adjacency list of vertices
1 -> 5 -> 2 -> 4
2 -> 1 -> 4 -> 3
3 -> 4 -> 2
4 -> 5 -> 1 -> 2 -> 3
5 -> 1 -> 4
This list tells us about the graph,the vertex 1 is adjacent to 5,2,4,vertex 2 is adjacent to 1,4,3 and so on.
Space Complexity:
Worst Case:O(V^2)
Otherwise,O(|E|+|V|)
|E|:Total number of edges
|V|:Total number of vertices
*/

