const findPalindrome = (str) => {
  sequence = processString(str);

  // array for holding the palindromic sequence around every center
  let positions = [];
  let start = 0;
  let end = 0;

  // i is our current center
  for (let i = 0; i < sequence.length;) {

      // we check on both sides of i till where we can find same letters on 2
      // positions
      while (start > 0 && end < sequence.length - 1 && sequence[start - 1] === sequence[end + 1]) {
          start--;
          end++;
      }

      // getting the length of palindrome around current center
      positions.splice(i, 0, end - start + 1);

      // this is case 2. Current palindrome is proper suffix of input. Meaning input
      // is the longest palindrome
      if (end === (sequence.length - 1)) {
          break;
      }

      // Mark newCenter to be either end or end + 1 depending on if we dealing with
      // even or old number input.
      let newCenter = end + (i % 2 == 0 ? 1 : 0);

      for (let j = i + 1; j <= end; j++) {

          // Its possible left mirror might go beyond current center palindrome. So take
          // minimum of either left side palindrome or distance of j to end.
          // T[j] = Math.min(T[i - (j - i)], 2 * (end - j) + 1);
          num = positions[Math.abs(i - (j - i))];
          positions.splice(j, 0, (Math.min(num, (2 * (end - j) + i))));

          // This check is to make sure we do not pick j as new center. As soon as we find
          // a center lets break out of this inner loop.
          if (j + parseInt(positions[i - (j - i)] / 2) === end) {
              newCenter = j;
              break;
          }
      }

      // make i as newCenter. Set right and left to atleast the value we already know
      // should be matching based of left side palindrome.
      i = newCenter;
      if (i < positions.length) {
          end = i + parseInt(positions[i] / 2);
          start = i - parseInt(positions[i] / 2);
      }
  }

  let max = Math.max.apply(null, positions);
  let pos = positions.indexOf(max);

  let pos1 = pos - parseInt(max / 2);
  let pos2 = pos + parseInt(max / 2);
  if (positions.length % 2 == 0) {
      sequence = sequence.slice(pos1, pos2 + 1);
  } else {
      sequence = sequence.slice(pos1, pos2);
  }

  // removing $ signs
  str = originalString(sequence);

  return str;
}

const originalString = (arr) => {
  return arr.filter(x => x !== '$').join('');
}

const processString = (str) => {
  let strArr = ['$'];

  for (let i = 0; i < str.length; i++) {
      strArr.push(str[i]);
      strArr.push('$');
  }

  return strArr;
}

const str1 = findPalindrome("abba");
const str2 = findPalindrome("babcbaabcbaccba");

console.log("Longest palindromic substring for input 1:" + str1);
console.log("Size:" + str1.length);
console.log("Longest palindromic substring for input 2:" + str2);
console.log("Size:" + str2.length);

/**
* Outputs for the sample inputs:
* Longest palindromic substring for input 1:abba
* Size:4
* Longest palindromic substring for input 2:abcbaabcba
* Size:10
*
* Time complexity: O(n) Space complexity: O(n)
*/