#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//CONVERSION OF DECIMAL NUMBER TO HEXADECIMAL NUMBER
void decitohexa(int n)
{
  int i=0;
  char ans[20];
  int digit=0;
  char x;
  while(n)
  {
    digit=n%16;
    n=n/16;
    /*  Condition checking :
        If digit greater than 9, X will be alphabet
        Else X will be a number  */
    if(digit>9)
       x=digit+'A'-10;
    else
      x=digit+'0';
    ans[i]=x;
    i++;
  }
  //Loop for printing reverse String
  cout<<"\n The Required Hexadecimal Number is::";
  for(int k=i-1;k>=0;k--)
    cout<<ans[k];
}
int main()
{
  int decimal;
  cout<<"\n ENTER THE DECIMAL NUMBER::";
  cin>>decimal;
  decitohexa(decimal);
  return 0;
}

/*
  INPUT::463
  OUTPUT::1CF

  INPUT::100
  OUTPUT::64

  INPUT::516042
  OUTPUT::7DFCA

  Time Complexity- O(n);
  Space Complexity- O(1);

*/
