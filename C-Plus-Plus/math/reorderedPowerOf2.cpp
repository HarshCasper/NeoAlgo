/* Problem Statement:
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.
The task is to return true if and only if we can do this in a way such that the resulting number is a power of 2.

Constraints:
1 <= N <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

bool reorderedPowerOf2(int N) {
    string num = to_string(N);
    int n = num.size();
    int base = 1, x = 1;
    unordered_map<int, vector<int>> powers2; //size of string, powers of 2 of that length

    while(x <= n) {
        powers2[x].push_back(base);
        base *= 2;
        x = to_string(base).size();
    }

    vector<int> countDigits(10, 0); //stores freq of digits of string num
    for(int i = 0; i < n; i++) {
        countDigits[num[i] - '0']++;
    }

    for(auto power : powers2[n]) {
        string x = to_string(power);
        int nx = x.size();
        vector<int> countDigitsx (10, 0);
        for(int i = 0; i < nx; i++) {
            countDigitsx[x[i] - '0']++;
        }

        bool f = 1;
        for(int i = 0; i < 10; i++) {
            if(countDigitsx[i] != countDigits[i]){
                f = 0;
                break;
            }
        }
        if(f == 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    reorderedPowerOf2(n) == 1 ? cout << "true" : cout << "false";
    return 0;
}

/*Examples:
1.  Input: 10
    Output : false
2.  Input: 46
    Output: true
*/
