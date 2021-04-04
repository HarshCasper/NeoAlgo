#include<bits/stdc++.h>
using namespace std;

//CONVERSION OF DECIMAL NUMBER TO HEXADECIMAL NUMBER
void decimal_to_hexadecimal(int n)
{
  int i=0;
  string ans="";
  int last_digit=0;
  char x;
  while(n)
  {
    last_digit=n%16;
    n=n/16;
    /*  Condition checking :
        If digit greater than 9, X will be alphabet
        Else X will be a number  */
    if(last_digit>9)
       x=last_digit+'A'-10;
    else
      x=last_digit+'0';
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
  decimal_to_hexadecimal(decimal);
  return 0;
}

/* Testcases:

  INPUT-
  ENTER THE DECIMAL NUMBER::463
  OUTPUT-
  The Required Hexadecimal Number is::1CF

  INPUT-
  ENTER THE DECIMAL NUMBER::100
  OUTPUT-
  The Required Hexadecimal Number is::64

  INPUT-
  ENTER THE DECIMAL NUMBER::516042
  OUTPUT-
  The Required Hexadecimal Number is::7DFCA

  Time Complexity- O(n);
  Space Complexity- O(1);

*/
