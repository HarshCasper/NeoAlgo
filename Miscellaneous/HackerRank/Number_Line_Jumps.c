/* NUMBER LINE JUMPS
    given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).
    The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
    The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
    If both kangaroos can be at the same location at the same time as part of the show,return YES,otherwise return NO.
*/

#include <stdio.h>

/*
    kangaroo has the following parameter(s):
    * int x1, int v1: starting position and jump distance for kangaroo 1
    * int x2, int v2: starting position and jump distance for kangaroo 2
    Returns:
    string: either YES or NO
*/

char *kangaroo(int x1, int v1, int x2, int v2)
{
    int i = 0, flag = 0;
    for (i = 0; i < 1000000; i++)
    {
        //If starting point of one is less than and jump distance of the same is greater than the other
        if ((x1 <= x2 && v1 >= v2) || (x1 >= x2 && v1 <= v2))
        {
            //if the kangaroos are are at the same position
            if ((x1 + i * v1) == (x2 + i * v2))
            {
                return "YES";
                flag = 0;
                 break;
            }
            else
            {
                flag = 1;
            }
        }
        else
        {
            return "NO";
            break;
        }
    }
    //If the kangaroos cannot be at the same position
    if (flag == 1)
        return "NO";
    return NULL;
}

//driver code
int main()
{
  //accept the starting locations and jump distances as user input
  int x1, v1, x2, v2;
  scanf("%d %d %d %d", &x1, &v1, &x2, &v2);
  printf("%s", kangaroo(x1, v1, x2, v2));
}

/*
    Sample Input:
    0 3 4 2
    Sample Output:
    YES

    Time Complexity: O(n)
    Space complexity: O(1)
*/
