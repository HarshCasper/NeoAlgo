#include <iostream>
#include <vector>
using std::vector;
int minimum_cuts(int a, int b, vector<vector<int> > &mem) {
    int minimum = mem[a][b];
    if (minimum > 0)
        return minimum;
    if (a%b==0)
        minimum= a/b-1;
    else if (b%a==0)
        minimum= b/a -1;
    else {
        for (int i=1; i<a; i++) {
            int m = minimum_cuts(i,b, mem);
            int n = minimum_cuts(a-i, b, mem);
            if (minimum<0 or m+n+1<minimum)
                minimum = m + n + 1;
        }
        for (int j=1; j<b; j++) {
            int m = minimum_cuts(a,j, mem);
            int n = minimum_cuts(a, b-j, mem);
            if (minimum<0 or m+n+1<minimum)
                minimum = m + n + 1;
        }
    }
    mem[a][b] = minimum;
    return minimum;
}
int main() {
    int a, b; std::cin >> a >> b;
    vector<vector<int> > mem(a+1, vector<int>(b+1, -1));
    int res = minimum_cuts(a,b,mem);
    std::cout << res << std::endl;
    return 0;
}
//
//sample input : 3 5 
//output : 3
//time complexity O(n^2)
//space 174kb
