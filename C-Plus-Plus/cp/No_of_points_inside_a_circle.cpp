/*You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. 
Multiple points can have the same coordinates.
You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) 
with a radius of rj.
For each query queries[j], compute the number of points inside the jth circle. Points on the border of the 
circle are considered inside.
Return an array answer, where answer[j] is the answer to the jth query.*/

#include<iostream>
#include <vector>
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
    vector<vector<int>>points{{1,3},{3,3},{5,3},{2,2}};
     
    vector<vector<int>>queries{{2,3,1},{4,3,1},{1,1,2}};
    countPoints(points, queries);
    
    return 0;

}