/*
We are given two arrays a[] and b[].
We have to find all possible sums a[i]+b[j], 
and for each sum count how often it appears.
Let the size of array a be n and array b be m.
Sample Input: 
3 2
1 2 3
4 5
Sample Output:
5 1
6 2
7 2
8 1
Large Data file: https://bit.ly/3l8Zo9q
Output file: https://bit.ly/3jqnz2C 
Constraints:
1<=n<=1e5
1<=m<=1e5
0<=ai<=1e4
0<=bi<=1e4
Time Limit: 1 sec
My Solution using Fast Fourier Transform:
We construct for the arrays a and b two polynomials A and B. 
The numbers of the array will act as the exponents in the polynomial (a[i]⇒xa[i]); 
and the coefficients of this term will by how often the number appears in the array.
Then, by multiplying these two polynomials in O(nlogn) time, we get a polynomial C, 9
where the exponents will tell us which sums can be obtained, 
and the coefficients tell us how often
Recorded Time for boundary limits:
n=1e5
m=1e5
0<=ai,bi<=1e4
Efficiency: O((n+m)log(n+m))
Execution Time: 0.621 secs
Language: C++17
for more details on this algorithm goto
https://cp-algorithms.com/algebra/fft.html
*/


#include<bits/stdc++.h>
using namespace std;

using cd=complex<double>;
//Range is the maximum limit of ai & bi together
#define RANGE 1e4
const double PI = acos(-1);

//standard Fast Fourier Transform Algorithm
void fft(vector <cd> &a, bool invert) 
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) 
    {
        int bit = n>>1;
        for (; j & bit; bit>>=1)
            j ^= bit;
        j ^= bit;
        if (i < j) 
        	swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len<<=1) 
    {
        double ang=2*PI/len*(invert?-1:1);
        cd wlen(cos(ang),sin(ang));
        for(int i=0;i<n;i+=len) 
        {
            cd w(1);
            for (int j = 0; j < len/2; j++) 
            {
                cd u = a[i + j], v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) 
    	for (cd &x : a) 
    	    x /= n;
}

/*This function works with polynomials with integer coefficients, 
however you can also adjust it to work with other types. 
Since there is some error when working with complex numbers, 
we need round the resulting coefficients at the end.*/
vector<int> multiply(vector <int> const &a, vector <int> const &b) 
{
    vector <cd> fa(a.begin(), a.end());
    vector <cd> fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    vector <int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main()
{
    //declare and read the values of a and m;
    int n, m, temp; 
    cin >> n >> m;
    //declare and read the values of a[] of size n 
    //at the same time create the polynomial A
    vector <int> A(RANGE, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        A[temp]++;
    }
    //declare and read the values of a[] of size n 
    //at the same time create the polynomial B
    vector <int> B(RANGE, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        B[temp]++;
    }
    //apply the algorithm to compue the sums and
    //their respective frequency
    vector <int> ans = multiply(A, B);
    for (int i = 0; i < ans.size(); i++)
        //if the the frequency is not zero then the value exists
        if (ans[i] != 0) 
            cout << i << " " << ans[i] << endl;
    return 0;
}
