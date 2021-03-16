#include <bits/stdc++.h>
using namespace std;
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n, p = 0;
    cin >> n;
    int a[n];

    fr(i, 0, n)
    {
        cin >> a[i];
    }
    fr(i, 0, n - 1)
    {
        while ((i < n - 1) && (a[i + 1] <= a[i]))
        {
            i++;
        }
        if (i == n - 1)
            break;
        int buy = i++;
        while ((i < n) && (a[i + 1] >= a[i]))
        {
            i++;
        }
        int sell = i--;
        cout << buy << " " << sell << "\n";
        p = p + (a[sell] - a[buy]);
    }
    cout << p << "\n";

    return 0;
}