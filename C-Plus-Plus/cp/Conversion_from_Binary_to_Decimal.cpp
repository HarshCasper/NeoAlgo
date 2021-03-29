/* C++ Program for Conversion of Binary Number to Decimal Number
In this Program only input line contains an integer input 'number'. Its length does not exceed 10.
Here, a function named 'binary_to_decimal' will convert the given binary input into decimal number.
And output contain Decimal Conversion of input in a single line.
*/  
#include<bits/stdc++.h>
using namespace std;
int binary_to_decimal(int number){
    int i, remainder, store, output;    
    remainder=1;
    store=1;
    output=0;  
    for(i=0;number>0;i++){
        //dividing number by 10 to get digits according to place value     
        remainder=number%10;
        //multiplying remainder with power of 2 according to its place value
        store=remainder*(pow(2,i));
        //storing this in 'output' in each iteration
        output=output+store;
        number=number/10;
    }
    return output;
}
int main(){
    int numberInput,l,k;
    cin>>numberInput;
    cout<<binary_to_decimal(numberInput)<<endl;
    return 0;
}

/* SAMPLE
Testcase 1
INPUT   100
OUTPUT  4   
Time Complexity is O(T)    where T is number of digit in 'number'
Space Complexity is O(1)   */
