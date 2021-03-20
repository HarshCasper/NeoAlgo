const removeOuterParenthesis = (str) => {

  // breaking the string into an array of characters
  let strArr = str.split('');
  let stack=[];

  // looping the array to check the characters
  for(let i = 0; i < strArr.length; i++){

    // we store the index if the character is an opening parenthesis
    if(strArr[i] == '(') {
      stack.push(i);
    } else {
      // removing the elements of stack
      let ele = stack.pop();

      // this checks if we have reached the outermost
      // closing parenthesis
      if(!stack.length){
        // replace the outermost characters with 0
        strArr[i] = '0';
        strArr[ele] = '0';
      }
    }
  }
  // return the string after removing the 0's and joining the characters
  return strArr.filter(x=>x!='0').join('');
}

console.log(removeOuterParenthesis("(()())(())"));
console.log(removeOuterParenthesis("(()())(())(()(()))"));

/**
 * Output for the above inputs:
 * ()()()
 * ()()()()(())
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
