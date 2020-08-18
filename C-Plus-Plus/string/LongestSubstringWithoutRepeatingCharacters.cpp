#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LongestSubsequenceWithoutRepratingCharacter(string s)
{

  vector<int> prev(256, -1);
  int i = 0, res = 0;
  for (int j = 0; j < s.length(); j++)
  {
    i = max(i, prev[s[j]] + 1);
    int maxEnding = j - i + 1;
    res = max(res, maxEnding);
    prev[s[j]] = j;
  }
  return res;
}