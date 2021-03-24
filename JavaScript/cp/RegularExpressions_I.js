/*in this challenge, we use a Regular Expression to evaluate a string.
The function must return a RegExp object that matches any string s beginning with and ending in the same vowel.

Problem Statement link: https://www.hackerrank.com/challenges/js10-regexp-1/problem
*/

function regexVar() {
    /*
     * Declare a RegExp object variable named 're'
     * It must match a string that starts and ends with the same vowel (i.e., {a, e, i, o, u})
     */

    let re = /^([aeiou]).+\1$/
    /*
     * Do not remove the return statement
     */
    return re;
}

