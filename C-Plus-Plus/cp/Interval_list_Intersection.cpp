/*
You are given two lists of closed 
intervals,firstList and secondList,
where firstList[i] = [starti, endi]
and secondList[j] = [startj, endj].
Each list of intervals is pairwise
disjoint and in sorted order.Return
the intersection of these two inte-
-rval lists.The intersection of two
closed intervals is a set of real
numbers that are either empty or 
represented as a closed interval.
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> IntervalList(int I1, int J1, int I2, int J2)
{
    vector<int> U;
    if (J2 == I1) {
        U.push_back(J2);
        U.push_back(J2);
        return U;
    }
    if ((I2 < I1) && (J2 > I1) && (J2 < J1)) {
        U.push_back(I1);
        U.push_back(J2);
        return U;
    }
    if ((I2 >= I1) && (J2 <= J1)) {
        U.push_back(I2);
        U.push_back(J2);
        return U;
    }
    if ((I2 > I1) && (J2 >= J1) && (I2 < J1)) {
        U.push_back(I2);
        U.push_back(J1);
        return U;
    }
    if ((I1 >= I2) && (J1 <= J2)) {
        U.push_back(I1);
        U.push_back(J1);
        return U;
    }
    if (J1 == I2) {
        U.push_back(J1);
        U.push_back(J1);
        return U;
    }
    return U;
}
vector<vector<int> > intervalIntersection(
    vector<vector<int> >& firstList,
    vector<vector<int> >& secondList)
{
    int X, Y, i, j, I1, J1, I2, J2;
    X = firstList.size();
    Y = secondList.size();
    vector<vector<int> > Ans;
    if ((X == 0) || (Y == 0))
        return Ans;
    I1 = firstList[0][0];
    J1 = firstList[0][1];
    I2 = secondList[0][0];
    J2 = secondList[0][1];
    i = 0;
    j = 0;
    while ((i < X) && (j < Y)) {
        vector<int> U = IntervalList(I1, J1, I2, J2);
        if (U.size() != 0) {
            Ans.push_back(U);
        }
        if (J1 < J2) {
            ++i;
            if (i < X) {
                I1 = firstList[i][0];
                J1 = firstList[i][1];
            }
        }
        else if (J1 == J2) {
            ++i;
            if (i < X) {
                I1 = firstList[i][0];
                J1 = firstList[i][1];
            }
            ++j;
            if (j < Y) {
                I2 = secondList[j][0];
                J2 = secondList[j][1];
            }
        }
        else {
            ++j;
            if (j < Y) {
                I2 = secondList[j][0];
                J2 = secondList[j][1];
            }
        }
    }
    return Ans;
}
int main()
{    
    int N, i, S, E, M;
    cout << "Enter the size of first list : ";
    cin >> N;
    vector<vector<int> > firstList;
    for (i = 0; i < N; i++) {
        vector<int> Temp;
        cin >> S >> E;
        Temp.push_back(S);
        Temp.push_back(E);
        firstList.push_back(Temp);
    }
    cout << "Enter the size of second list : ";
    cin >> M;
    vector<vector<int> > secondList;
    for (i = 0; i < M; i++) {
        vector<int> Temp;
        cin >> S >> E;
        Temp.push_back(S);
        Temp.push_back(E);
        secondList.push_back(Temp);
    }
    cout << "The Intersection of given two list : " << endl;
    vector<vector<int> > IntersectingList = intervalIntersection(firstList, secondList);
    for (i = 0; i < IntersectingList.size(); i++)
        cout << IntersectingList[i][0] << " " << IntersectingList[i][1] << endl;
    return 0;
}

/*
Time Complexity: O(N + M)
Space Complexity: O(M + N)
where N and M are the size of first
and second List respectively.

Sample Input 
Enter the size of first list :
4
0 2
5 10
13 23
24 25
Enter the size of second list : 
4
1 5
8 12
15 24
25 26

Output 
The Intersection of given two list :
1 2
5 5
8 10
15 23
24 24
25 25
*/
