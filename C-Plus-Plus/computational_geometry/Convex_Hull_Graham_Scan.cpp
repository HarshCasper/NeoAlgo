/* A convex Hull is a polygon with vertices such that all the points in the plane are
   contained inside of the polygon.
    GrahamScan algorithm gives us the convex hull for the given points by focusing on the following:

   -> It pushes each point of the input set onto the stack one time,
       and then pops from the stack each point which is not a vertex.
    -> When, the function finishes stack contains exactly the vertices of
       all the convex hull in counterclock wise direction from their appearance
       of the boundary.
*/






#include <iostream> 
#include<algorithm>
#include<vector>
#include<stack>
#include<cmath>
#define e 1e-10
#define x first
#define y second

using namespace std;

typedef struct point      //structure for the coordinates
{
   double x,y;           // comparison is done first on y coordinate and then on x coordinate.
} 
point;

vector <point>plane;

stack<point> hull;

double area(point a, point b, point c)
{
    return (a.x - b.x) * (b.y - c.y) - (a.y - b.y) * (b.x - c.x);

}
double dis(point a, point b)          //returns euclidean distance between two points.
{
    return sqrt((a.x = b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp(point a, point b)           // for comparing points based on their orientation.
{
    if (area(plane[0], a, b) < -e){
    return 0;
    }
    if (area(plane[0], a, b) > e){
        return 1;
    }
    return dis(a, plane[0]) < dis(b, plane[0]);

}

int main()

{
   cout<<"enter the desired number of points\n";
    int n;                         // the number of coordinates to be entered
    point tmp;
    cin >> n;
    cout<<"enter the points\n";
    plane.resize(n);
    for (int i = 0; i < n; i++)    //entering the desired points for determining the convex hull
    {

        cin >> plane[i].x >> plane[i].y;
        if (i) {
            if (plane[i].x < plane[0].x)
                swap(plane[i], plane[0]);
        }
    }
    sort(plane.begin() + 1, plane.end(), cmp);
    hull.push(plane[0]);
    hull.push(plane[1]);
    for (int i = 2; i < n; i++) {
        tmp = hull.top();
        hull.pop();
        while (hull.size() && area(plane[i], tmp, hull.top()) > -e) {
            tmp = hull.top();
            hull.pop();
        }
        hull.push(tmp);
        hull.push(plane[i]);

    }
    cout<<"\n The following vertices form the convex hull:\n";
    while (!hull.empty()) {
        cout << hull.top().x << " , " << hull.top().y << endl;
        hull.pop();
}    }



/*Time Complexity: O(nLogn), if total points = n*/
/*Worst case time complexity: Θ(N log N)
Average case time complexity: Θ(N log N)
Best case time complexity: Θ(N log N)
Space complexity: Θ(N)*/


/* Test Case 1:
Sample Input :
enter the desired number of points
8
enter the points
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3

Sample Output :

The following vertices form the convex hull:
4,4
3,1
0,0
0,3
*/
