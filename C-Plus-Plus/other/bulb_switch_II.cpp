/*

Problem: Bulb Switcher - II

There is a room with n bulbs labeled from 1 to n that all 
are turned on initially, and four buttons on the wall. Each 
of the four buttons has a different functionality where:

Button 1: Flips the status of all the bulbs.
Button 2: Flips the status of all the bulbs with even labels (i.e., 2, 4, ...).
Button 3: Flips the status of all the bulbs with odd labels (i.e., 1, 3, ...).
Button 4: Flips the status of all the bulbs with a label j = 3k + 1 where k = 0, 1, 2, ... (i.e., 1, 4, 7, 10, ...).
You must make exactly presses button presses in total. For each press, you may pick any of the four buttons to press.

Given the two integers n and presses, return the number of different possible 
statuses after performing all presses button presses.

*/

// Code
class Solution {
public:
    int flipLights(int n, int p) {
        if(p == 0) return 1;
        if(n == 1) return 2;
        if(n == 2) return p == 1 ? 3 : 4;
        else return p == 1 ? 4 : p == 2 ? 7 : 8;
    }
};

/*

Input: n = 2, presses = 1
Output: 3
Explanation: Status can be:
- [off, off] by pressing button 1
- [on, off] by pressing button 2
- [off, on] by pressing button 3

*/