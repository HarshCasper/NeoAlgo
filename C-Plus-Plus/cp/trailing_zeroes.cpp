#include <iostream>
using namespace std;
//function to calculate trailing zeroes
int calculate(int num)
{
    int f=0;
    for (int i =5;num/i>=1;i*=5)
    {
        f=f+num/i;
    }
    return f;
}
int main()
  {
      int num;
      cout<<"enter the number: \n";
      cin>>num;
      cout<<"No. of trailing zeroes in "<< num <<" are " <<"\n"<<calculate(num);
 return 0;
}