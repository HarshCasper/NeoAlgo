#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//FUNCTION FOR CONVERSION OF DECIMAL NUMBER TO OCTAL NUMBER
decitooctal(long long int n)
{
  long long int num=0;
  int digit =0;
  int p=1;
  int x;
  while(n)
     {
           x=n%8;
           n/=8;
           digit=x*p;
           num=num+digit;
           p*=10;
     }
  cout<<"\n The Required Octal Number is::"<<num;
}
int main()
{
  long long int decimal;
  cout<<"\n Enter The Decimal Number:";
  cin>>decimal;
  decitooctal(decimal);
  return 0;
}

/*
  INPUT::15635
  OUTPUT::36423

  INPUT::100
  OUTPUT::144

  INPUT::256
  OUTPUT::400

  Time Complexity- O(n);
  Space Complexity- O(1);

*/
