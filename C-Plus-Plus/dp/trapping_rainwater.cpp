//given n towers of specified height, stacked alongside each other, the goal is to find the amount of water stored by the stacking towers, if rain water falls without any upper bound. We assume that 1 unit space between the towers store 1 unit water.
#include<bits/stdc++.h>
using namespace std;
int trap(vector<int> tower) {
    //tower is a vector such that tower[i] represents height of ith tower from the left
    if(tower.size()<= 1) return 0; //at least two towers are needed to trap water
    int n= tower.size();
    vector<int> max_left(n, 0); //max_left[i] represents the height of tallest tower uptil ith position, starting from left to right
    vector<int> max_right(n, 0);// max_right[i] represents the height of tallest tower uptil ith position, from right to left.
    int water =0;
    max_left[0]= tower[0];
    max_right[n-1]= tower[n-1];
    for(int i=1; i<n; i++){
        max_left[i]= max(max_left[i-1], tower[i]);
    }
    for(int i= n-2; i>=0; i--){
        max_right[i]= max(max_right[i+1], tower[i]);
    }
    // The the maximum water trapped in at a position depends on the shorter tower on either side, hence now we can treat each tower segment as an independent water body and subtracting the tower height from that body of standing water will give the water trapped in that segment. 
    for(int i=0; i<n; i++){
        water+= min(max_left[i], max_right[i]) - tower[i];
    }
    return water;
}
int main(){
    cout<<"Enter number of towers\n";
    int n;
    cin>>n;
    cout<<"Enter tower heights\n";
    vector<int> tower(n);
    for(int i=0; i<n; i++)
        cin>>tower[i];
    cout<<"Amount of rainwater trapped by towers is:\n "<< trap(tower)<<endl;
    return 0;
}
/*Input/Output
Ex 1:
Enter number of towers
12
Enter tower heights
0 1 0 2 1 0 1 3 2 1 2 1
Amount of rainwater trapped by towers is:
 6
Ex 2:
Enter number of towers
6
Enter tower heights
4 2 0 3 2 5
Amount of rainwater trapped by towers is:
 9
*/
