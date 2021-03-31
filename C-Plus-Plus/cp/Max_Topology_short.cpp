/*Maximum Topology Short 
For example, consider the tree below:
              2
        1           3 


The sorted list of pairs is ((2,2),(1,3),(1,1))
*/

#include<bits/stdc++.h>  //TO include all pre required liabries
using namespace std;

#define int           long long int
#define mod 1000000007 //Defining macros
int n;
const int Limit = (int)5e5 + 5;
int fni[Limit + 1];
int nni[Limit + 1];
int f_a_c_t[Limit + 1];
void I_o_N(int p) { //to find inverse of number
 nni[0] = nni[1] = 1;
 for (int i = 2; i <= Limit; i++)
  nni[i] = nni[p % i] * (p - p / i) % p;
}
void I_o_f(int p) {
 fni[0] = fni[1] = 1;
 for (int i = 2; i <= Limit; i++)
  fni[i] = (nni[i] * fni[i - 1]) % p;
}
void factorial(int p) {// To find factorial of a given number
 f_a_c_t[0] = 1;
 for (int i = 1; i <= Limit; i++) {
  f_a_c_t[i] = (f_a_c_t[i - 1] * i) % p;
 }
}
int Binomial(int Limit, int R, int p) {
    if(R>Limit) return 0;
    if(R==Limit) return 1;
 int ans = ((f_a_c_t[Limit] * fni[R]) % p * fni[Limit - R]) % p;
 return ans;
}
vector<vector<int>> akshay;
vector<int> pankaj;
vector<int> ways;
vector<int> sub;
int dfs(int node) {
    pankaj[node] = 1;
    int sol=1, subtree=0;
    for(auto x: akshay[node]) {
        if(pankaj[x] == 0) {
            int curr_s = dfs(x);
            subtree += curr_s;
            sol*= Binomial(subtree, curr_s, mod);
            sol%=mod;
            sol*=ways[x];
            sol%=mod;
        }
    }
    sol%=mod;
    ways[node] = sol;
    return subtree+1;
}
vector<pair<int, pair<int, int>>> AA;
int getNode(int node) {
    pankaj[node] = 1;
    int subtree=0, curr;
    for(auto x: akshay[node]) {
        if(pankaj[x] == 0) {
            curr = getNode(x);
            subtree += curr;
    int abcd = min(curr,(n-curr));
            AA.push_back({abcd, {x, node}});
        }
    }
    sub[node] = subtree+1;
    return subtree+1;
}
int32_t main() {
    factorial(mod);
    I_o_N(mod);
    I_o_f(mod);
    
        int  k;
        cin>>n>>k;
        int m=n-1;
        akshay.clear(), pankaj.clear(), ways.clear();
        akshay.resize(n), pankaj.resize(n, 0), ways.resize(n);
        while(m--) {
            int x,y;
            cin>>x>>y;
            akshay[x-1].push_back(y-1);
            akshay[y-1].push_back(x-1);
        }
        if(n==1) {
            int k1=0,k2=0;
            if(k==1) {
                pankaj.clear(), ways.clear();
                pankaj.resize(n, 0), ways.resize(n);
                dfs(k1);
                cout<<k1+1<<" "<<ways[k1]%mod<<endl;
            } else {
                pankaj.clear(), ways.clear();
                pankaj.resize(n, 0), ways.resize(n);
                dfs(k2);
                cout<<k2+1<<" "<<ways[k2]%mod<<endl;
            }
          
        }
        AA.clear(), sub.clear(), sub.resize(n);
        getNode(0);
        int idx=1;
        sort(AA.begin(), AA.end(), greater<pair<int, pair<int, int>>>());
        int k1,k2;
        if(AA[0].first != AA[1].first) {        
            int X = AA[0].second.first, Y = AA[0].second.second;
            if(sub[X] == n-sub[X]) {
                k1=max(X, Y);
                k2=min(X, Y);
            } else {
                if(sub[X] > n-sub[X]) {
                    k1=X;
                    k2=Y;
                } else {
                    k2=X;
                    k1=Y;
                }
            }
        } else {
            vector<int> temp;
            if((AA[0].second.first == AA[1].second.first) || (AA[0].second.first == AA[1].second.second)) {
                k1 = AA[0].second.first;
            } else {
                k1 = AA[0].second.second;
            }
            idx = 1;
            temp.push_back((AA[0].second.first != k1)? AA[0].second.first : AA[0].second.second);
            while(idx!=n && AA[idx-1].first == AA[idx].first ) {
                temp.push_back((AA[idx].second.first != k1)? AA[idx].second.first : AA[idx].second.second);
                ++idx;
            }
            k2 = *max_element(temp.begin(), temp.end());
        }
        if(k==1) {
            pankaj.clear(), ways.clear();
pankaj.resize(n, 0), ways.resize(n);
            dfs(k1);
            cout<<k1+1<<" "<<((ways[k1]%mod) +mod)%mod<<endl;
        } else {
            pankaj.clear(), ways.clear();
            pankaj.resize(n, 0), ways.resize(n);
            dfs(k2);
            cout<<k2+1<<" "<<((ways[k2]%mod)+mod)%mod<<endl;
        }
    
}
/* Example input

4 2
1 2
2 3
2 4 
Output:
4 2 */