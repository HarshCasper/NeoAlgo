#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
 #define pip pair<int, pii> 
// Function to find k pairs
// with least sum such
// that one elemennt of a pair
// is from arr-A and
// other element is from arr-B
void kSmallestPair(vector<int> A, vector<int> B, int K)
{
    sort(A.begin(), A.end()); //sort the arrays
    sort(B.begin(), B.end());
 
    int n = A.size();
 // make heap of pairs, push values, pop it when size > k
        // in the end, pop all values and psh it in a vector
 
    priority_queue<pip,
                   vector<pip >,
                   greater<pip > >
        pq;
 
    // pairs is used to store the indices of
    //pair(i, j)
 
    set<pair<int, int> > pairs;
 
    // initialize the heap with the minimum sum
    // combination i.e. (A[0] + B[0])
    // and also push indices (0,0) along
    // with sum.
 
    pq.push(make_pair(A[0] + B[0], make_pair(0, 0)));
 
    pairs.insert(make_pair(0, 0));
 
    // iterate upto K
 // run double for loop to create all pairs,and push values based on the sum values
    for (int l = 0; l < K; l++) {
 
        // tuple format (sum, i, j).
        pip temp = pq.top();
        pq.pop();
 
        int i = temp.second.first;
        int j = temp.second.second; 
            // pq.top().second.first means, pair's top's value's second's part's first value
 
        cout << "(" << A[i] << ", " << B[j] << ")"
             << endl; // Extracting pair with least sum such
                      // that one element is from A and
                      // another is from B
 
        // check if i+1 is in the range of our first array A
        if (i + 1 < A.size()) {
             
            int sum = A[i + 1] + B[j];
            // insert (A[i + 1] + B[j], (i + 1, j))
            // into min heap.
            pair<int, int> x = make_pair(i + 1, j);
 
            // insert only if the pair (i + 1, j) is
            // not already present inside the map i.e.
            // no repeating pair should be present inside
            // the heap.
 
            if (pairs.find(x) == pairs.end()) {
                pq.push(make_pair(sum, x));
                pairs.insert(x);
            }
        }
        // check if j+1 is in the range of our second array
        // B
        if (j + 1 < B.size()) {
            // insert (A[i] + B[j + 1], (i, j + 1))
            // into min heap.
 
            int sum = A[i] + B[j + 1];
            pair<int, int> x = make_pair(i, j + 1);
 
            // insert only if the pair (i, j + 1)
            // is not present inside the heap.
 
            if (pairs.find(x) == pairs.end()) {
                pq.push(make_pair(sum, x));
                pairs.insert(x);
            }
        }
    }
}
 
// Driver Code.
int main()
{
    vector<int> A;
    vector<int> B ;
    int n,m,x,y;
    cout<<"Enter the number of elements in array A and B resp:";
    cin>>n>>m;
    cout<<"Enter elements of A:";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        A.push_back(x);
    }
    cout<<"Enter elements of B:";
    for(int i=0;i<m;i++)
    {
        cin>>y;
        B.push_back(y);
    }
    int K ;
    cout<<"Enter K- no. of pairs:";
    cin>>K;
    kSmallestPair(A, B, K);
    return 0;
}