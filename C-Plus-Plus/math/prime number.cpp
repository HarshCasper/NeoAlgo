// Check if a given number is a Prime Number or not.
// e.g :

// Input : 
// Enter a number : 13
// Output : 
// 13 is a Prime Number.



#include <iostream>
using namespace std;
int main() {
    int n, i, flag = 0;
     cout<<"Input :"<<endl;
     cout<<"Enter a number : "; 
     cin>>n;
     cout<<endl;
     cout<<"Output :"<<endl;
    for (i = 2; i <= n / 2; ++i) {

        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (n == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (flag == 0)
            cout<<n<<" is a prime number";
        else
            cout<<n<<" is a prime number";
    }

    return 0;
}