#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//FUNCTION FOR CONVERSION OF DECIMAL NUMBER TO BINARY NUMBER
decitobinary(long long int n)
{
  long long int num=0;
  int digit =0;
  int p=1;
  int x;
  while(n)
    {
      x=n%2;
      n/=2;
      digit=x*p;
      num=num+digit;
      p*=10;
    }
  cout<<"\n The Required Binary Number is::"<<num;
}
int main()
{
  long long int decimal;
  cout<<"\n Enter The Decimal Number:";
  cin>>decimal;
  decitobinary(decimal);
  return 0;
}

/*
  INPUT::160
  OUTPUT::10100000

  INPUT::952
  OUTPUT::1110111000

  INPUT::181
  OUTPUT::10110101

  Time Complexity- O(n);
  Space Complexity- O(1);

*/
