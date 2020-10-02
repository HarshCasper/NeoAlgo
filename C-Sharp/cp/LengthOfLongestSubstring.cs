public class Solution
{
	/*

	Given a string, return the length of the longest substring WITHOUT repeating characters.

	Samples...
	Example 1:
		Input: "abcabcbb"
		Output: 3
		Explanation: The answer is "abc", with the length of 3.

	Example 2:
	    Input: "bbbbb"
	    Output: 1
	    Explanation: The answer is "b", with the length of 1.

	Example 3:
	    Input: "pwwkew"
	    Output: 3
	    Explanation: The answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

	Algorithm complexity analysis:
	This is the sliding window solution for the 'Longest Substring without Repeating Characters' problem, which is far more efficient than the naive brute force approach.

	Time complexity: O(n), where n is the length of the input string.
	Space complexity: O(k), where k is the number of unique characters in the input string.

	*/

	public int LengthOfLongestSubstring(string s)
	{
		// pointers to the substring without duplicating characters
		int left = 0, right = -1;
		// length of the longest substring
		int longest_length = 0;
		// dictionary (HashMap) for storing indices of characters in the string
		Dictionary<char, int> d = new Dictionary<char, int>();


		for (int i = 0; i < s.Length; i++)
		{
			// get current char from string
			char c = s[i];

			// check if the char is already present in dictionary's keys. If not, then, add the character into our longest substring (by updating the right pointer to our sliding window)

			// If yes, then, check if the char is part of our CURRENT longest substring. If not, then, add the character into our longest substring
			if ((!d.ContainsKey(c)) || (d[c] < left))
			{
				d[c] = i;
				right += 1;
			}
			else
			{
				// If a repeating char is encountered, then update the left pointer to our current sliding window that tracks the current longest substring
				left = d[c] + 1;
				right += 1;
				d[c] = i;
			}

			// length of the current sliding window
			int length = (right - left) + 1;
			if (length > longest_length)
			{
				// update longest_length so far
				longest_length = length;
			}

		}

		return longest_length;
	}
}
