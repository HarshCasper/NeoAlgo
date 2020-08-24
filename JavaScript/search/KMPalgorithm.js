//function to make pattern table to store when sub-patterns in given pattern repeat
function makePatternTable(pattern) {
  const patternTable = [];
  let prefIndex = 0, sufIndex = 1;

  while (sufIndex < pattern.length) {
    if (pattern[prefIndex] === pattern[sufIndex]) {

      //found a match in sub-pattern, store index+1
      patternTable[sufIndex] = prefIndex + 1;
      sufIndex++;
      prefIndex++;
    } else if (prefIndex === 0) {

      patternTable[sufIndex] = 0;
      sufIndex += 1;
    } else {

      prefIndex = patternTable[prefIndex - 1];
    }
  }

  //return the pattern table made to find the pattern's occurrence
  return patternTable;
}

function kmpSearch(text, pattern) {
  if (pattern.length === 0) {
    return 0;
  }

  const patTable = makePatternTable(pattern);
  let textIndex = 0, patIndex = 0;

  while(textIndex < text.length) {
    if (text[textIndex] === pattern[patIndex]) {

      // We've found a match.
      if (patIndex === pattern.length - 1) {
        return (textIndex - pattern.length) + 1;
      }
      patIndex++;
      textIndex++;
    }
    else if (patIndex > 0) {
      patIndex = patTable[patIndex - 1];
    }
    else {
      patIndex = 0;
      textIndex++;
    }
  }

  return -1;
}

result = kmpSearch('hakincodes', 'kin');
if(result === -1) {
  console.log("Pattern is not present in the text.")
} else {
  console.log(`Pattern is present in text at index ${result}`);
}

/*
Output for above sample input:
Pattern is present in text at index 2

Time complexity = O(m+n)
Space complexity = O(n)
m = number of characters in text
n = number of characters in pattern
*/
