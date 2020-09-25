const searchPattern = (text, pattern) => {
  let concatNewStr = pattern + "$" + text;
  let zArr = [];

  //get the z array
  getZarr(concatNewStr, zArr);

  // looping to find the array locations
  for (let i = 0; i < zArr.length; i++) {
    if (zArr[i] == pattern.length) {
      console.log("Found pattern at index " + (i - pattern.length - 1));
    }
  }
};
const getZarr = (str, zArr) => {
  let n = str.length;

  // [left,right] make a window which matches with prefix of s
  let left = 0,
    right = 0;

  for (let i = 1; i < n; ++i) {
    // if i>right nothing matches
    if (i > right) {
      left = right = i;

      // right-left = 0 in starting, so it will start checking from 0'th index.
      while (right < n && str.charAt(right - left) == str.charAt(right)) {
        right++;
      }

      zArr[i] = right - left;
      right--;
    } else {
      // k = i-left so k corresponds to number which matches in [left,right] interval.
      let k = i - left;

      // if zArr[k] is less than remaining interval then zArr[i] will be equal to zArr[k].
      if (zArr[k] < right - i + 1) {
        zArr[i] = zArr[k];
      } else {
        // else start from right and check manually
        left = i;
        while (right < n && str.charAt(right - left) == str.charAt(right)) {
          right++;
        }
        zArr[i] = right - left;
        right--;
      }
    }
  }
};

searchPattern("AABAACAADAABAABA", "AABA");

/*
Output:
Found pattern at index 0
Found pattern at index 9
Found pattern at index 12

Time complexity and Space complexity: O(m + n), length of text be n and of pattern be m
*/
