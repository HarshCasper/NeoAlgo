/*
Each cell is represented by either

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges

Only a fresh orange adjacent to a rotten one will get rotten after 1 second.
*/

#include <bits/stdc++.h>
using namespace std;

// A struct data type for storing each and every cell index pairs
struct cell
{
	int x, y;
};

// Checks if the index in consideration is valid or not
bool isValid(int x, int y, int R, int C)
{
	return (x >= 0 && x < R && y >= 0 && y < C);
}

// Checks if there are still some fresh oranges left
bool checkall(vector <int> arr[], int R)
{
	int C = arr[0].size();
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (arr[i][j] == 1)
				return true;
	return false;
}

// A checker to take care of all corner case. In case the matrix is all zero then this checker takes care of such cases
bool checkzero(vector <int> arr[], int R)
{
	int C = arr[0].size();
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (arr[i][j] != 0)
                return false;
    return true;
}

int rotOranges(vector <int> arr[], int R)
{
	queue <cell> q;
	cell curr;
	int time = -1, lsize, x, y, i, j;
	int xindex[] = {1, -1, 0, 0};
	int yindex[] = {0, 0, 1, -1};
	int C = arr[0].size();
	
	for (i=0; i < R; i++)
		for (j=0; j < C; j++)
			if (arr[i][j] == 2)
				q.push({i, j});

	while (!q.empty())
	{
		time++;
		lsize = q.size();
		
		while (lsize--)
		{
			curr = q.front();
			q.pop();
			
			for (int i=0; i < 4; i++)
			{
				x = curr.x + xindex[i];
				y = curr.y + yindex[i];
				
				if (!isValid(x, y, R, C))
					continue;
				
				if (arr[x][y] == 1)
				{
					arr[x][y] = 2;
					q.push({x, y});
				}
			}
		}
	}
	
	if (checkzero(arr, R))
		return 0;
	
	if (checkall(arr, R))
		return -1;
	return time;
}

int main()
{
	int R, C, num;
	
	cout << "Enter number of rows and columns: ";
	cin >> R >> C;
	
	vector <int> arr[R];
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << "\nEnter number : ";
			cin >> num;
			arr[i].push_back(num);
		}
	}
	
	int ans = rotOranges(arr, 3);
	if (ans != -1)
		cout << "\nThe time taken is " << ans << " seconds.";
    else
		cout << "\nAll the oranges cannot be rotten !!";
	
    return 0;
}

/*
Row = 3
Column = 5

Time t = 0

	2, 1, 0, 2, 1
	1, 0, 1, 2, 1
	1, 0, 0, 2, 1

Time t = 1

	2, 2, 0, 2, 2
	2, 0, 2, 2, 2
	1, 0, 0, 2, 2

Time t = 2

	2, 2, 0, 2, 2
	2, 0, 2, 2, 2
	2, 0, 0, 2, 2

All oranges are rotten. Time taken is 2 seconds.
*/
