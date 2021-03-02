#include <bits/stdc++.h>
using namespace std;

void getZ(string s, int z[])
{
	int n = s.size();
	int left = 0, right = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i > right)
		{
			left = right = i;
			while (right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left;
			right--;
		}
		else
		{
			int k = i - left;
			if (z[k] < right - i + 1)
			{
				z[i] = z[k];
			}
			else
			{
				left = i;
				while (right < n && s[right - left] == s[right])
					right++;
				z[i] = right - left;
				right--;
			}
		}
	}
}

int main()
{
	string text, pattern;
	cout << "Enter the text: ";
	cin >> text;
	cout << "Enter the pattern: ";
	cin >> pattern;
	string concat = pattern + "$" + text;
	int n = concat.size();
	int m = pattern.size();
	int z[n];
	getZ(concat, z);
	for (int i = 0; i < n; ++i)
	{
		if (z[i] == m)
		{
			cout << "Pattern found at index " << i - m - 1 << "\n";
		}
	}
	return 0;
}

/*
Time Complexity: O(length of text + length of pattern)

Input
Enter the text: AABACAAFGAABAABA
Enter the pattern: AABA

Output
Pattern found at index 0
Pattern found at index 9
Pattern found at index 12
*/
