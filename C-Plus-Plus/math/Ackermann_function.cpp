// Ackermann Function implemented in C++

#include <iostream> 
using namespace std; 
int ackermann_function(int m, int n) 
{ 
    if (m == 0){ 
@@ -15,8 +14,6 @@ int ackermann_function(int m, int n)
        return ackermann_function(m - 1, ackermann_function(m, n - 1)); 
    } 
} 

// Driver code 
int main() 
{ 
    int m,n;
@@ -26,3 +23,5 @@ int main()
    cout << result << endl; 
    return 0; 
} 
//Time Complexity:O(mA(m, n))
//Space Complextiy:O(m)
