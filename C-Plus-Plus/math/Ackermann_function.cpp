// Ackermann Function implemented in C++

#include <iostream> 
using namespace std; 
int ackermann_function(int m, int n) 
{ 
    if (m == 0){ 
        return n + 1; 
    } 
    else if((m > 0) && (n == 0)){ 
        return ackermann_function(m - 1, 1); 
    } 
    else if((m > 0) && (n > 0)){ 
        return ackermann_function(m - 1, ackermann_function(m, n - 1)); 
    } 
}  
int main() 
{ 
    int m,n;
    cout<<"Enter two non negative integers:"<<endl;
    cin>>m>>n;
    int result=ackermann_function(m,n);
    cout << result << endl; 
    return 0; 
} 
//Time Complexity:O(mA(m, n))
//Space Complextiy:O(m)
