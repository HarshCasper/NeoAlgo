#include<iostream>
using namespace std;

//FUNCTION FOR PRINTING FLOYD'S TRIANGLE
void floydstriangle(int n)
{ int x=1;
  int i,j;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<i;j++)
             cout<<x++<<" ";
             cout<<endl;
  }
}
//FUNCTION FOR PRINTING HOLLOW BUTTERFLY
void hollowbutterfly(int n)
{ int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<2*n;j++)
    {
      if(j==0||j==(2*n-1))
         cout<<"*";
      else if(j==i||j==(2*n-i-1))
         cout<<"*";
           else
             cout<<" ";
    }
  cout<<endl;
  }
  for(i=n-1;i>=0;i--)
  {
    for(j=0;j<2*n;j++)
    {
      if(j==0||j==(2*n-1))
        cout<<"*";
      else if(j==i||j==(2*n-i-1))
        cout<<"*";
      else
        cout<<" ";
    }
  cout<<endl;
  }
}
//FUNCTION FOR PRINTING SOLID BUTTERFLY
void solidbutterfly(int n)
{ int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<2*n;j++)
    {
      if(j<=i||j>=(2*n-i-1))
         cout<<"*";
      else
         cout<<" ";
    }
    cout<<endl;
  }
  for(i=n-1;i>=0;i--)
  {
    for(j=0;j<2*n;j++)
    {
      if(j<i||(j>=2*n-i))
         cout<<"*";
      else
         cout<<" ";
    }
  cout<<endl;
  }
}
//FUNCTION FOR PRINTING HOLLOW RECTANGLE
void hollowrectangle(int l,int b)
{
  for(int i=0;i<b;i++)
  {
    for(int j=0;j<l;j++)
    {
      if(i==0||i==(b-1))
         cout<<"X";
      else if(j==0||j==(l-1))
         cout<<"X";
           else
             cout<<" ";
    }
      cout<<endl;
  }
}
//FUNCTION FOR PRINTING HOLLOW PARALLEOGRAM
void hollowllgm(int l,int b)
{
  int i,j;
  for(i=b;i>0;i--)
  {
    for(j=0;j<i-1;j++)
       cout<<" ";
    for(j=0;j<l;j++)
      { if(i==1||i==b)
          cout<<"*";
        else if(j==0||j==l-1)
         cout<<"*";
        else
         cout<<" ";
      }
    cout<<endl;
  }
}
//FUNCTION FOR PRINTING SOLID PARALLEOGARM
void solidllgm(int l,int b)
{
  int i,j;
  for(i=b;i>0;i--)
  {
    for(j=0;j<i-1;j++)
       cout<<" ";
    for(j=0;j<l;j++)
      cout<<"*";
    cout<<endl;
  }
}
//FUNCTION FOR PRINTING HOLLOW DIAMOND
void hollowdiamond(int n)
{ int i,j;
  for(i=0;i<n;i++)
  {
    for(j=1;j<2*n;j++)
    {
      if(j+i==n||j-i==n)
         cout<<"*";
     else
         cout<<" ";
    }
  cout<<endl;
  }
  for(i=1;i<n;i++)
  {
    for(j=0;j<2*n-1;j++)
    {
      if(j==i||i+j==(2*n-2))
        cout<<"*";
      else
        cout<<" ";
    }
  cout<<endl;
  }
}
//FUNCTION FOR PRINTING SOLID DIAMOND
void soliddiamond(int n)
{ int i,j;
  for(i=0;i<n;i++)
  {
    for(j=n-1;j>i;j--)
      cout<<" ";
    for(j=0;j<2*i+1;j++)
      cout<<"*";
    cout<<endl;
  }
  for(i=n-1;i>0;i--)
  {
    for(j=n;j>i;j--)
      cout<<" ";
    for(j=0;j<2*i-1;j++)
      cout<<"*";
    cout<<endl;
  }
}
//FUNCTION FOR FINDING FACTORIAL
int fact(int n)
{ int factorial=1;
  for(int i=1;i<=n;i++)
      factorial*=i;
  return factorial;
}
//FUNCTION FOR PRINTING PASCAL TRIANGLE
void pascaltriangle(int n)
{ int i,j;
  for(i=0;i<n;i++)
  {
    for(j=i;j<n;j++)
      cout<<" ";
    for(j=0;j<=i;j++)
      cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
    cout<<endl;
  }
}
//FUNCTION FOR PRINTING PALINDROME PATTERN
void pallindromepattern(int n)
{ int i,j;
  for(i=1;i<=n;i++)
  {
    for(j=5;j>=1;j--)
    {
      if(i<j)
         cout<<" ";
      else
         cout<<j;
    }
    for(j=1;j<i;j++)
    {
      if(j<i)
      cout<<j+1;
    }
  cout<<endl;
  }
}

