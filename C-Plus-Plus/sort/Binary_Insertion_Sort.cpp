#include<bits/stdc++.h>
using namespace std;
#define int               long long int
#define ff                first
#define ss                second
#define pb                push_back
#define mp                make_pair
#define pii               pair<int,int>
#define vi                vector<int>
#define vvi               vector<vector<int>>
#define mii               map<int,int>
#define pqb               priority_queue<int>
#define pqs               priority_queue<int,vi,greater<int> >
#define mod               1000000007
#define inf               1e18
#define ps(x,y)           fixed<<setprecision(y)<<x
#define heap(arr,n,type)  type *arr=new type[n];
#define w(x)              int x; cin>>x; while(x--)
#define endl              '\n'
#define fio               ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(var,s,e)      for(int var=s;var<e;var++)
#define repc(var,s,e)      for(int var=s;var<=e;var++)
#define setbits(x)        __builtin_popcountll(x)
#define numbits(x)        (64 - __builtin_clzll(x))
#define zerobit(x)        __builtin_ctzll(x)
#define log2(x)           (63 - __builtin_clzll(x))
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

bool comp(pair<pii,pii> x, pair<pii,pii> y){
    if(x.ff.ff<y.ff.ff) return true;
    else return false;
}
int binarySearch(int a[], int element, int low, int high)
{
    if (high <= low)
        return (element > a[low]) ? 
                (low + 1) : low;
 
    int mid = (low + high) / 2;
 
    if (element == a[mid])
        return mid + 1;
 
    if (element > a[mid])
        return binarySearch(a, element, mid + 1, high);
        
        
    return binarySearch(a, element, low, mid - 1);
}
 
void insertionSort(int arr[], int n)
{
    int i, place, j, k, selected;
 
    for (i = 1; i < n; ++i) 
    {
        j = i - 1;
        selected = arr[i];
 
        // location where selected sould be inseretd
        place = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= place) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}
 
signed main()
{
    //Let's take this unsorted array
    int arr[] = { 35, 23, 12, 17, 12, 72, 31, 46, 180, 88, 54 };
    int n = sizeof(a) / sizeof(a[0]), i;
 
    //Apply Sort
    insertionSort(a, n);
 
    cout<<"Sorted Array is :-"<<endl;
    
    for (i = 0; i < n; i++) cout<<arr[i]<<" ";
 
    return 0;
}




