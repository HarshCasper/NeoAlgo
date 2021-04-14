/*
* The Problem is finding the largest Kth item in Two Separated sorted Arrays
* Complexity O(log(N))
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
        private static int KElement(int[] A1, int s1, int e1, int[] A2, int s2, int e2, int k)
        {
            int mid1 = (e1 - s1) / 2;
            int mid2 = (e2 - s2) / 2;

            if (s1 == e1)
                return A2[s2 + k];
            if (s2 == e2)
                return A1[s1 + k];
            /*
             * Ex: 1 4 8 , 2 10 15 K = 2
             * Trying to neglect one half of the arrays 
             */
            else if (mid1 + mid2 < k)
            {
                /*
                 * if A1[s1 + mid1] > A2[s2 + mid2]
                 * So I am Sure I can neglect first half of second array
                 */
                if (A1[s1 + mid1] > A2[s2 + mid2])
                    return KElement(A1, s1, e1, A2, s2 + mid2 + 1, e2, k - mid2 - 1);
                /*
                 * if A1[s1 + mid1] <= A2[s2 + mid2]
                 * So I am Sure I can neglect first half of first array
                 */
                else if (A1[s1 + mid1] <= A2[s2 + mid2])
                    return KElement(A1, s1 + mid1 + 1, e1, A2, s2, e2, k - mid1 - 1);

            }
            else
            {
                if (A1[s1 + mid1] >= A2[s2 + mid2])
                    return KElement(A1, s1, s1 + mid1, A2, s2, e2, k);
                else if (A2[s2 + mid2] > A1[s1 + mid1])
                    return KElement(A1, s1, e1, A2, s2, s2 + mid2, k);

            }
            return 0;
        }
        public static int GetKthItem(int[] arr1, int[] arr2, int N, int M, int K)
        {

            /*
             * Find the Position of Element if the two arrays was merged
             * EX:
             * In A1: 1 5 6  A2: 7 8 10 k = 4
             * Fourth Largest Element is 6
             * It's Position is (3+3) - 4 = 2
             * And true it's the third Element with index 2
             * And this is the new k
             */
            int s = (N + M) - K;
            int res = KElement(arr1, 0, N, arr2, 0, M, s);
            return res;
        }
       
        static void Main(string[] args)
        {
            Console.WriteLine("Enter Size of First Array: ");
            int N;
            N = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter Size of Second Array: ");
            int M;
            M = int.Parse(Console.ReadLine());
            int[] A1 = new int[N];
            int[] A2 = new int[M];
            Console.WriteLine("Enter Elements of First Sorted Array: ");
            for (int i = 0; i < N; i++)
            {
                A1[i] = int.Parse(Console.ReadLine());
            }
            
            Console.WriteLine("Enter Elements of Second Sorted Array: ");
            for (int i = 0; i < M; i++)
            {
                A2[i] = int.Parse(Console.ReadLine());
            }
            Console.WriteLine("Enter the Kth Item: ");
            int k = int.Parse(Console.ReadLine());
            Console.WriteLine("The number is: " + GetKthItem(A1, A2, N, M, k)); ;
            /*
             * Ex: A1: 1 5 7
             *     A2: 2 6 10
             *     k = 3
             *     Output = 7
             *     Complexity O(Log(N))
            */
        }
    }
}
