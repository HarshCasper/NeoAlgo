/*Find the position of the only set bit
The main principle of this logic is one by one right shift the set bit of given number n until n becomes 0.
Count how many times we shifted to make n zero. So final count is position of set bit.*/

#include<bits/stdc++.h>
using namespace std;
int findPosition(int n){
    int count=0;
    int position=0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n=n>>1;   //Using right shift operator
        position++;
    }
    if(count == 1){
        return position;
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<findPosition(n)<<endl;
    return 0;
}
/*Time Complexity : O(log(N))
Space Complexity : O(1)

Sample Input
Example 1:
4
Example 2:
15
Sample Output
Example 1:
3      //4 is represented as "100" in Binary. As we see there's only one set bit and it's in Position 3 
Example 2:
-1     //15 is represented as "1111" in Binary. As we see there's four set bits and thus the Output -1
*/
