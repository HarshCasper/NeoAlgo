#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>& h) {
    int count = 0;
    
    int left = 0;
    int right = h.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    while(left<right){
        if(h[left]<h[right]){
            if(h[left]>leftMax){
                leftMax = h[left];
            }else{
                count += (leftMax - h[left]);
            }
            left++;
        }else{
            if(h[right]>rightMax){
                rightMax = h[right];
            }else{
                count += (rightMax - h[right]);
            }
            right--;
        }
    }
    return count;
}
int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
	    cin>>v[i];
	}
	cout<<"Maximum Water trapped is : "<<trap(v)<<"\n";
	return 0;
}
