/*Find the largest rectangular area possible in a given histogram where the largest rectangle can be made 
of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.
*/
#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n)
{
	stack<int> s;

	int max_area = 0;
	int tp; 
	int area_with_top; 
					
	int i = 0;
	while (i < n)
	{
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		else
		{
			tp = s.top();
			s.pop(); 
			area_with_top = hist[tp] * (s.empty() ? i :i - s.top() - 1);
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i :i - s.top() - 1);

		if (max_area < area_with_top)
            max_area = area_with_top;
	}

	return max_area;
}

int main()
{
    int n;
    cin>>n;
    int hist[n];
    for(int i=0;i<n;i++)
        cin>>hist[i];

	cout << "Maximum area is " << getMaxArea(hist, n);
	return 0;
}

/*
INPUT:
n=7

hist[n]={6, 2, 5, 4, 5, 1, 6}

OUTPUT:Maximum area is 12

Code Complexity: O(n)

*/

