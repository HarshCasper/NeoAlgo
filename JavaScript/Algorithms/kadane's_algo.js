
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    for(let i=0;i<t;i++)
    {
        let input_line = readLine().split(' ');
        let N = parseInt(input_line[0]);
        input_line = readLine().split(' ').map(x=>parseInt(x));
        let arr = new Array(N);
        for(let i=0;i<N;i++){
            arr[i]=input_line[i];
        }
        let obj = new Solution();
        let ans = obj.kadanesalgo(arr, N);
        if(ans==-0)
            ans=0;
        console.log(ans);
    }
}



class Solution {
    
    kadanesalgo(arr, N){
        let maxh = 0, maxf = arr[0];
        

        for(let i=0;i<N;i++) 
        {
            //Updating max sum till current index.
            maxh+=arr[i];
            //Storing max sum so far by choosing maximum between max 
            //sum so far and max sum till current index.
            maxf=Math.max(maxh,maxf);
            
            //If max sum till current index is negative, we do not need to add
            //it to result so we update it to zero.
            if(maxh<0)
                maxh=0;
        }
         //returning the result.
        return maxf;
    } 
}
// solved example
// Input:
// N = 4
// arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)

  
