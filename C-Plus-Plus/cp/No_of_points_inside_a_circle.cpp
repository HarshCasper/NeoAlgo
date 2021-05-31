/*You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. 
Multiple points can have the same coordinates.
You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) 
with a radius of rj.
For each query queries[j], compute the number of points inside the jth circle. Points on the border of the 
circle are considered inside.
Return an array answer, where answer[j] is the answer to the jth query.*/

#include<bits/stdc++>
using namespace std;

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
	vector<int> ans(queries.size());
	for(int i = 0; i < queries.size(); i++){
		
        int x = queries[i][0], y = queries[i][1], r = queries[i][2];
	
        for(int j = 0; j < points.size(); j++){
		if((x-points[j][0])*(x-points[j][0])+(y-points[j][1])*(y-points[j][1]) <= r * r)    
				ans[i]++;
		}
        cout<<ans[i]<<" ";            
	}
	return ans;
}
int main(){
    vector<vector<int>>points;
    vector<vector<int>>queries;
    int n;
    cout<<"Enter the no of Points: ";
    cin>>n;
    for(int i = 0; i<=n; i++){                        //TO get the input from the user for the points in cartesian plane
        vector<int> row;
        for(int j = 0; j<2; j++){
            cin>>n;
            row.push_back(n);
        }
        points.push_back(row);
    }
    cout<<endl<<"Enter the no of Queries: ";
    cin>>n;
    for(int i = 0; i<=n; i++){                      //To get the input from the user for the coordinates of a circle in cartesian plane.
        vector<int> row;
        for(int j = 0; j<3; j++){
            cin>>n;
            row.push_back(n);
        }
        queries.push_back(row);
    }
    cout<<"For each query queries, the number of points that are inside the circle are: ";
    countPoints(points, queries);

    
    return 0;

}

/*Sample Input 

Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: For first Query there are 3 points that are inside the circle.
For 2nd there are 2 points and for 3rd Query there are 2 points that lie inside the circle {query[3]}.

*/


/*
Time Complexity : O(N*Q), where N is the number of points and Q is the number of queries.
Space Complexity: O(Q), Required to store the ans array. 
*/