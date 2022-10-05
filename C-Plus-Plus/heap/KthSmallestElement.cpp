class Solution{
    public:

    int kthSmallest(int arr[], int l, int r, int k) {
       priority_queue<int,vector<int>,greater<int>> p;
       for(int i=l;i<=r;i++)
       {
           p.push(arr[i]);
           
       }
       k--;
       while(k--)
       {
           p.pop();
           
       }
       return p.top();
       
    }
};
