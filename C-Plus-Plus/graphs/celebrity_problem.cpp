// C++ program to solve the Celebrity Problem
#include <bits/stdc++.h> 
using namespace std; 


int find_celebrity(int person[][9000], int n) {
    int low = 0;
    int high = n - 1;
    while(1) {
        if (low == high) 
            break;
        
        if (person[low][high] == 1) 
            low++;
        
        else 
            high--;
    }
    for (int i = 0; i < n; i++) {
        if (low == i) 
            continue;
        
        if (person[low][i] == 1 or person[i][low] == 0) 
            return -1;   
    }
    return low;
}


int main() {
    int n;
    cout<<"How many person are present in the party? ";
    cin >> n;
    int person[n][9000];
    cout<<"Enter thier co-relation graph: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> person[i][j];
        }
    }
    int celeb = find_celebrity(person, n);
    if (celeb >= 0) {
        cout<<"Celebrity is present at the "<<celeb<<"th index of the given co-relation graph";
    }
    else {
        cout<<"Celebrity is not present in the party.";
    }
}

/*

Time Complexity: O(n)
Space Complexity: O(n^2)

SAMPLE INPUT AND OUTPUT

How many person are present in the party? 3
Enter thier co-relation graph: 0 1 0 0 1 1 1 0 1
Celebrity is not present in the party.

*/
