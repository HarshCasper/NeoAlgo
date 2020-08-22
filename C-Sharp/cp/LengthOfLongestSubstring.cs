public class Solution
{
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