// Given a sorted array,remove the duplicates such that each element appears only once and return the new length using two pointers.

// Function removeDuplicates returns modified size of vector which is passed in this function initially.
class solution{

int removeDuplicates(vector<int> &nums) {
    //base case
	if(nums.empty()){
	    return 0;
	}
	// initializing 2 pointers
	int p1=0;
	int p2=1;
	//main logic
	while(p2<nums.size()){
	    if(nums[p2]==nums[p1]){
	        p2++;
	        continue;
	    }
	    else{
	        std::swap(nums[++p1],nums[p2++]);
	    }
	}
nums.erase(nums.begin()+p1+1,nums.end());
return nums.size();
}
};
/*Time Complexity: O(n)
Space Complexity: O(1)
Sample input & output
sample 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2]
sample 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
output: 5, nums = [0,1,2,3,4]
*/