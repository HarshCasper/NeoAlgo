/*In Highway Billboard Problem, the main task is to place billboards on the highway such that
revenue is maximized. The possible sites for billboards on the highway
are given by number pos1 < pos2 < ….. < posn-1 < posn, specifying positions in
miles measured from one end of the road to the other. If we place a billboard at
position pos[i], we receive a revenue of r[i] > 0. But we have a restriction here that
no two billboards can be placed within restricted mile number or less than that.*/

import java.util.Arrays;
import java.util.Scanner;

public class HighwayBillboardProblem {

    public int maxRevenue(int[] billboard, int[] revenue, int distance, int mileRestriction) {

        int[] maxRev = new int[distance + 1];
        int nextBillBoard = 0;
        mileRestriction = mileRestriction + 1;
        //Minimum distance can be between 2 billboards
        maxRev[0] = 0;

        for (int i = 1; i <= distance; i++) {
                //if statement for checking if billboards are not already placed
            if(nextBillBoard < billboard.length) {
                //Checking if billboard present for that mile
                if (billboard[nextBillBoard] != i) {
                    maxRev[i] = maxRev[i - 1];
                }
                else {
                /*If billboards are present for this mile then
                we either place the billboard or ignore it
                by chosing the optimal solution*/
                    if(i>=mileRestriction){
                        maxRev[i] = Math.max(maxRev[i - mileRestriction] + revenue[nextBillBoard], maxRev[i - 1]);
                    }else{
                /*There are no billboard placed prior to ith mile
                we will just place the billboard*/
                        maxRev[i] = revenue[nextBillBoard];
                    }
                    nextBillBoard++;
                }
            }
            else {
                //copying the previous optimal solution
                maxRev[i] = maxRev[i - 1];
            }
        }
        return maxRev[distance];
    }


    public static void main(String[] args) {
        //Taking Positions, Revenue, Distance, Mile Restriction as an input from the user
        Scanner sc = new Scanner(System.in);
        int n, distance, milesRestriction;
        System.out.print("Enter array size for number of billboard sites: ");
        n = sc.nextInt();
        int[] pos = new int[n];
        System.out.print("Enter positions in miles from one end to the other: ");
        for (int i = 0; i < n; i++){
            pos[i]= sc.nextInt();
        }
        int[] revenue = new int[n];
        System.out.print("Enter corresponding revenue generated for each position: ");
        for (int i = 0; i < n; i++){
            revenue[i]= sc.nextInt();
        }
        System.out.print("Enter Distance for which you want revenue for: ");
        distance = sc.nextInt();
        System.out.print("Enter mile restriction: ");
        milesRestriction = sc.nextInt();
        // Creating class object
        HighwayBillboardProblem h = new HighwayBillboardProblem();
        int result = h.maxRevenue(pos, revenue, distance, milesRestriction);
        System.out.println("Maximum revenue that can be generated is: " + result);
    }
}
/*Sample Input/Output:
  Input:
        Enter array size for number of billboard sites: 5
        Enter positions in miles from one end to the other: 2 6 13 16 17
        Enter corresponding revenue generated for each position: 6 7 6 4 2
        Enter Distance for which you want revenue for: 15
        Enter mile restriction: 7

  Output:
        Maximum revenue that can be generated is: 12

 Time and space complexity for this approach:
 Time Complexity: O(N), where N is distance of total Highway.
 Auxiliary Space: O(N)
 */

