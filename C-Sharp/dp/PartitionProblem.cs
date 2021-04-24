/*
 * The Problem is deciding whether a given multiset S of positive integers can be partitioned
   into two subsets S1 and S2 such that the sum of the numbers in S1 equals the sum of the numbers in S2.
 * Complexity O(N^2)
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
        public static bool NumberPartitiong(int[] numbers, int N)
        {       
            int Sum = 0;
            bool flag = false;       
            int[,] numbers2 = new int[N + 1, N + 1];
            /*
            * Calculate the sum of all elements in the array
            * Saving every elemebt in first row and column in the new matrix
            */
            for (int i = 1; i <= N; i++)
            {
                Sum += numbers[i - 1];              
                numbers2[i, 0] = numbers[i - 1];
                numbers2[0, i] = numbers[i - 1];
            }
            int Sum2 = Sum / 2;
            int Subset = 0;
            for (int i = 1; i <= N; i++)
            {
                for (int j = i + 1; j <= N; j++)
                {
                    /*
                     * Adding numbers to matrix that equals to sum / 2 or if (sum / 2) + 1 in case sum is odd 
                     */
                    if (Sum % 2 != 0 && (numbers2[i, j - 1] + numbers2[0, j] > Sum2 || numbers2[i, j - 1] + numbers2[0, j] > Sum2 + 1) || j == 1)
                        numbers2[i, j] = numbers2[i, 0] + numbers2[0, j];
                    else if (Sum % 2 == 0 && numbers2[i, j - 1] + numbers2[0, j] > Sum2 || j == 1)
                        numbers2[i, j] = numbers2[i, 0] + numbers2[0, j];
                    else
                        numbers2[i, j] = numbers2[i, j - 1] + numbers2[0, j];

                    /*
                     * if Element in matrix = sum / 2 so Add 1 to subset
                     * if subset = 2 so we have reached our Goal
                     */
                    if (Sum % 2 != 0 && (numbers2[i, j] == Sum2 + 1 || numbers2[i, j] == Sum2))
                    {
                        Subset++;
                    }
                    else if (Sum % 2 == 0 && numbers2[i, j] == Sum2)
                    {
                        Subset++;
                    }

                }
                if (Subset == 2)
                {
                    flag = true;
                    break;
                }
            }
            return flag;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Enter No. of Vertices: ");
            int N = int.Parse(Console.ReadLine());           
            int[] numbers = new int[N];
            for (int i = 0; i < N; i++)
            {
                numbers[i] = int.Parse(Console.ReadLine());
            }
            Console.WriteLine(NumberPartitiong(numbers, N)); ;
            /*
             * Input: N = 5
             * numbers: 5 6 4 2 3 1
             * Sum = 21
             * S1: [5, 2, 3] S2: [6, 4, 1]
             * OutPut = True
             */
        }
    }
}
