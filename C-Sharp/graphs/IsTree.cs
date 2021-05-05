/*
 * The Problem is Checking if a Graph is a Tree or not
 * Complexity O(V+E)
 * V: No. of Vertices
 * E: No. of Edges
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeoAlgo
{
    class Program
    {
        /*
         * Using DFS Algorithm to check if node is visited(W) or Not Visited(G)
         * If it's not Visited it will mark it as visited and visit its neighbours
         * If it's visited, it will return true (it's Cycle)
        */
        static bool DFS(string u, ref Dictionary<string, char> Color, ref Dictionary<string, List<string>> Graph, ref Dictionary<string, string> Parent)
        {
            Color[u] = 'G';
            //Node u is visited but its neighbours not
            foreach (string v in Graph[u])
            {
                if (Color[v] == 'W')
                {
                    Parent[v] = u;
                    if (DFS(v, ref Color, ref Graph, ref Parent))
                        return true;
                }
                else if (Color[v] == 'G')
                    return true;
            }
            Color[u] = 'B';
            //Node u is visited and finished visiting its neighbours
            return false;
        }
        static bool isCycle(string[] vertices, List<KeyValuePair<string, string>> edges)
        {

            Dictionary<string, char> Color = new Dictionary<string, char>();
            Dictionary<string, string> Parent = new Dictionary<string, string>();
            Dictionary<string, List<string>> Graph = new Dictionary<string, List<string>>();
            int j = 0;
            for (int i = 0; i < edges.Count;)
            {
                if (Graph.ContainsKey(edges[i].Key))
                {

                    Graph[edges[i].Key].Add(edges[i].Value);
                    i++;
                }
                else
                {
                    if (j < vertices.Length)
                    {
                        if (vertices[j] == edges[i].Key)
                        {
                            List<string> L = new List<string>();
                            L.Add(edges[i].Value);
                            Graph.Add(vertices[j], L);
                            i++;
                        }
                        else
                            Graph.Add(vertices[j], new List<string>());
                    }
                    j++;
                }
                if (j < vertices.Length && i < edges.Count && vertices[j] != edges[i].Key)
                {
                    if (!Graph.ContainsKey(vertices[j]))
                        Graph.Add(vertices[j], new List<string>());
                    j++;
                }
            }
            while (j < vertices.Length)
            {
                Graph.Add(vertices[j], new List<string>());
                j++;
            }
            Parent[vertices[0]] = "Nan";
            for (int i = 0; i < vertices.Length; i++)
            {
                Color[vertices[i]] = 'W';
                // All nodes are not visited
            }
            for (int i = 0; i < vertices.Length; i++)
            {
                //Calling DFS Algorithm
                if (DFS(vertices[i], ref Color, ref Graph, ref Parent))
                    return true;
            }
            return false;
        }
        public static bool IsTree(string[] vertices, List<KeyValuePair<string, string>> edges)
        {
            /*
             * If it's a Cycle so it's not a tree as a node in a tree doesn't return back to node before it
             */
            if (!isCycle(vertices, edges))
                return true;
            else
                return false;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Enter No. of Vertices: ");
            int V = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter No. of Edges: ");
            int E = int.Parse(Console.ReadLine());
            string[] Vertices = new string[V];
            for (int i = 0; i < V; i++)
            {
                Vertices[i] = Console.ReadLine();
            }
            List<KeyValuePair<string, string>> Edges = new List<KeyValuePair<string, string>>(E);
            for (int i = 0; i < E; i++)
            {
                string First = Console.ReadLine();
                String Second = Console.ReadLine();
                KeyValuePair<string, string> K = new KeyValuePair<string, string>(First, Second);
                Edges.Add(K);
            }
            Console.WriteLine(IsTree(Vertices, Edges)); ;
        }
    }
}
