/*
Topological ordering of a directed graph is a linear ordering of its 
vertices such that for every directed edge uv from vertex u to vertex v,
u comes before v in the ordering. To perform this sorting the graph must 
be Direct acyclic graph(DAG).

*/

using System;
using System.Collections.Generic;

namespace Topoplogical_Sorting
{
    public class Graph
    {
        //Number of vertices
        private int vertices;
        //Adjacency list
        List<int>[] adjList;
        public Graph(int v)
        {
            vertices = v;
            adjList = new List<int>[v];
            for (int i = 0; i < v; i++)
            {
                adjList[i] = new List<int>();
            }
        }
        //Add direct edge from vertex u to vertex v
        public void AddEdge(int u, int v)
        {
            adjList[u].Add(v);
        }
        //Modified DFS algorithm to traverse the graph
        public void ModifiedDFS(int v, bool[] visited, Stack<int> stack)
        {
            visited[v] = true;
            List<int> connected_vertices = adjList[v];
            foreach (var vertex in connected_vertices)
            {
                //if the vertex not visited recurse
                if (!visited[vertex])
                {
                    ModifiedDFS(vertex, visited, stack);
                }
            }
            //add the vertex to stack after it is visited and its children
            stack.Push(v);
        }
        //Call Modified DFS and perform topological sorting
        public void TopologicalSort()
        {
            bool[] visited = new bool[vertices];
            Stack<int> stack = new Stack<int>();
            for (int i = 0; i < vertices; i++)
            {
                if (!visited[i])
                    ModifiedDFS(i, visited, stack);
            }
            while(stack.Count != 0)
                Console.Write(stack.Pop() + " ");
        }
        public void TopologicalSort(int start_vertex)
        {
            bool[] visited = new bool[vertices];
            Stack<int> stack = new Stack<int>();
            ModifiedDFS(start_vertex, visited, stack);
            while (stack.Count != 0)
                Console.Write(stack.Pop() + " ");
        }
        static void Main(string[] args)
        {
            Console.Write("Enter Number of vertices: ");
            int n = Convert.ToInt32(Console.ReadLine());
            Graph g = new Graph(n);
            Console.Write("Enter number of Edges: ");
            int num_edges = Convert.ToInt32(Console.ReadLine());
            while (num_edges != 0)
            {
                Console.Write("Enter Number of first Vertex: ");
                int u = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter Number of second Vertex: ");
                int v = Convert.ToInt32(Console.ReadLine());
                g.AddEdge(u, v);
                num_edges--;
            }
            Console.WriteLine("Do you want Topological sort of the whole graph (YES/NO): ");
            string choice = Console.ReadLine();
            if (choice == "YES")
            {
                Console.WriteLine("Topological sort of the graph");
                g.TopologicalSort();
            }
            else
            {
                Console.Write("Enter your start vertex: ");
                int start = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine($"Topological sort from vertex {start}");
                g.TopologicalSort(start);
            }


        }
    }
}
/*
 Sample Input
Enter Number of vertices: 6
Enter number of Edges: 6
Enter Number of first Vertex: 5
Enter Number of second Vertex: 2
Enter Number of first Vertex: 5
Enter Number of second Vertex: 0
Enter Number of first Vertex: 4
Enter Number of second Vertex: 0
Enter Number of first Vertex: 4
Enter Number of second Vertex: 1
Enter Number of first Vertex: 2
Enter Number of second Vertex: 3
Enter Number of first Vertex: 3
Enter Number of second Vertex: 1

Do you want Topological sort of the whole graph (YES/NO): YES
Topological sort of the graph
5 4 2 3 1 0 

Time Complexity: O(m+n)
Space Complexty: O(n)
 
 */
