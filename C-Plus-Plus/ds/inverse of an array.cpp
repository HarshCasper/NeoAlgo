
    //INVERSE OF AN ARRAY

    /*If the array elements are swapped with their corresponding indices,
      the array finally results is inverse of the array.
    */

    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    int n;
    cin>>n;
    int arr[n];     //created an array of size n
    int inv[n];     //created an inv array of size n

    for(int i =0 ; i<n; i++){
        cin>>arr[i];            //putting values in array
    }
     for(int i =0 ; i<n; i++){
            int j = arr[i];     //j is temporary variable
            inv[j] = i;         //after storing values of array in j
                                //at inverse array we store corresponding indices of array arr[].
    }

    for(int i =0 ; i<n; i++){
        cout<<inv[i]<<" ";      //output the inverse array
    }

    return 0;
    }


    /* Sample input:
     5
    4 0 2 3 1

    Sample Output
    1 4 2 3 0




    Sample input
    3
    0 1 2

    Sample Output
    0 1 2
    */

