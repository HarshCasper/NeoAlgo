#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//Function for conversion of hexadecimal number to decimal number
void hexatodeci(string s)
{
  int num=0;
  int digit=0;
  int p=0;
  int x;
  int sz=s.size();
  //Traverse the elements of the string
  for(int i=sz-1;i>=0;i--)
  {
     if(s[i]>='A'&&s[i]<='Z')
        x=s[i]-'A'+10;
     else if(s[i]>='a'&&s[i]<='z')
        x=s[i]-'a'+10;
     else if(s[i]>='0'&&s[i]<='9')
        x=s[i]-'0';
     x=x*pow(16,p);
     num=num+x;
     p++;
  }
  cout<<"\n The Required Decimal Number is::"<<num;
}
int main()
{
  string hexadeci;
  cout<<"\n ENTER THE HEXADECIMAL NUMBER::";
  cin>>hexadeci;
  hexatodeci(hexadeci);
  return 0;
}

/*
  INPUT::1CF
  OUTPUT::463

  INPUT::64CFB
  OUTPUT::412923

  INPUT::536BA
  OUTPUT::341690

  Time Complexity- O(sz);
  Space Complexity- O(1);

*/
