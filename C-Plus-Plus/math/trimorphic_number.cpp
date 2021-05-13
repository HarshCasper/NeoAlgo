/* 
 *  In this program we have to tell whether a given number
    is trimorphic or not.
 *  A trimorphic number is a number whose cube's last digit 
    is equal to the last digit of the number itself.
 *   For Ex:  
            If number=10
                cube=1000
             Since last digit to 1000 and 10 both are 0. 
             Therefore, 10 is a Trimorphic number.
 */

 #include<iostream>
 using namespace std;
 int main()
 {
     int n,c;
     cout<<"Enter the Number\n";
     cin>>n;

     //c is assigned as the cube of the given number
     c=n*n*n;

     /* The last digit of a number is the remainder left behind when the
         number is divided by 10 and % operation is used to find the remainder 
         obtained when one number is divided by the other.*/
     //This if condition checks if both n and c have same last digits
     if((n%10)==(c%10))
         cout<<"The given number is Trimorphic";
     else
         cout<<"The given number is not Trimorphic";
     return 0;
 }

 /*     TEST CASES
     
     1)Input: 
             Enter the Number
             20
     2)Output:
             The given number is Trimorphic
     
      1)Input: 
             Enter the Number
             2
     2)Output:
             The given number is not Trimorphic

     Time Complexity:O(1)
     Space Complexity:O(1)

 */
