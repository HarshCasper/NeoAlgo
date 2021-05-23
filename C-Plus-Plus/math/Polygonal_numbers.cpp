/*
    Polygonal numbers are non-negative integers constructed and represented by geometrical
    arrangements of equally spaced points that form regular polygons.
    It is given by: P(s,n)=(s-2)n(n-1)/2 +n
                    where s is no of sides in a polygon
                          P(s,n) is nth s-gonal number
    
    This program will print the polygonal numbers upto nth term.        
*/

#include <iostream>
using namespace std;

// Function to generate nth s-gonal number
int nth_sgonal(int s,int n)
{
    return((s-2)*n*(n-1)/2+n);
}

int main()
{
    int s,n;
    cout << "Enter the number of sides in polygon:";
    cin >> s;
    cout << "Enter number of terms to generate:";
    cin >> n;

    //Printing polygonal numbers upto n terms
    cout << n<<" Polygonal numbers with " << s << " sides are:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << nth_sgonal(s,i) << " ";
    }
}

/*

Sample Input/Output:

Input:
Enter the number of sides in polygon:5
Enter number of terms to generate:7

Output:
7 Polygonal numbers with 5 sides are:
1 5 12 22 35 51 70

Time Complexity:O(n) where n is number of terms
Space Complexity:O(1)

*/
