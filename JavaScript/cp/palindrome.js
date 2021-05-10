/* A palindrome is a word or sentence that's spelled the same way both forward and backward, ignoring punctuation, case, and spacing.
Given a string we need to write a function that returns true if the string is palindrome and false if it is not.
Remove the non alphanumeric characters during comparison.
*/
var palindrome = (str) => {
    var strAlphaNumeric = str.replace(/[\W_]/g, ""); //remove all non-alphanumeric characters
      var lowerCase = strAlphaNumeric.toLowerCase(); //turn everything to lowercase
      var reversedStr = lowerCase.split("").reverse().join(""); //reverse the string to check if the reversed words match the first words.
      
      if (lowerCase == reversedStr) 
      { //check if lcase match revcase, if yes, return true
        return true;
      } else { //otherwise return false.
        return false;
      }
    }
    
    
    /*
    Example: 

    palindrome("eye") should return `true`

    palindrome("_eye") should return `true`

    palindrome("race car") should return `true`

    */