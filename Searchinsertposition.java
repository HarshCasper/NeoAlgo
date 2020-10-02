public int searchInsert(int[] nums, int target) {
    int i=0; 
    int j=nums.length-1;
 
    while(i<=j){
        int mid = (i+j)/2;
 
        if(target > nums[mid]){
            i=mid+1;
        }else if(target < nums[mid]){
            j=mid-1;
        }else{
            return mid;
        }
    }
 
    return i;
}
