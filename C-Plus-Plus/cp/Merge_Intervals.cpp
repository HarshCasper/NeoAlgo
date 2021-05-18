/*
  Given a 2D vector of intervals where intervals[i]={start_time,end_time} ,
  merge all the overlapping intervals and
  return the array of non-overlapping intervals that cover all the intervals in the input.
*/


#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> merge_interval(vector<vector<int>> interval);

int main()
{
    //number of intervals
    int n;
    cin>>n;

    // input 2D vector
    vector<vector<int>> intervals;

    //taking data from user
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        intervals.push_back({x,y});
    }

    vector<vector<int>> result;

    //calling function merge_interval
   result = merge_interval(intervals);

   //displaying output
   for(int i=0;i<result.size();i++)
   {
       cout<<result[i][0]<<","<<result[i][1];
       cout<<endl;
   }

    return 0;
}

vector<vector<int>> merge_interval(vector<vector<int>> interval)
{
    if(interval.size()==0)
        return interval;

    //sorting the vector in ascending order
    sort(interval.begin(),interval.end());

    //for result to store
    vector<vector<int>> merged;

    vector<int> temp = interval[0];

    for(int i=0;i<interval.size();i++)
    {
        //interval[i](start_time) is less than temp(end_time)
        //then it is merged
        if(interval[i][0] <= temp[1])
        {
            if(interval[i][1] >= temp[1])
            temp[1] = interval[i][1];
        }
        //interval[i](start_time) is greater than temp(end_time)
        else
        {
            merged.push_back(temp);
            temp = interval[i];
        }

    }
     //last interval
    merged.push_back(temp);

    return merged;
}


/*
   Time Complexity: O(NlogN) + O(N) ...N is the number of intervals
                    (sorting)  (traversing)
   Space Complexity:O(N)
*/

/*   Examples:

   1)Input:
     3   ...N
     2 4
     3 8
     10 12

    Output:
     2,8
     10,12

*/
