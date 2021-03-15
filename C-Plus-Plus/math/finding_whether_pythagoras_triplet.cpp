/* C++ program to find whether the given numbers form a pythagoras triplet or not
   In this program user will provide 3 integer input and the program will check whether the given input is pythagorian triplet or not. */
   
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b, int c)
{   // function to check the largest number among the three numbers given
    if(a>=b && a>=c)
    return a;
    else if(b>=a && b>=c)
    return b;
    else
    return c;
}
int main()
{
     int a,b,c;
     cin>>a>>b>>c;
     int m=max(a,b,c);
     /* calling max function to get the largest side of triangle as largest side is the hypotenuse
        after finding the hypotenuse formula is ((a^2 + b^2) = c^2) where c is the largest side. */
     if(m==a)
     {
         if((a*a) == ((b*b)+(c*c)))
         {
             cout<<"It is a pythagoras triplet";
         }
         else
         {   
             cout<<"It is not a pythagoras triplet";
         }
     }
     else if(m==b)
     {
         if((b*b) == ((a*a)+(c*c)))
         {
             cout<<"It is a pythagoras triplet";
         }
         else
         {   
             cout<<"It is not a pythagoras triplet";
         }
     } 
     else
     {
         if((c*c) == ((a*a)+(b*b)))
         {
             cout<<"It is a pythagoras triplet";
         }
         else
         {   
             cout<<"It is not a pythagoras triplet";
         }
     } 
     return 0;
}