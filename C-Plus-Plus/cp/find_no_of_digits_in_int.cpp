#include <bits/stdc++.h>
using namespace std;

int num_of_digits(int num){
    int count = 0;                                       //count is a variable for number of digits
    
    while(num > 0){                                      //Ex : num = 324, count = 0 (Initially)
        count++;                                         //     num = 324, count = 1 (1st iteration)
        num /= 10;                                       //     num = 32, count = 2 (2nd iteration)
    }                                                    //     num = 3, count = 3 (3rd iteration)
                                                         //     num = 0, out of the loop
    return count;
}

int num_of_digits_recursive(int num){
    if(num == 0){                                        //Base case
        return 0;
    }
    
    return 1 + num_of_digits_recursive(num / 10);        
}

int num_of_digits_stringsoln(int num){
    string number = to_string(num);
    return number.size();                                //returning string length
}

int num_of_digits_logbased(int num){
    return floor(log10(num) + 1);                        //Number of digits in integer = upper bound of log10(N)
}

int main() {
    int num;
    cin >> num;                                           //Inputting the number
    cout << "The number of digits in given integer (using normal approach): " << num_of_digits(num) << endl;
    cout << "The number of digits in given integer (using recursive approach): " << num_of_digits_recursive(num) << endl;
    cout << "The number of digits in given integer (using string): " << num_of_digits_stringsoln(num) << endl;
    cout << "The number of digits in given integer (log based approach): " << num_of_digits_logbased(num) << endl;
    return 0;
}
