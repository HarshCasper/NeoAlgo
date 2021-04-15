/*
 Given an array of integers nums. A pair (i,j) is called good if nums[i] == nums[j] and i < j.
 Return the number of good pairs.

 Approach - Use a Hash Table to calculate the frequency of each element in the given array.
 count the number of pairs using the formula y(y-1)/2; where y is the frequency for the element.
*/


// Program 
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int ,int> umap; // creating an unordered map
        for(int i = 0;i<n;i++)
        {
            umap[nums[i]]++; // storing frequency of each element
        }
        int ans = 0;
        for(auto i:umap)
        {
            int y = i.second;
            ans = ans + (y * (y-1)) / 2; //count the number of pairs and add to answer.
        }
        return ans; // returing final answer
    }
/*

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

*/
