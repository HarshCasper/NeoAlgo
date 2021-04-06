var kadanesalgo=function(arr, N){
    let maxh = 0, maxf = arr[0];
    
    for(let i=0;i<N;i++) 
    {
        maxh+=arr[i];
        //Storing max sum so far by choosing maximum between max 
        //sum so far and max sum till current index.
        maxf=Math.max(maxh,maxf);
        
        //If max sum till current index is negative, we do not need to add
        //it to result so we update it to zero.
        if(maxh<0)
            maxh=0;
    }
 
    return maxf;
} 
  
/* solved example
Input:
N = 4
arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1 
of element (-1)
*/
  
