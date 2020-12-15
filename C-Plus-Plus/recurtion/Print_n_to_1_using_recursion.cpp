//Question Print n to 1 using recursion

#include <iostream>
using namespace std;

void print(int n){
    if(n==0)    
        return;
    
    cout << n << " ";
    print(n-1);
    
}

int main()
{
    int n;

    cout << "Enter the  value of n : ";
    cin >> n;

    print(n);

    return 0;
}

/*
Input
Enter the  value of n : 5

Output
5 4 3 2 1
*/