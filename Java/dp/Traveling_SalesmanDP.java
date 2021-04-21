/*
Travelling Salesman Problem states-

A salesman has to visit every city exactly once.
He has to come back to the city from where he starts his journey.

We need to find-
What is the shortest possible route that the salesman must follow to complete his tour?

 */
import java.util.*;
import java.lang.*;

//Travelling Salesman Problem using Dynamic programming
public class Traveling_SalesmanDP {

    public static void main(String[] args)

    {

        Scanner in = new Scanner(System.in);

        /*
        initially we are declaring a 2d Array c for storing
        input from the user.
        tour array will consist numbers of city
        For example if no. of cites are 4 then
        tour = [1,2,3,4]
         */
        int c[][]=new int[10][10], tour[]=new int[10];

        int i, j,cost;

        System.out.println("");

        // taking no. of cities input from user
        System.out.print("Enter No. of Cities: ");

        int n = in.nextInt();

        //checking out if whether user has enter valid
        //no. of cities
        if(n==1)

        {
            System.out.println("");

            //if no. of cities is one
            System.out.println("Path is not possible!");

            System.exit(0);

        }

        System.out.println("");
        System.out.println("Enter the Cost Matrix:");

        /*
        user input(Cost Matrix)

        For example-

        if no. of cities is equal to 4

            4 8 6 3
            4 3 2 7
            1 2 3 0
            1 6 1 7

         */
        for(i=1;i<=n;i++)

            for(j=1;j<=n;j++)

                c[i][j] = in.nextInt();

        for(i=1;i<=n;i++)

            tour[i]=i;

        //calling tspdp
        cost = tspdp(c, tour, 1, n);

        System.out.println("");

        //printing out the path(min cost)
        System.out.print("The Optimal Tour is: ");

        for(i=1;i<=n;i++)

            System.out.print(tour[i]+"->");

        System.out.println("1");

        System.out.println("");

        //cost of the optimal path
        System.out.println("Minimum Cost: "+cost);

    }

    static int tspdp(int c[][], int tour[], int start, int n)

    {

        /*
        for eg. Cost Matrix- 4 8 6 3
                             4 3 2 7
                             1 2 3 0
                             1 6 1 7
        here n=4
         */

        int mintour[]=new int[10], temp[]=new int[10], mincost=999,ccost, i, j, k;

        if(start == n-1)

        {

            // c[3][4] + c[4][1]
            return (c[tour[n-1]][tour[n]] + c[tour[n]][1]);

        }

        for(i=start+1; i<=n; i++)

        {

            for(j=1; j<=n; j++)

                temp[j] = tour[j];

            temp[start+1] = tour[i];

            temp[i] = tour[start+1];

            /*
                c[1][2] + Recursive call

                          c[2][3] + Recursive call

                                    start == n-1 (start=3)
                                    (returns c[3][4] + c[4][1])
             */

            /*
                (c[1][2] + c[2][3] + c[3][4] + c[4][1]) < 999
             */
            if((c[tour[start]][tour[i]]+(ccost=tspdp(c,temp,start+1,n)))<mincost)

            {

                mincost = c[tour[start]][tour[i]] + ccost;

                for(k=1; k<=n; k++)

                    mintour[k] = temp[k];

            }

        }

        for(i=1; i<=n; i++)

            tour[i] = mintour[i];

        //returning the minimum cost
        return mincost;

    }
}

/*

Sample I/O:

Enter No. of Cities: 4

Enter the Cost Matrix:
4 8 6 3
4 3 2 7
1 2 3 0
1 6 1 7

The Optimal Tour is: 1->4->3->2->1

Minimum Cost: 10

Time Complexity: O(2^n*n^2)

Space Complexity: O(2^n)

(here n is no. of nodes in the graph(creating graph
to find optimal path))

 */
