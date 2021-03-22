using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeoAlgo
{
    class AdjacencyMatrix
    {
        static void Main()
        {
            bool isExecuted = GenerateAdjancencyMatrix();
            if (!isExecuted)
            {
                Console.WriteLine("Error generating adjacency Matrix");
            }

            Console.ReadLine();
        }

        static bool GenerateAdjancencyMatrix()
        {
            List<string> vertices = new List<string>();

            Console.Write("Supply Space Seperated Unique Vertex Name : ");
            vertices.AddRange(Console.ReadLine().Trim().Split(' ').ToHashSet());

            Console.Write("Supply Number of Edges : ");
            bool canParse = int.TryParse(Console.ReadLine().Trim(), out int graphSize);
            if (!canParse)
            {
                Console.WriteLine("Please Supply Integer Only as Size of Graph");
                return false;
            }

            byte[,] adjacencyMatrix = new byte[vertices.Count, vertices.Count];

            int startVertexPos, endVertexPos;
            for (int edge = 1; edge <= graphSize; edge++)
            {
                Console.Write($"Supply Space Seperated Start Vertex and End Vertex of Edge {edge} : ");
                string[] endPoints = Console.ReadLine().Trim().Split(' ');
                if (endPoints.Length != 2)
                {
                    Console.WriteLine("Please Supply Starting Vertex and End Vertex of Edge Properly");
                    return false;
                }

                if (((startVertexPos = vertices.IndexOf(endPoints[0])) == -1) || ((endVertexPos = vertices.IndexOf(endPoints[1])) == -1))
                {
                    Console.WriteLine("Invalid Vertex Specified");
                    return true;
                }

                adjacencyMatrix[startVertexPos, endVertexPos] = 1;
            }

            foreach (string vertex in vertices)
            {
                Console.Write($"{vertex} ");
            }
            Console.WriteLine();

            for (byte row = 0; row < adjacencyMatrix.GetLength(0); row++)
            {
                for (byte col = 0; col < adjacencyMatrix.GetLength(1); col++)
                {
                    Console.Write($"{adjacencyMatrix[row, col]} ");
                }
                Console.WriteLine();
            }

            return true;
        }
    }
}
