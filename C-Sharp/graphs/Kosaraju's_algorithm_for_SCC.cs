// Kosaraju-Sharir's algorithm is a linear time algorithm
// to find the strongly connected components of a directed graph.

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace SCC_
{
    // Strongly Connected Component
    class SCC
    {
        private int nodeNum;
        private Dictionary<int, int> stack;
        private Dictionary<int, List<int>> graph;
        private List<List<int>> scc = new List<List<int>>();
        private List<int> sccCount = new List<int>();

        public SCC()
        {
            this.nodeNum = 0;
            this.graph = new Dictionary<int, List<int>>();
            this.stack = new Dictionary<int, int>();
            // Lists for Strongly Connected Components
            this.scc = new List<List<int>>();
            // Length of Strongly Connected Components
            this.sccCount = new List<int>();
        }
        public SCC(Dictionary<int, List<int>> graph, int nodeNum)
        {
            this.nodeNum = nodeNum;
            this.graph = graph;
            this.stack = new Dictionary<int, int>();
            // Lists for Strongly Connected Components
            this.scc = new List<List<int>>();
            // Length of Strongly Connected Components
            this.sccCount = new List<int>();
        }
        // To Load your dataset
        public void LoadData(string path, int nodeNum)
        {
            this.nodeNum = nodeNum;
            using (var fileStream = new FileStream(path, FileMode.Open, FileAccess.Read))
            {
                using var sr = new StreamReader(fileStream, Encoding.UTF8);

                string[] content = sr.ReadToEnd().Split('\n');
                foreach (var element in content)
                {
                    int key = Convert.ToInt32(element.Split(' ')[0]);
                    if (!this.graph.ContainsKey(key))
                    {
                        this.graph[key] = new List<int>();
                        this.graph[key].Add(Convert.ToInt32(element.Split(' ')[1]));
                    }

                    else
                    {
                        this.graph[key].Add(Convert.ToInt32(element.Split(' ')[1]));
                    }
                }
            }
        }
        public int FirstPassDFS(Dictionary<int, List<int>> graph, int start, int t, Dictionary<int, bool> searched)
        {
            Stack<int> stack_ = new Stack<int>();
            stack_.Push(start);
            var v = new List<int>();
            while (stack_.Count != 0)
            {
                int vv = stack_.Pop();
                if (searched[vv] == false)
                {
                    v.Add(vv);
                    searched[vv] = true;
                    foreach (var i in graph[vv])
                        stack_.Push(i);
                }
            }
            int n = v.Count;
            t += n;
            for (int i = 0; i < n; i++)
            {
                if (!this.stack.ContainsKey(v[i]))
                    this.stack[v[i]] = t - i;
            }

            return t;
        }
        // To find the Stongly Connectected Component
        public List<int> SecondPassDFS(Dictionary<int, List<int>> graph, int start, Dictionary<int, bool> searched)
        {
            Stack<int> stack = new Stack<int>();
            stack.Push(start);
            var list = new List<int>();
            while (stack.Count != 0)
            {
                int v = stack.Pop();
                if (searched[v] == false)
                {
                    searched[v] = true;
                    list.Add(v);
                    foreach (var i in graph[v])
                        stack.Push(i);
                }
            }
            return list;
        }
        // To compute the finishing time of every node
        public void FirstPassAlgorithm(Dictionary<int, List<int>> graphRev, Dictionary<int, bool> searched, int t)
        {
            for (int i = this.nodeNum; i >= 1; i--)
            {
                if (searched.ContainsKey(i) && searched[i] == false)
                    t = FirstPassDFS(graphRev, i, t, searched);
            }
        }
        // To find the Stongly Connectected Components
        public void SecondPassAlgorithm(Dictionary<int, List<int>> graphWithFinishingTIme, Dictionary<int, bool> visited)
        {
            for (int i = this.nodeNum; i >= 1; i--)
            {
                if (visited.ContainsKey(i) && visited[i] == false)
                {
                    this.scc.Add(SecondPassDFS(graphWithFinishingTIme, i, visited));
                    // To add length of Strongly Connected Component
                    this.sccCount.Add(this.scc[scc.Count - 1].Count);
                }
            }
        }
        // To reverse all the directed edges in  agraph
        public void GraphRev()
        {
            Dictionary<int, List<int>> graphRev = new Dictionary<int, List<int>>();
            Dictionary<int, bool> searched = new Dictionary<int, bool>();
            int t = 0;
            // Reverse all Edges
            foreach (var i in this.graph.Keys)
            {
                foreach (var j in this.graph[i])
                {
                    if (!graphRev.ContainsKey(j))
                    {
                        graphRev[j] = new List<int>();
                        graphRev[j].Add(i);
                    }
                    else
                    {
                        graphRev[j].Add(i);
                    }
                }
            }

            // Add all nodes to searched list and assign it False
            foreach (var i in graphRev.Keys)
                searched[i] = false;

            // Add all nodes with no outgoing edges to searched list and assign it False
            foreach (var i in graphRev.Values)
            {
                foreach (var j in i)
                {
                    if (!searched.ContainsKey(j))
                        searched[j] = false;
                }
            }
            // Add all nodes with no outgoing edges to graphRev Dict and assign it []
            foreach (var i in searched.Keys)
            {
                if (!graphRev.ContainsKey(i))
                    graphRev[i] = new List<int>();

            }
            FirstPassAlgorithm(graphRev, searched, t);
        }
        // To create new graph with the finishing time of the nodes
        public void GraphWithFinishingTIme()
        {
            Dictionary<int, List<int>> graphWithFinishingTIme = new Dictionary<int, List<int>>();
            Dictionary<int, bool> visited = new Dictionary<int, bool>();
            foreach (var i in this.stack.Keys)
            {
                graphWithFinishingTIme[this.stack[i]] = new List<int>();
                if (this.graph.ContainsKey(i))
                {
                    foreach (var j in this.graph[i])
                    {
                        if (this.stack.ContainsKey(j))
                        {
                            graphWithFinishingTIme[this.stack[i]].Add(this.stack[j]);
                        }
                    }
                }
            }

            // Add all nodes with no outgoing edges to visited list and assign it False
            foreach (var i in graphWithFinishingTIme.Keys)
                visited[i] = false;

            SecondPassAlgorithm(graphWithFinishingTIme, visited);
        }

        // Apply the Kosaraju Algorithm
        public void KosarajuSCC()
        {
            GraphRev();
            GraphWithFinishingTIme();
        }

        //To get the length of every strongly connected component
        public List<int> SCC_Counts()
        {
            var descendingOrder = this.sccCount.OrderByDescending(i => i).ToList<int>();
            return descendingOrder;
        }

        // To get list of every strongly connected component
        public List<List<int>> Scc()
        {

            return this.scc;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Enter graph manually or load text file(0: for manual, Any other key: load tex file): ");
            string choice = Console.ReadLine();
            SCC g;
            if (choice == "0")
            {
                Dictionary<int, List<int>> graph = new Dictionary<int, List<int>>();
                Console.Write("Enter Number of nodes: ");
                int nodes = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter Number of Edges: ");
                int num_edges = Convert.ToInt32(Console.ReadLine());
                int c = num_edges;
                var edges = new List<int[]>();
                while (num_edges != 0)
                {
                    Console.Write($"Enter edge number {c - num_edges + 1}: ");
                    string[] edge = Console.ReadLine().Split(" ");
                    var edge__ = from i in edge
                                    select Convert.ToInt32(i);
                    int[] edge_ = edge__.ToArray();
                    edges.Add(edge_);
                    num_edges--;
                }

                foreach (var i in edges)
                {
                    if (!graph.ContainsKey(i[0]))
                        graph[i[0]] = new List<int>() { i[1] };
                    else
                        graph[i[0]].Add(i[1]);
                }
                g = new SCC(graph, nodes);
            }
            else
            {
                g = new SCC();
                Console.WriteLine("Enter Path for you data: ");
                string path = Console.ReadLine();
                Console.WriteLine("Enter Number of nodes: ");
                int nodes = Convert.ToInt32(Console.ReadLine());
                g.LoadData(path, nodes);
            }
            g.KosarajuSCC();
            Console.WriteLine("Length of at most Longest 5 Strongly Connected Components: ");
            var topFive = g.SCC_Counts().Take(5);
            foreach(var i in topFive)
                Console.Write(i + " ");
            Console.WriteLine();
            Console.WriteLine("Longest Strongly Connected Components: ");
            var topSCC = g.Scc()[0];
            foreach (var i in topSCC)
                Console.Write(i + " ");
        }
    }
}


/*

- Sample Input

-Input
- Enter graph manually or load text file(0: for manual, Any other key: load tex file): 0
- Enter Number of nodes: 8
- Enter Number of Edges: 11
- Enter edge number 1: 1 2
- Enter edge number 2: 2 3
- Enter edge number 3: 3 1
- Enter edge number 4: 3 4
- Enter edge number 5: 5 4
- Enter edge number 6: 6 4
- Enter edge number 7: 8 6
- Enter edge number 8: 6 7
- Enter edge number 9: 7 8
- Enter edge number 10: 4 3
- Enter edge number 11: 4 6

- Output
- Length of at most Longest 5 Strongly Connected Components:
- [7, 1]
- Longest Strongly Connected Components:
- [8, 6, 7, 5, 3, 1, 2]

- Time Complextiy = O(m+n)S
- Space Complextiy = O(n)
    
    */

