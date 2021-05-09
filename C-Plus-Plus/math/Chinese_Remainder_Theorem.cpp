/*The Chinese remainder theorem is a theorem that gives a unique solution to simultaneous linear \
congruences with coprime moduli. In its basic form, the Chinese remainder theorem will determine 
a number p that, when divided by some given divisors, leaves given remainders.*/

// A C++ program to demonstrate working of Chinese Remainder Theorem
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int inverse(int n, int mod){
  int mod_bak = mod;
  int n_bak = n;
  n = n % mod;
  int d = 0;
  if(n == 0 && d == 1)
    return 0;
  else if(n == 0 && d != 1){
    cout << n << " is not inversibe mod " << mod << endl;
    return 9999;
  }
  else{
    int x1 = 1;
    int x2 = 0;
    int y1 = 0;
    int y2 = 1;
    int q3 = 0;
    int r = 0;
    int y3 = 0;
    int x3 = 0;
    while(n > 0){
      q3 = mod / n;
      r = mod - q3 * n;
      x3 = x1 - q3 * x2;
      y3 = y1 - q3 * y2;
      mod = n; 
      n = r; 
      x1 = x2;
      y1 = y2;
      x2 = x3;
      y2 = y3;
    }
    if(mod == 1){
      if(y1 < 0)
        y1 += mod_bak;
      return y1;
    }
    else{
      cout << n << " is not inversibe mod " << mod << endl;
      return 9999;
    }
  }
}

int CRT(vector<int> a, vector<int> n){
  if(a.size()!= n.size()) cout << "length don't match" << endl;
  int N = 1;
  for_each(n.begin(), n.end(), [&](int i){N *= i;});
  vector <int> n_comp;
  vector <int> M;
  for_each(n.begin(), n.end(), [&](int i){n_comp.push_back(N/i); M.push_back(inverse(N/i , i));});

  int x = 0;
  for(int i = 0; i < n.size(); ++i)
    x += a[i] * n_comp[i] * M[i];

  return x % N;

}
    
int main(){
  long long int s,p,q;
  cin>>s;
  vector<int> n;
  vector<int> a;
  for(int i=0 ; i<s ; i++)
  {cin>>p>>q;
  n.push_back(p);
  a.push_back(q);
  }
  cout << CRT(a,n)  << endl;
  return 0;
}

/*Two Test case you can try out with this code-
# Input  3
         2 1
         3 2
         5 3
  Output  23
# Input  2
         12 2
         13 4
  Output 134 */

/*Time Complexity = O(n), n is the product of all elements of array
Space Complexity = O(1)*/