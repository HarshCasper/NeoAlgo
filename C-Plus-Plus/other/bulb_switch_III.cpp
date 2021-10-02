/*

Problem: Bulb Switcher - III

There is a room with n bulbs, numbered from 1 to n, arranged 
in a row from left to right. Initially, all the bulbs are turned off.

At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. 
A bulb changes color to blue only if it is on and all the previous 
bulbs (to the left) are turned on too.

Return the number of moments in which all turned-on bulbs are blue.

*/

// Code
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0,pos = 0;
        for(int i = 0; i < light.size(); i++){
            pos = max(pos, light[i]);
            if(pos == i + 1) 
                ans++;
        }
        return ans;
    }
};

/*

Input: light = [4,1,2,3]
Output: 1
Explanation: All bulbs turned on, are blue at the moment 3 (index-0).
Bulb 4th changes to blue at the moment 3.

*/