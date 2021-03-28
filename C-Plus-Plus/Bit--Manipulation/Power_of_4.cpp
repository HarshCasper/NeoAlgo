#include<iostream>
using namespace std;
bool check_power_of_4(int n)
{
    int count=0;
        if(n<0) 
        return false;
        //As soon as number is <=0 we tend to stop our loop
        while(n){
            //condition to check whether it is a multiple of 4 or not. 
            if(n&1 == 1 && n>>1!=0)
             return false; 
            n>>=1;count++;
        }
        return count%2?true:false;
}
int main()
{
    int n;
    cout<<"Enter the number of which you want to check";
    cin>>n;
    cout<<endl;
    check_power_of_4(n)?cout<<"YES"<<endl:cout<<"NO"<<endl;
}


// Sample Input:
// You enter n, i.e. a number you want to check if its a multiple of 4 or not.

//Output:
//It prints yes or no on the condition whether n is a multiple of 4 or not.
