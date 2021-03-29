using System;
using System.Linq;
using System.Collections.Generic;

namespace NeoAlgo
{
    class DFS
    {
        static void Main()
        {
            bool graphGenrated = GenerateGraph(out Dictionary<string, Vertex> graph);
            if (!graphGenrated)
            {
                Console.WriteLine("Some Problem Occurred Genrating the Graph");
                return;
            }
            GraphTraversal(graph);
            ResetGraph(graph);
            Console.ReadLine();
        }

        /// <summary>
        /// Given the vertices and edges input by user this function generates a graph and 
        /// </summary>
        /// <param name="graph">Dictionary representing the graph</param>
        /// <returns>true if graph is generated, false otherwise</returns>
        static bool GenerateGraph(out Dictionary<string, Vertex> graph)
        {
            graph = new Dictionary<string, Vertex>();

            Console.Write("Supply Vertices of Graph Seperated by Space : ");
            HashSet<string> vertices = Console.ReadLine().Trim().Split(' ').ToHashSet();

            foreach (string vertex in vertices)
            {
                graph.Add(vertex, new Vertex(vertex));
            }

            Console.Write("Supply Number of Edges : ");

            bool canParse = int.TryParse(Console.ReadLine().Trim(), out int graphSize);

            if (!canParse)
            {
                Console.WriteLine("Size of graph must be an integer. Please try again");
                return false;
            }

            for (int edge = 1; edge <= graphSize; edge++)
            {
                Console.Write($"Supply Space Seperated Start and End Vertex of Edge {edge}: ");
                string[] endPoints = Console.ReadLine().Trim().Split(' ');

                if (endPoints.Length != 2)
                {
                    Console.WriteLine("Please Supply Edge is Specified Form.");
                    return false;
                }

                if (!graph.ContainsKey(endPoints[0]) || !graph.ContainsKey(endPoints[1]))
                {
                    Console.WriteLine("Make Sure to Supply Valid Vertex Name For Edges");
                    return false;
                }

                Vertex startVertex = graph[endPoints[0]], endVertex = graph[endPoints[1]];
                Edge newEdge = new Edge() { EndVertex = endVertex };
                startVertex.Edges.Add(newEdge);
            }

            return true;
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="graph">This dictionary represents graph</param>
        static void GraphTraversal(Dictionary<string, Vertex> graph)
        {
            Stack<Vertex> traverseStack = new Stack<Vertex>();
            Vertex unvisited;
            while ((unvisited = FindUntraversedVertex(graph)) != null)
            {
                traverseStack.Push(unvisited);
                while (traverseStack.Count > 0)
                {
                    Vertex vertex = traverseStack.Pop();
                    vertex.Traversed = true;
                    Console.Write($"{vertex.Value} ");

                    foreach (Edge incidentEdge in vertex.Edges)
                    {
                        if (!incidentEdge.EndVertex.Traversed)
                        {
                            traverseStack.Push(incidentEdge.EndVertex);
                        }
                    }
                }
                Console.WriteLine();
            }
        }

        /// <summary>
        /// In case of disconnected graph, for the generation of DFS forest(instead of single tree) this method find untraversed vertices 
        /// </summary>
        /// <param name="graph">Dictionary representing the graph</param>
        /// <returns></returns>
        static Vertex FindUntraversedVertex(Dictionary<string, Vertex> graph)
        {
            foreach (KeyValuePair<string, Vertex> graphVertice in graph)
            {
                if (!graphVertice.Value.Traversed)
                {
                    return graphVertice.Value;
                }
            }
            return null;
        }

        /// <summary>
        /// Resetting states of all vertex after DFS traversal
        /// </summary>
        /// <param name="graph"></param>
        static void ResetGraph(Dictionary<string, Vertex> graph)
        {
            foreach (KeyValuePair<string, Vertex> graphVertex in graph)
            {
                graphVertex.Value.Traversed = false;
            }
        }


        /// <summary>
        /// Vertex reprsents each vertex within the graph having three properteies 
        /// Value represents actual name of the vertex
        /// Traversed determines whether the vertex has already been traversed or not
        /// Edges determines list of edges to denote edges adjacent to vertex. 
        /// </summary>
        private class Vertex
        {
            internal string Value { get; set; }
            internal bool Traversed { get; set; }
            internal List<Edge> Edges { get; set; }

            internal Vertex(string value)
            {
                Value = value;
                Edges = new List<Edge>();
                Traversed = false;
            }
        }

        /// <summary>
        /// Edge encapsulates end vertex
        /// </summary>
        private class Edge
        {
            internal Vertex EndVertex { get; set; }
        }
    }
}
