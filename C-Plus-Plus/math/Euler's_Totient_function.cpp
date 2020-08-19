// Euler's Totient Function represented by M(n)
// For integer n it calculates the no. of coprimes
// of n from 1 to n. Do refer line 18 for 
// better grasp of question
#include <bits/stdc++.h>
using namespace std;
int F(int n){
    if(n<=0) return 0;             // we are calculating coprime from 1 to n
    int arr[n+1],i,j; 
    for(i=0;i<=n;i++){
        arr[i]=i;
    }
    for(i=2;i<=n;i++){
        if(arr[i]==i){             // checking if arr[i] has been untouched or not
            for(j=i;j<=n;j+=i){
                arr[j]-=arr[j]/i;   // here we are removing no. of coprime of j integer
            }
        }
    }
    // till now arr[i] shows no. of coprimes of n from 0 to n
    // Let us represent Euler's Totient Function by M(n) where n is an integer
    // M(n) denotes the number of coprimes of n from 1 to n
    // so till now M(n)=arr[n] i.e. we have created Euler's Totient Function Array
    // Now we have to calculate the no. of coprime pairs between 0 and n
    for(i=2;i<=n;i++){
        arr[i]+=arr[i-1]; // applying dp to calculate no. of coprime 
    }                     // between 1 and n (both 1 and n inclusive)
    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<F(n)<<endl;
    return 0;        
}
/*                      
             Sample Input  3
             Sample Output 4
             Explanation: Coprime pairs between 1 and 4
                          {(1,1),(1,2),(1,3),(2,3)}
                          
             Sample Input  4 
             Sample Output 6
             Explanation: Coprime pairs between 0 and 4
                          {(1,1),(1,2),(1,3),(2,3),(1,4),(3,4)}
             As you can see from second sample case that for integer 4 we have to 
             add only coprime pairs which include 4 as one integer to the result of 
             first sample case. This is the concept of Dynamic Programming
*/
