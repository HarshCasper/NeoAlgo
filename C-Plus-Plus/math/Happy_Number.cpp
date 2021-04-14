/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.

Example:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
#include <iostream>
using namespace std;

class Happy {
    int n;
public:
    void set_data(){
        cout<<"Enter the number you want to check"<<endl;
        cin>>n;
    }
    bool isHappy(int n) {
        if (n==1)
            return true;
        else if (n!=7 and n < 10)
            return false;
        else
            return isHappy(sq_of_dig(n));
        return false;
    }
    int sq_of_dig(int n){
        int s=0;
        while(n!=0){
            int d= n%10;
            s=s+d*d;
            n=n/10;
        }
        return s;
    }
    void display(){
        if(isHappy(n))
            cout<<"Yes its a happy number";
        else
            cout<<"No its not a happy number";
    }
};
int main()
{
    Happy h;
    h.set_data();
    h.display();

    return 0;
}
/*
Enter the number you want to check
Input: 19
Output: Yes its a happy number

Enter the number you want to check
Input: 2
Output: No its not a happy number
*/
