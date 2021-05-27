/* This Program is to check the Orientation of three given points on a 2-D plane
     i.e, a) Counter-Clockwise
          b) Clockwise
          c) Collinear
 Based on the slope, we can categorize the orientation of the three points.
 If the slope of line segment (a,b)> slope of line segment (b,c), then the orientation is clockwise or right turn
 and vice versa for counter - clockwise or left turn.
 When the three points are collinear, the slope of both the lines are equal
 */

#include <bits/stdc++.h>
using namespace std;

/*returns 1 if  rotation is counter - clockwise
 returns 0 if  rotation is collinear
 returns -1 if rotation is clockwise*/
int CheckOrientation(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int slope = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
    if (slope > 1e-10)
    {
        return -1;
    }
    if (slope == 0)
    {
        return 0;
    }

    if (slope < -1e-10)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    //To input the desired values.
    cout << "Input the desired values for point a, point b, point c to check their Orientation \n";
    cout << "Input x and y values for point a" << endl;
    cin >> x1 >> y1;
    cout << "Input x and y values for point b" << endl;
    cin >> x2 >> y2;
    cout << "Input x and y values for point c." << endl;
    cin >> x3 >> y3;

    //calling the function for checking the Orientation.
    int result = CheckOrientation(x1, y1, x2, y2, x3, y3);
    if (result > 0)
    {
        cout << "Orientation : Counter-Clockwise." << endl;
    }

    if (result == 0)
    {
        cout << "Orientation :  Collinear." << endl;
    }
    if (result < 0)
    {
        cout << "Orientation : Clockwise." << endl;
    }

    return 0;
}

/* Time Complexity : O(1)
   Since there are no loops , time complexity is constant 
*/

/* Test Case 1:
Sample Input :Input the desired values for point a, point b, point c to check their Orientation
                Input x and y values for point a
                0 0
                Input x and y values for point b
                4 4
                Input x and y values for point c
                1 1
 Sample Output : Orientation : Collinear 
 */

