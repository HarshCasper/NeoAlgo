// Given 2 integers lets say N and i. All bits are cleared from most significant bit to ith bit. The counting of bits starts from right to left. Updated N is returned
#include<iostream>
using namespace std;

int clearAllBits(int n, int i){

n &= (1<<i)-1;
return n;
}

int main() {
int n, i;

cin >> n >> i;

cout<< clearAllBits(n, i) <<endl;
	
return 0;
}
// input 15 2, It will return 3