//MAIN FUNCTION
int main()
{
  int choice;
  int ch;
  int n,l,b;
  start:
  cout<<"\n PATTERN PROBLEMS::"<<endl;
  cout<<"\n 1. FLOYD'S TRIANGLE ";
  cout<<"\n 2. HOLLOW BUTTERFLY ";
  cout<<"\n 3. SOLID BUTTERFLY ";
  cout<<"\n 4. HOLLOW RECTANGLE ";
  cout<<"\n 5. HOLLOW PARALLELOGRAM ";
  cout<<"\n 6. SOLID PARALLEOGRAM ";
  cout<<"\n 7. HOLLOW DIAMOND ";
  cout<<"\n 8. SOLID DIAMOND ";
  cout<<"\n 9. PASCAL TRIANGLE ";
  cout<<"\n 10.PALINDROME PATTERN "<<endl;
  cout<<"\n ENTER YOUR CHOICE NUMBER:::";
  cin>>choice;
  switch(choice)
  {
    case 1:
            cout<<"\n ENTER THE VALUE OF N::";
            cin>>n;
            cout<<endl;
            floydstriangle(n);
            break;
    case 2:
            cout<<"\n ENTER THE VALUE OF N::";
            cin>>n;
            cout<<endl;
            hollowbutterfly(n);
            break;
    case 3:
            cout<<"\n ENTER THE VALUE OF N::";
            cin>>n;
            cout<<endl;
            solidbutterfly(n);
            break;
    case 4:
            cout<<"\n ENTER THE LENGTH OF THE RECTANGLE::";
            cin>>l;
            cout<<"\n ENTER THE BREADTH OF THE RECTANGLE::";
            cin>>b;
            cout<<endl;
            hollowrectangle(l,b);
            break;
    case 5:
            cout<<"\n ENTER THE VALUE OF BASE AND SLANT HEIGHT OF PARALLEOGRAM::";
            cin>>l>>b;
            cout<<endl;
            hollowllgm(l,b);
            break;
    case 6:
            cout<<"\n ENTER THE VALUE OF BASE AND SLANT HEIGHT OF PARALLEOGRAM::";
            cin>>l>>b;
            cout<<endl;
            solidllgm(l,b);
            break;
    case 7:
            cout<<"\n ENTER THE VALUE OF N::";
            cin>>n;
            cout<<endl;
            hollowdiamond(n);
            break;
    case 8:
            cout<<"\n ENTER THE VALUE OF N::";
            cin>>n;
            cout<<endl;
            soliddiamond(n);
            break;
    case 9:
            cout<<"\n ENTER THE VALUE OF N::";
            cin>>n;
            cout<<endl;
            pascaltriangle(n);
            break;
    case 10:
            cout<<"\n ENTER THE VALUE OF N::";
            cin>>n;
            cout<<endl;
            pallindromepattern(n);
            break;
    default:
            cout<<"\n YOUR HAVE ENTERED WRONG CHOICE...";
            break;
  }
  cout<<"\n DO YOU WANT TO RUN AGAIN(YES/NO) ?? "<<endl;
  cout<<"\n -> ENTER '1' FOR YES";
  cout<<"\n -> ENTER '0' FOR NO"<<endl;
  cin>>ch;
  if(ch==1)
     { system("CLS");
       goto start;
     }
  return 0;
}
