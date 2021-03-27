#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//FUNCTION FOR CONVERSION OF BINARY NUMBER TO DECIMAL NUMBER
binarytodeci(long long int n)
{
  long long int num=0;
  int digit =0;
  int p=0;
  int x;
  while(n)
  {
     x=n%10;
     n=n/10;
     digit=x*pow(2,p);
     num=num+digit;
     p++;
  }
  cout<<"\n The Required Decimal Number is::"<<num;
}
int main()
{
  long long int Binary;
  cout<<"\n Enter The Binary Number:";
  cin>>Binary;
  binarytodeci(Binary);
  return 0;
}

/*
  INPUT::10000
  OUTPUT::16

  INPUT::10100001011
  OUTPUT::1291

  INPUT::11001
  OUTPUT::25

  Time Complexity- O(n);
  Space Complexity- O(1);

*/
