/* Given n non-negative integers representing an elevation map where the width of each bar is 1.
   Compute how much water it can trap after raining.

   Example:-
   Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
   Output: 6

   Explanation:-
   If we carefully observe using a block diagram, we see that:-
   1 unit of water is stored from index [1, 3] and [9, 11], Total=2.
   4 units of water is stored from index [3, 7], Total=6.
   Hence 6 units of rain water is being trapped.
*/

/* 
   Intution:- 
   # We will be using stacks to keep track of the bars that are bounded by longer bars and hence, may store water. 
   Using the stack, we can do the calculations in only one iteration.

   # We keep a stack and iterate over the array. We add the index of the bar to the stack if bar is smaller than or 
   equal to the bar at top of stack, which means that the current bar is bounded by the previous bar in the stack. 
   If we found a bar longer than that at the top, we are sure that the bar at the top of the stack is bounded by the 
   current bar and a previous bar in the stack, hence, we can pop it and add resulting trapped water to ans.
*/

// Code :-

#include <bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> &height)
{

    // ans is taken for calculating the total amount of water that can be stored.
    // current is a pointer that points to the current position of the vector.

    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size())
    {
        while (!st.empty() && height[current] > height[st.top()])
        {
            //While stack is not empty and height[current] > height[st.top()]

            int top = st.top(); //It means that the stack element can be popped. Pop the top element as top.
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1; //Find the distance between the current element and the element at top of stack, which is to be filled : distance=current−st.top()−1

            int bounded_height = min(height[current], height[st.top()]) - height[top]; // Find the bounded height : bounded_height=min(height[current],height[st.top()])−height[top]

            ans += distance * bounded_height; // Add resulting trapped water to answer : ans+=distance×bounded_height
        }
        st.push(current++); // Push current index to top of the stack and move current to the next position
    }
    return ans;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // Height of buildings
    cout << trappingRainWater(height);
    return 0;
}