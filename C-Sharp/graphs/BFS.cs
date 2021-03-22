using System;
using System.Linq;
using System.Collections.Generic;

namespace NeoAlgo
{
    class BFS
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
            Console.ReadLine();
        }

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

        static void GraphTraversal(Dictionary<string, Vertex> graph)
        {
            Queue<Vertex> traverseQueue = new Queue<Vertex>();
            Vertex unvisited;
            while ((unvisited = FindUntraversedVertex(graph)) != null)
            {
                traverseQueue.Enqueue(unvisited);
                while (traverseQueue.Count > 0)
                {
                    Vertex vertex = traverseQueue.Dequeue();
                    vertex.Traversed = true;
                    Console.Write($"{vertex.Value} ");

                    foreach (Edge incidentEdge in vertex.Edges)
                    {
                        if (!incidentEdge.EndVertex.Traversed)
                        {
                            traverseQueue.Enqueue(incidentEdge.EndVertex);
                        }
                    }
                }
                Console.WriteLine();
            }
        }

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

        private class Edge
        {
            internal Vertex EndVertex { get; set; }
        }
    }
}
