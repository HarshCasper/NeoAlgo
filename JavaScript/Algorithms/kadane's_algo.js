class Solution {
    
    kadanesalgo(arr){
        let maxh = 0, maxf = arr[0];
        let N=arr.length;     

        for(let i=0;i<N;i++) 
        {
            maxh+=arr[i];
            //Storing max sum so far by choosing maximum between max 
            //sum so far and max sum till current index.
            maxf=Math.max(maxh,maxf);
           
            if(maxh<0)
                maxh=0;
        }

        return maxf;
    } 
}


var arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
let obj = new Solution();
let ans = obj.kadanesalgo(arr);
if(ans===0)
    ans=0;
console.log(ans);
// solved example
// Input:
// N = 4
// arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)

  
