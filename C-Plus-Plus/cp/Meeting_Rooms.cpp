/*
given the starting and the end time of few meeting to be held. our goal is to find the minimum number of meeting rooms required to conducy all the meetings successfully.
in brief we have to find the maximum number of meetings being help simultaneously.
*/
#include<bits/stdc++.h>
using namespace std;

class meetings{
public://access specifier since all the members of a class are by default private
int meetingrooms(vector<vector<int>>& intervals)
{
  //we'll be considering the start and the end times of all the meetings.
  vector<int> start_time,end_time;
 for(auto vec: intervals)
 {
   start_time.push_back(vec[0]);
   end_time.push_back(vec[1]);
 }
 sort(start_time.begin(),start_time.end());
 sort(end_time.begin(),end_time.end());

 int start=0, end=0;
 int parallel=0;
 int max_parallel=0;

 for(auto i=0;i<intervals.size();i++)
 {
   if(start_time[start]>=end_time[end])
   {
     parallel--;
     end++;
   }
   parallel++;
   start++;

   max_parallel=max(max_parallel,parallel);
 }
 return max_parallel;
 cout<<"\n";
}

};

/*
 Time Complexity : O(N)
 Space Complexity : O(N)
*/
/*
input1:
[[0,30],[5,10],[15,20]]
output1 : 2

input2: [[7,10],[2,4]]
output2: 1

*/