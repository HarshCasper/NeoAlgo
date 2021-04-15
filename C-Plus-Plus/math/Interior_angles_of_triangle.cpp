/*
INTERIOR ANGLES OF A TRIANGLE
A triangle is valid only if the sum of
any 2 sides is greater than the 3rd side

The interior angles of a valid triangle
of sides a,b,c can be found using the formula:
alpha= cos^-1(b^2+c^2-a^2)/2bc

*/
#include<bits/stdc++.h>

using namespace std;

//to validate triangle
bool validate(int a, int b, int c)
{
    // check condition
    if (a + b <= c ||  b + c <= a || a + c <= b)
        return false;
    else
        return true;
}

void interior_angles(int a,int b, int c ){
    //angles in radian
    float alpha = acos((b*b + c*c - a*a)/float((2*b*c)));
    float beta = acos(((a*a) + (c*c) - (b*b))/float((2*a*c)));
    float gamma = acos((a*a + b*b - c*c)/float((2*a*b)));

    // angles in  degree
    alpha*= 180 / 3.1415926535;
    beta*= 180 / 3.1415926535;
    gamma*= 180 / 3.1415926535;

    // to print all the angles
    cout << "\nSolving interior angles\n";
    cout << "alpha : " << alpha << " degrees" <<endl;
    cout << "beta : " << beta << " degrees" <<endl;
    cout << "gamma : " << gamma << " degrees" <<endl;
}



// Driver function
int main()
{
    int a , b , c ;
     cout << "Enter the 3 sides of the triangle: ";
     cin >> a >> b >> c;
    if (validate(a, b, c)){
        cout << "Valid triangle\n";
        interior_angles(a,b,c);
    }
    else
        cout << "Invalid triangle";
}
/*
SAMPLE I/O:
Enter the 3 sides of the triangle: 5 12 13
Valid triangle

Solving interior angles
alpha : 22.6199 degrees
beta : 67.3801 degrees
gamma : 90 degrees

Time Complexity:O(1)
Space complexity: O(1)
*/
