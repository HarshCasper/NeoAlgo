#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        
        int result=0;
        int count=1;
        
        // Find a candidate key
        for(int i=1; i<size; i++) {
            if(a[result] == a[i])
                count++;
            else
                count--;
            
            if(count == 0) {
                result = i;
                count = 1;
            }
        }
        
        // Check if the candidate is actually a majority
        count=0;
        for(int i=0; i<size; i++)
            if(a[result] == a[i])
                count++;
        
        result = a[result];
        
        if(count <= size/2)
            result = -1;
        
        return result; 
    }
};

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
