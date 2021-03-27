#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//FUNCTION FOR CONVERSION OF OCTAL NUMBER TO DECIMAL NUMBER
octaltodeci(long long int n)
{
  long long int num=0;
  int digit =0;
  int p=0;
  int number=0;
  int x;
  while(n)
  {
     x=n%10;
     n=n/10;
     digit=x*pow(8,p);
     num=num+digit;
     p++;
  }
  cout<<"\n The Required Decimal Number is::"<<num;
}
int main()
{
  long long int octal;
  cout<<"\n Enter The Octal Number::";
  cin>>octal;
  octaltodeci(octal);
  return 0;
}

/*
  INPUT::512
  OUTPUT::330

  INPUT::964674
  OUTPUT::321980

  INPUT::137
  OUTPUT::95

  Time Complexity- O(n);
  Space Complexity- O(1);

*/
