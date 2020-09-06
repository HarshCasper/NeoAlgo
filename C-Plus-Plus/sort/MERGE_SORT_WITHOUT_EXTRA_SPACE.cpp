#include<bits/stdc++.h>
using namespace std;
int main() {
   
        int m, n;
cout<<"enter totle no.of elements\n";
        cin>>m>>n;
       
        int arr1[m], arr2[n];
cout<<"enter 1st array elements\n";
        for(int i=0; i<m; i++){
            cin>>arr1[i];
        }
cout<<"enter 2nd array elements\n";
        for(int i=0; i<n; i++){
            cin>>arr2[i];
        }
        
        for(int i=m-1, j=0; i>=0&&j<n; i--,j++){
            int temp;
            if(arr1[i] > arr2[j]){
                temp = arr1[i];
                arr1[i] = arr2[j];
                arr2[j] = temp;
            }
        }
        sort(arr1, arr1+m);
        sort(arr2, arr2+n);
cout<<"answer: ";
        for(int i=0; i<m; i++){
            cout<<arr1[i]<<" ";
        }
        for(int i=0; i<n; i++){
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
    
    
	return 0;
}

/*

Sample output:
enter totle no.of elements
3 4
enter 1st array elements
2 4 6
enter 2nd array elements
1 3 5 7
answer: 1 2 3 4 5 6 7

*/
