#include<iostream>
using namespace std;
void swap_using_bit_manipulation(int &a,int &b)
{
    a=a^b;
    b=b^a;
    a=a^b;
}
int main()
{
    int a,b;
    cout<<"Enter numbers you want to swap:  ";
    cin>>a>>b;
    cout<<endl<<"Before Swapping a is  "<<a<<" "<<"b is  "<<b;
    swap_using_bit_manipulation(a,b);
    cout<<endl<<"After  Swapping a is  "<<a<<" "<<"b is  "<<b;
}