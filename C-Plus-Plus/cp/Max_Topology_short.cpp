/*Maximum Topology Short

First of all Lets Understand what is topology : 
The arrangement of a network that comprises nodes and connecting lines via sender and receiver is referred to as network topology.


Here is Problem statemet
Lets assume a Boy  has a tree  named that tree G with N nodes (numbered 1 through N) and N−1 undirected edges.
 For each node (u) in the tree, he can assign directions to the edges in such a way that (u) is reachable from all the other nodes.
 Let C(u) be the number of valid topological orderings in the resulting directed acyclic graph.

This way, the boy  obtains N pairs (C1,1),(C2,2),…,(CN,N) and he sorts all these pairs (Ci,i) in descending order 
(first by C(i) and in the case of a tie by i).

we have to find the maximum sorted pairs .
*/
/*To Include All Pre Required Liabries*/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007 


int n;
const int Limit = (int)5e5 + 5;
int Factorial_Number_Inverse[Limit + 1];

int Natural_Number_Inverse[Limit + 1];
int Factorial[Limit + 1];
//Function to Find Inverse of A Number
void Inverse_of_Number(int p)
{ 
    Natural_Number_Inverse[0] = Natural_Number_Inverse[1] = 1;
    for (int i = 2; i <= Limit; i++)
        Natural_Number_Inverse[i] = Natural_Number_Inverse[p % i] * (p - p / i) % p;
}

/* Function to Find Inverse of factorial*/
void Inverse_of_Factorial(int p)
{
    Factorial_Number_Inverse[0] = Factorial_Number_Inverse[1] = 1;
    for (int i = 2; i <= Limit; i++)
        Factorial_Number_Inverse[i] = (Natural_Number_Inverse[i] * Factorial_Number_Inverse[i - 1]) % p;
}

// To find factorial of a given number
void factorial(int p)
{ 
    Factorial[0] = 1;
    for (int i = 1; i <= Limit; i++)
    {
        Factorial[i] = (Factorial[i - 1] * i) % p;
    }
}

/*Function to Find Bionominal of A given Number*/
int Binomial(int Limit, int R, int p)
{
    if (R > Limit)
        return 0;
    if (R == Limit)
        return 1;
    int ans = ((Factorial[Limit] * Factorial_Number_Inverse[R]) % p * Factorial_Number_Inverse[Limit - R]) % p;
    return ans;
}
vector<vector<int>> akshay;  //Temp variable of vectore
vector<int> p;
vector<int> Temp_ways;
vector<int> sub_tree;
int dfs(int node)
{
    p[node] = 1;
    int sol = 1, subtree = 0;
    for (auto x : akshay[node])
    {
        if (p[x] == 0)
        {
            int curr_s = dfs(x);
            subtree += curr_s;
            sol *= Binomial(subtree, curr_s, mod);
            sol %= mod;
            sol *= Temp_ways[x];
            sol %= mod;
        }
    }
    sol %= mod;
    Temp_ways[node] = sol;
    return subtree + 1;
}
vector<pair<int, pair<int, int>>> AA;
int getNode(int node)
{
    p[node] = 1;
    int subtree = 0, curr;
    for (auto x : akshay[node])
    {
        if (p[x] == 0)
        {
            curr = getNode(x);
            subtree += curr;
            int abcd = min(curr, (n - curr));
            AA.push_back({abcd, {x, node}});
        }
    }
    sub_tree[node] = subtree + 1;
    return subtree + 1;
}
int32_t main()
{
    factorial(mod);
    Inverse_of_Number(mod);
    Inverse_of_Factorial(mod);

    int k;
    cin >> n >> k;
    int m = n - 1;
    akshay.clear(), p.clear(), Temp_ways.clear();
    akshay.resize(n), p.resize(n, 0), Temp_ways.resize(n);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        akshay[x - 1].push_back(y - 1);
        akshay[y - 1].push_back(x - 1);
    }
    if (n == 1)
    {
        int k1 = 0, k2 = 0;
        if (k == 1)
        {
            p.clear(), Temp_ways.clear();
            p.resize(n, 0), Temp_ways.resize(n);
            dfs(k1);
            cout << k1 + 1 << " " << Temp_ways[k1] % mod << endl;
        }
        else
        {
            p.clear(), Temp_ways.clear();
            p.resize(n, 0), Temp_ways.resize(n);
            dfs(k2);
            cout << k2 + 1 << " " << Temp_ways[k2] % mod << endl;
        }
    }
    AA.clear(), sub_tree.clear(), sub_tree.resize(n);
    getNode(0);
    int idx = 1;
    //Sort of Vector
    sort(AA.begin(), AA.end(), greater<pair<int, pair<int, int>>>());
    int k1, k2;
    if (AA[0].first != AA[1].first)
    {
        int X = AA[0].second.first, Y = AA[0].second.second;
        if (sub_tree[X] == n - sub_tree[X])
        {
            //k1 stores the maximum element of pair
            k1 = max(X, Y);
            //k2 stores min elements of pair
            k2 = min(X, Y);
        }
        else
        {
            if (sub_tree[X] > n - sub_tree[X])
            {
                k1 = X;
                k2 = Y;
            }
            else
            {
                k2 = X;
                k1 = Y;
            }
        }
    }
    else
    {
        vector<int> temp;
        if ((AA[0].second.first == AA[1].second.first) || (AA[0].second.first == AA[1].second.second))
        {
            k1 = AA[0].second.first;
        }
        else
        {
            k1 = AA[0].second.second;
        }
        idx = 1;
        temp.push_back((AA[0].second.first != k1) ? AA[0].second.first : AA[0].second.second);
        while (idx != n && AA[idx - 1].first == AA[idx].first)
        {
            temp.push_back((AA[idx].second.first != k1) ? AA[idx].second.first : AA[idx].second.second);
            ++idx;
        }
        k2 = *max_element(temp.begin(), temp.end());
    }
    if (k == 1)
    {
        p.clear(), Temp_ways.clear();
        p.resize(n, 0), Temp_ways.resize(n);
        dfs(k1);
        cout << k1 + 1 << " " << ((Temp_ways[k1] % mod) + mod) % mod << endl;
    }
    else
    {
        p.clear(), Temp_ways.clear();
        p.resize(n, 0), Temp_ways.resize(n);
        dfs(k2);
        cout << k2 + 1 << " " << ((Temp_ways[k2] % mod) + mod) % mod << endl;
    }
}


/*  Example Test Cases

consider the tree below:
                    2
            1                 3


The sorted list of pairs is ((2,2),(1,3),(1,1)).



*/
/* Example input

4 2
1 2
2 3
2 4 
Output:
4 2 

For u=1, there are C1=2 possible topological orderings: (3,4,2,1) and (4,3,2,1)
For u=2, there are C2=6 possible topological orderings: (3,4,1,2), (4,3,1,2), (3,1,4,2), (4,1,3,2), (1,3,4,2) and (1,4,3,2).
For u=3, there are C3=2 possible topological orderings: (1,4,2,3) and (4,1,2,3).
For u=4, there are C4=2 possible topological orderings: (3,1,2,4) and (1,3,2,4).
The sorted list of pairs is ((6,2),(2,4),(2,3),(2,1)).
 The node for the 2-nd pair is 4 and the corresponding number of topological orderings modulo 109+7 is 2*/