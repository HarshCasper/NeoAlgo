/*Call by reference is a method in C++ to pass the values to the function arguments.
In the case of call by reference, the reference of actual parameters is sent to the formal parameter,
which means that if we change the values inside the function that will affect the actual values. */

//Code for Call by reference

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{    int temp = a;
     a = b;
     b = temp;
}

int main(){
    int x , y;
    cout<<"Enter the value of x and y\n";
    cin>>x>>y;
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    swap(x, y); 
    cout<<"After Swap\n";
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl; 
    return 0;
}


/*Two Test case you can try out with this code-
# Input  10 20
  Output  20 10
# Input  1 9
  Output 9 1  */

/*Time Complexity = O(n)
Space Complexity = O(n)*/