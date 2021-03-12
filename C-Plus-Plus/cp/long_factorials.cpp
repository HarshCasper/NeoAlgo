/*Finding huge factorials such as !100, !1000 is sometimes required but in languages such as C++
the datatypes are not even capable of storing such a big number. We could achieve calculation of
such a number via going back to the basis of how we used to muiltiply two numbers back in school days. 
We used to muiltiply numbers and would add the summation and get the final result. 
This program here uses a vector to store each particular digit in a single index of the vector. 
The carry is forwarded as basic maths and in the end the complete result gets stored in the vector*/

//The length of vector should be >= length of the resultant factorial

// Time Complexity = O(N)

#include <vector>
#include <iostream>

using namespace std;


void factorial(int val)
{
    int carry = 0;       
    vector <int> arr(10000, 0);   
    arr[0] = 1;                   
    int k = 0;                         

    for(int i = 1; i <= val; i++) {
        for(int j = 0;j <= k; j++) {      
            arr[j] = arr[j] * i + carry;
            carry = arr[j] / 10;
            arr[j] = arr[j] % 10;
        }
        while(carry) {        
            k++;
            arr[k] = carry % 10;
            carry /= 10;
        }   
    }
    for(int i = k; i >= 0; i--) {  
        cout<<arr[i];
    }
    cout << "\n";
}
int main() {
    int num;
    cin>>num;
    factorial(num);
    return 0;
}

/*Sample test cases 
1. Input: 5
   Output: 120
2. Input: 50
   Output: 30414093201713378043612608166064768844377641568960512000000000000 
 */