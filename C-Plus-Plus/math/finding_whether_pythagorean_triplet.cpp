/* C++ program to find whether the given numbers form a pythagoras triplet or not
   In this program user will provide 3 integer input and the program will check whether the given input is pythagorean triplet or not. 
   pythagoras formula => (height^2) + (base^2) = (hypotenuse^2)
   */
   
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int side_1,side_2,side_3;
     // where side_1,side_2 and side_3 are the three sides of the triangle
     cout<<"Enter three sides of the triangle :";
     cin>>side_1>>side_2>>side_3;
     int m = max(side_1,side_2);
     m = max(m, side_3);
     /* calling in-built max function to get the largest side of triangle as largest side is the hypotenuse */
     if(m==side_1)
     {
         if((side_1*side_1) == ((side_2*side_2)+(side_3*side_3)))
         {
             cout<<"It is a pythagoras triplet";
         }
         else
         {   
             cout<<"It is not a pythagoras triplet";
         }
     }
     else if(m==side_2)
     {
         if((side_2*side_2) == ((side_1*side_1)+(side_3*side_3)))
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
         if((side_3*side_3) == ((side_2*side_2)+(side_1*side_1)))
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
/* SAMPLE
Testcase 1
INPUT   5 3 4
OUTPUT  It is a pythagoras triplet
Testcase 2
INPUT   5 6 2
OUTPUT  It is not a pythagoras triplet  
Time Complexity is O(1)  
Space Complexity is O(1)   */
