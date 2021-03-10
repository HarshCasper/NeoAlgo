#include<iostream>
using namespace std;

//Exponentiation/Power using Bitmasking
int power_optimised(int base, int exp){

    int ans = 1;

    while (exp>0)
    {
        int last_bit = (exp&1);
        if(last_bit){
            ans=ans*base;
        }
        base=base*base; //Square up
        exp=exp>>1; //Discard the last bit of N
    }
    
    return ans;
}

int main(){

    int base, exp;
    cout<<"Enter the base number: ";
    cin>>base;
    cout<<"Enter the exponent: ";
    cin>>exp;

    cout<<"The power of "<<base<<" raised to "<<exp<<" is: "<<power_optimised(base,exp)<<endl;

    return 0;
}