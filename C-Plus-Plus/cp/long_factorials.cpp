/*Finding huge factorials such as !100, !1000 is sometimes required but in languages such as C++
the datatypes are not even capable of storing such a big number. We could achieve calculation of
such a number via going back to the basis of how we used to muiltiply two numbers back in school days. 
We used to muiltiply numbers and would add the summation and get the final result. 
This program here uses a vector to store each particular digit in a single index of the vector. 
The carry is forwarded as basic maths and in the end the complete result gets stored in the vector*/

#include <vector>
#include <iostream>

using namespace std;


int main() {
    int num;
    int carry = 0;       
    cin >> num;                  //Input the number whose factorial is to be calculated 
    vector <int> arr(10000, 0);  //The size of the vector should be more than the digits present 
    arr[0] = 1;                  //in the factorial of the number.  
    int k = 0;                         

    for(int i = 1; i <= num; i++) {
        for(int j = 0;j <= k; j++) {      
            arr[j] = arr[j] * i + carry;
            carry = arr[j] / 10;
            arr[j] = arr[j] % 10;
        }
        while(carry) {        //The carries are forwarded in order to get the final result
            k++;
            arr[k] = carry % 10;
            carry /= 10;
        }   
    }
    for(int i = k; i >= 0; i--) {  //Each digit of the final answer is stored in a single index 
        cout << arr[i];            //of the vector    
    }
    cout << "\n";
    return 0;
}
