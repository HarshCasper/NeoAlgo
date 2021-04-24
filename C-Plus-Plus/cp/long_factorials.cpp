/*Finding huge factorials such as !100, !1000 is sometimes required but in languages such as C++
the datatypes are not even capable of storing such a big number. We could achieve calculation of
such a number via going back to the basis of how we used to muiltiply two numbers back in school days. 
We used to muiltiply numbers and would add the summation and get the final result. 
This program here uses a vector to store each particular digit in a single index of the vector. 
The carry is forwarded as basic maths and in the end the complete result gets stored in the vector*/

//The length of vector should be >= length of the resultant factorial

#include<bits/stdc++.h>
using namespace std;

/*The function takes a number and muiltiplies the number in the school's old fashioned way 
where we muiltiply the complete digit by one digit and then add the results to get the final 
resultant. The carry is carried forwarded and in the end the final result gets stored in the 
array/vector. */

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

/*Sample test case 
Input: 15
Output: 1307674368000

Time Complexity = O(N)
Space Complexity = O(1)
 */

