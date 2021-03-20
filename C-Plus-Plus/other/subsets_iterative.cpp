#include<bits/stdc++.h>

using namespace std;
void generate_subsets(int arr[], int n) {
    /*
    Number of possible subsets are 2^n
    If n=2, then:
    00 01 10 11 , four sets
    00 Indicates that both 0 and 1 index are not set hence empty
    01 Indicating that first index is unset and zeroth index is set
    */
    for (int i = 0; i < pow(2, n); i++) {
        //For checking set bits in the binary pattern and then printing the corresponding element
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    generate_subsets(arr, n);
}
/*
Input:
3
1 2 3 

Output:
1 
2 
1 2 
3 
1 3 
2 3 
1 2 3

Time complexity: O(2^n)
Space complexity: O(1)
*/
