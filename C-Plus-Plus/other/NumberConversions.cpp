#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//CONVERSION OF NUMBER FROM X1 FORM TO X2 FORM
void x1tox2(int n,int x1,int x2)
{
  int num=0;
  int digit =0;
  int p=0;
  int number=0;
  int x;
  while(n)
  {
     x=n%x2;
     n=n/x2;
     digit=x*pow(x1,p);
     num=num+digit;
     p++;
  }
  if(x2<x1)
     num=num+1;
  cout<<"\n The Required Answer is::"<<num;
}

//CONVERSION OF HEXADECIMAL NUMBER TO DECIMAL NUMBER
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
  cout<<"\n The Required Answer is::"<<num;
}

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
  cout<<"\n The Required Answer is::";
  for(int k=i-1;k>=0;k--)
    cout<<ans[k];
}

int main()
{
  int n;
  int choice;
  string hexadeci;
  start:
  //MENU DRIVEN CODE
  cout<<"\n MENU DRIVEN::";
  cout<<"\n 1.Binary To Decimal";
  cout<<"\n 2.Octal to Decimal";
  cout<<"\n 3.Hexadecimal to Decimal";
  cout<<"\n 4.Decimal to Binary";
  cout<<"\n 5.Decimal to Ocatl";
  cout<<"\n 6.Decimal to Hexadecimal";
  cout<<"\n\n ENTER YOUR CHOICE::::";
  cin>>choice;
  switch(choice)
  {
    case 1: cout<<"\n ENTER THE BINARY NUMBER::";
            cin>>n;
            x1tox2(n,2,10);
            break;
    case 2: cout<<"\n ENTER THE OCTAL NUMBER::";
            cin>>n;
            x1tox2(n,8,10);
            break;
    case 3: cout<<"\n ENTER THE HEXADECIMAL NUMBER::";
            cin>>hexadeci;
            hexatodeci(hexadeci);
            break;
    case 4: cout<<"\n ENTER THE DECIMAL NUMBER::";
            cin>>n;
            x1tox2(n,10,2);
            break;
    case 5: cout<<"\n ENTER THE DECIMAL NUMBER::";
            cin>>n;
            x1tox2(n,10,8);
            break;
    case 6: cout<<"\n ENTER THE DECIMAL NUMBER::";
            cin>>n;
            decitohexa(n);
            break;
    default: cout<<"\n YOU HAVE ENTERED WRONG CHOICE!!!";
            break;
    }

    cout<<"\n Do you Want to run again?(0/1)::";
    cout<<"\n Press '1' to continue";
    cout<<"\n Press '0' for Exit";
    cout<<"\n Enter your choice:::";
    int ch;
    cin>>ch;
    if(ch==1)
        { system("CLS");
          goto start;
        }
    return 0;
}
//End of Program
