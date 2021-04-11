 
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inpStr = '';
let curr = 0;

process.stdin.on('data', inputStdin => {
    inpStr += inputStdin;
});

process.stdin.on('end', _ => {
    inpStr = inpStr.trim().split('\n').map(string => {
        return string.trim();
    });
    
    master();    
});

function lineread() {
    return inpStr[curr++];
}

function master() {
    console.log("INPUT TEST CASES");
    let t = parseInt(lineread());
    for(let i=0;i<t;i++)
    {   
        console.log("INPUT NUMBER OF ELEMENTS");
        let line = lineread().split(' ');
        let ele = parseInt(line[0]);
        line = lineread().split(' ').map(x=>parseInt(x));
        console.log("INPUT ARRAY ELEMENTS");
        let a = new Array(ele);
        for(let k=0;k<ele;k++){
            a[k]=line[k];
        }
        let Ob = new Kadanes();
        let sol = Ob.kadanesalgo(a,ele);
        console.log("MAX SUM OF SUBARRAY IS : ");
        if(sol===0)
            sol=0;
        console.log(sol);
    }
    
}



class Kadanes {
    
    kadanesalgo(a,ele){
        let mh = 0, mf = a[0];
        for(let p=0;p<ele;p++) 
        {
            mh+=a[p];
            mf=Math.max(mh,mf);
            if(mh<0)
                mh=0;
        }
        return mf;
    } 
}

// solved example
// Input:
// INPUT TEST CASES = 1
//INPUT NUMBER OF ELEMENTS = 4
// INPUT ARRAY ELEMENTS = -1 -2 -3 -4
// Output:
//  MAX SUM OF SUBARRAY IS : -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)

// Time Complexity: O(N)
// Auxiliary Space: O(1)
