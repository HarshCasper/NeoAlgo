/* example 1
set[] = {3, 34, 4, 12, 5, 2}, sum = 9

example 2
set[] = {3, 34, 4, 12, 5, 2}, sum = 30
*/
#include<bits/stdc++.h>
using namespace std;

//returns true if there is a subset of set[] with sum equal to given sum
bool isSubsetSum(int set[],int n,int sum){
    bool subset[n+1][sum+1];
    
   
    for(int i=0;i<=n;i++)
        subset[i][0]=true;
  
    for(int i=1;i<=sum;i++)
        subset[0][i]=false;
    //fill this table in bottom up manner
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++){
            if(j<set[i-1])
                subset[i][j]=subset[i-1][j];
            if(j>=set[i-1])
                subset[i][j]=subset[i-1][j]||subset[i-1][j-set[i-1]];

        }
    }
    }
}
int main(){
    int set[]={3,34,4,12,5,2};
    int sum=9;
    int n=sizeof(set)/sizeof(set[0]);
    if(isSubsetSum(set,n,sum)==true)
        cout<<"found a subset with given sum";
    else
        cout<<"no subset with given sum";
    return 0;
}
/*
Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.*/
