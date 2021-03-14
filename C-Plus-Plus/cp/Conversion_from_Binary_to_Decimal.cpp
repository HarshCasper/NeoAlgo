/* C++ Program for Conversion of Binary Number to Decimal Number
In this Program only input line contains an integer input 'number'. Its length does not exceed 10.
Here, a function named binary_to_decimal will convert the given binary input into decimal number.
And output contain Decimal Conversion of input in a single line.
*/  
#include<bits/stdc++.h>
using namespace std;
int binary_to_decimal(int number){
    int i, remainder, store, output;
    //initialising variables     
    remainder=1;
    store=1;
    output=0;
    //loop to perform conversion task    
    for(i=0;number>0;i++){
        //dividing number by 10 to get its digits of one's place, ten's place, etc.. in each iteration respectively    
        remainder=number%10;
        //multiplying remainder with power of 2 according to its place value
        store=remainder*(pow(2,i));
        //storing this in each iteration to get the final output at end
        output=output+store;
        //modifying number
        number=number/10;
    }
    return output;
}
int main(){
    int numberInput,l,k;
    //getting user input
    cin>>numberInput;
    //calling function to perform the task
    cout<<binary_to_decimal(numberInput)<<endl;
    return 0;
}

/* SAMPLE
Testcase 1
INPUT   100
OUTPUT  4
Testcase 2
INPUT   1111
OUTPUT  15
Testcase 3
INPUT   111000
OUTPUT  56   
Time Complexity is O(t)    where t is number of digit in 'number'
Space Complexity is O(1)   */

