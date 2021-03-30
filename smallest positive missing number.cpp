/*SMALLEST POSITIVE MISSING NUMBER:-*/
/*STEPS TO SOLVE:
1.BUILD THE Check[] ARRAY INITIALIZED WITH FALSE AT ALL INDICES..
2.BY ITERATING OVER AN ARRAY AND MARKING a[i] AS TRUE..
i.e.
if(a[i]>=0){
    check[a[i]]=TRUE;
}
3.ITERATE IN THE Check[] FROM i=1,BREAK THE LOOP WHEN YOU FIND check[i]=FALSE AND STORE THAT i A VARIABLE NAMED ans..
4.OUTPUT THE ans..
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
   //BUILD THE CHECK[] ARRAY INITIALIZED WITH FALSE AT ALL INDICES..
    const int N=1e6+2;//1000002
    bool check[N];
    for(int i=0;i<N;i++){
      check[i]=false;
    }
    //BY ITERATING OVER AN ARRAY AND MARKING a[i] AS TRUE..
    for(int i=0;i<n;i++){
      if(a[i]>=0){
        check[a[i]]=true;
      }
    }
	//ITERATE IN THE Check[] FROM i=1,BREAK THE LOOP WHEN YOU FIND check[i]=FALSE AND STORE THAT i A VARIABLE NAMED ans..
    int ans=-1;
    for(int i=1;i<N;i++){
      if(check[i]==false){
        ans=i;
        break;
      }
    }
	//OUTPUT THE ans..
    cout << ans << endl;
    return 0;
}

/*
I/O:-
Input:[0.-9,1,3,-4,5]
Output:2
*/

/*ANOTHER OPTIMAL SOLUTION:-*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int segArr (int arr[], int n) { 
    	int j = 0, i; 
    	for(i = 0; i < n; i++) { 
    	    if(arr[i] <= 0) { 
    	        //Changing the position of negative numbers and 0.
    	        swap(arr[i], arr[j]); 
    	        //Incrementing count of non-positive integers.
    	        j++; 
    		} 
    	}
    	return j; 
    } 
    
    //Finding the smallest positive missing number in an array that contains
    //all positive integers.
    int findMissingPositive(int arr[], int n) {
        
        //Marking arr[i] as visited by making arr[arr[i] - 1] negative. 
        //Note that 1 is subtracted because index starts from 0 and 
        //positive numbers start from 1.
        for(int i=0; i<n; i++) {
    	    if(abs(arr[i]) - 1 < n && arr[ abs(arr[i]) - 1] > 0) 
    	    arr[ abs(arr[i]) - 1] = -arr[ abs(arr[i]) - 1]; 
        } 
        for(int i=0; i<n; i++) 
            if (arr[i] > 0)
                //Returning the first index where value is positive. 
                // 1 is added because index starts from 0. 
    	        return i+1; 
    
        return n+1; 
    } 
    
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) { 
        // First separating positive and negative numbers. 
        int shift = segArr(arr, n); 
        //Shifting the array and calling function to find result in the positive part.
        //returning the result.
        return findMissingPositive(arr+shift, n-shift); 
    } 
};

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}  


/*
I/O:-
Input:[0.-9,1,3,-4,5]
Output:2

TIME COMPLEXITY:O(N)
SPACE COMPLEXITY:O(1)
*/










