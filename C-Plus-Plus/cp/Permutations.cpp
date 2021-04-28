//A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.
//Print a beautiful permutation of integers 1,2,…,n.
// If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".

/*Sample Input
Example 1:
5
Example 2:
2

Sample Output
Example 1:
4 2 5 1 3
Example 2:
NO SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
    }
    if(n==2 || n==3){
        cout<<"NO SOLUTION"<<endl;
    }
    if(n%2==0){           
        for(int i=2;i<=n;i+=2){          
            cout<<i<<" ";                   
        }
        for(int i=1;i<=n;i+=2){            
            cout<<i<<" ";    
        }
    }
    else{
        for(int i=n-1;i>0;i-=2){          
            cout<<i<<" ";              
        }
        for(int i=n;i>0;i-=2){        
            cout<<i<<" ";      
        }
    }
    
    return 0;
}