#include<bits/stdc++.h>
using namespace std;
//This functions returns the least significant bit
int check_bit(int n){
    return n&1;
}
//This functions sets the given bit from the right
//example n=11001 pos=2 , makes -> 11011 i.e second bit from right
int set_bit(int n,int pos){
    int mask =1;
    mask<<=pos-1;
    return n|mask;
}
//Returns the complement of a number
int complement(int n, int bits){
    return ((1<<bits)-1) ^ n;
}
//Clears the bit at given position from the right
int clear_bit(int n,int pos){
    int mask = 1;
    mask<<=pos-1;
    int bits = floor(log2(n)) + 1;
    mask = complement(mask,bits);
    return n&mask;
}
int main(){
    int n,pos; cin>>n>>pos;
    cout<<check_bit(n)<<endl;
    cout<<set_bit(n,pos)<<endl;
    cout<<clear_bit(n,pos)<<endl;
    return 0;
}
/*
Input:
25 1
Output
1
25
24

Time complexity: O(1) for all
Space complexity: O(1) for all
*/
