/* Given an array of integers, find anyone combination of four elements in the array whose sum is equal to a given value X. 
   Here most optimized solution is discussed using the concept of hashing.Below is a hashing based  CPP program to find if there are four elements with given sum. */

#include<bits/stdc++.h>
using namespace std;

/* Function to find combination of 4 elements that sum to given sum */
void findFourElements(int a[],int n,int sum)
{
	/*Store sums of all pairs 
	   in a hash table */
	unordered_map<int,pair<int,int> >ump;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
		 ump[a[i]+a[j]]={i,j};
	}
		 
	/* Traverse through all pairs and search
       for X - (current pair sum) */
    for(int i=0;i<n-1;i++){
    	for(int j=i+1;j<n;j++){
    		int X=a[i]+a[j];
    		
            /* If X - sum is present in hash table */
             if(ump.find(sum-X)!=ump.end()){
             	/* Making sure that all elements are
                   distinct array elements and an element
                   is not considered more than once */
                pair<int,int>p=ump[sum-X];
                if(p.first!=i&&p.first!=j
				   && p.second !=i && p.second!=j){
				   	cout<<a[i]<< ","<<a[j]<< ","
				   	<<a[p.first]<< "," <<a[p.second];
				   	return ;
				   }
			 }
		}
	}
}


int main(){
	int n;
	cin>>n;
	int sum;
	cin>>sum;
	int a[n];
	for(int i=0;i<n;i++)
	  cin>>a[i];
	findFourElements(a,n,sum);
	return 0;
}

/*
   Time Complexity: O(n)
   Auxilary Space Complexity: O(n)
   
   Input: n=6 
          sum=91
          a[n]={10 ,20 ,30 ,40 ,1 ,2}
   Output: 20, 30, 40, 1
*/
   
