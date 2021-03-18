/*
We can use binary search to reduce the number of comparisons in normal insertion sort.
Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration. 
In normal insertion sort, it takes O(n) comparisons (at nth iteration) in the worst case.
We can reduce it to O(log n) by using binary search.
*/

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
//searching element in array a by binary search algoritm
int binarySearch(int a[], int element, int low, int high)
{
    if (high <= low){
        return (element > a[low]) ? (low + 1) : low;
    }
    int mid = (low + high) / 2;
    if (element == a[mid]){
        return mid + 1;
    } 
    if (element > a[mid]){
        return binarySearch(a, element, mid + 1, high);
    }
    return binarySearch(a, element, low, mid - 1);
}
// sorting using insertion sort
void insertionSort(int arr[], int n)
{
    // initializing variables
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
 
    //Applying Sort
    //calling sort function
    insertionSort(a, n);
    cout<<"Sorted Array is :-";
    for (i = 0; i < n; i++){ 
        cout<<arr[i]<<" ";
    }
    return 0;
}
/* Sample Input
arr = 35 23 12 17 12 72 31 46 180 88 54
*/
/* Sample Output
Sorted Array is:- 12 12 17 23 31 35 46 54 72 88 180
*/

// Time Complexity -O(n^2)
//Space Complexity -O(n)




