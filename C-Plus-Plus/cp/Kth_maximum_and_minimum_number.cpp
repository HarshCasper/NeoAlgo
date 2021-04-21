/* This program finds the k-th maximum and minimum number from an array.
* Problem Statement: Given a set of array elements, and a number k, we need to find out k-th maximum and minimum number from the array.
* Approach used: Priority queue has been to find out the k-th times maximum and minimum number.
                 Max-heap has been used to find the maximum value.
                 Min-heap has been used to find the minimum value.
                 Sets have also been used to prevent duplicate numbers.
*Time Complexity: o(n log k)
*Space Complexity: o(k) */

#include <iostream>
#include<queue>
#include<set>


using namespace std;

//The function to calculate the k-th maximum value
void maxheap(priority_queue<int> max_min, int k)
{
    int ans,i = 1;
    priority_queue<int> p = max_min ;
    while(!p.empty())
    {
        //If the value of k equals to the counter i, the array value is stored as the ans
        //which is the required output
        if(i == k)
        {
            ans = p.top();
            break;
        }
        i++;
        p.pop();
    }

  //The k-th largest value is printed
  cout << "The k-th largest value " << ans << endl;
}

//The function to calculate the k-th minimum value
void minheap(priority_queue<int ,vector<int>, greater<int> > max_min, int k)
{
    priority_queue<int, vector<int>, greater<int> > p = max_min;
    int ans, i = 1;
    while(!p.empty())
    {
        //If the value of k equals to the counter i, the array value is stored as the ans
        //which is the required output
        if(i == k)
        {
            ans = p.top();
            break;
        }
        p.pop();
        i++;
    }

    //The k-th smallest value is printed
    cout << "The k-th smallest number is " << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Taking the number of test cases as input
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,k;

        //Taking the size of the array as input
        cout << "Enter the size " << endl;
        cin >> n;

        //Taking the value of k as input
        cout << "Enter value of k " << endl;
        cin >> k;

        //Taking the array as input and declaring the sets
        set<int> s;
        set<int>::iterator it;
        int a[n];
        cout << "Enter the values of the array " << endl;

        for(int i=0;i<n;i++)
            {
                int v;
                cin >> v;
                s.insert(v);
            }

        //Declaring the max-heap
        priority_queue<int> largest;

        //Declaring the min-heap
        priority_queue<int, vector<int>, greater<int> > smallest;

        //Pushing the array values in the queue
        for(it = s.begin(); it != s.end(); it++)
        {
            largest.push(*it);
            smallest.push(*it);
        }

        //Calling the functions to calculate the k-th max-value and min-value respectively
        maxheap(largest, k);
        minheap (smallest, k);
    }
    return 0;
}

/* A sample test case for the above problem is:

Input:
1
Enter the size 5
Enter the value of k 3
Enter the values of the array 1 2 3 4 5

Output:
The k-th largest value 3
The k-th smallest value 3
*/
