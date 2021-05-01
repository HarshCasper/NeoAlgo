/*  Given two strings word and text, return the number of 
substrings where text contains any anagram of word. */


/* Function to count the number of anagrams */
const countAnagrams = (word, text) => {
    let alpha = new Array(26);

    for(let i = 0; i<alpha.length; i++){
        alpha[i] = 0;
    }

    /* Calculating the frequency of each character in the given word */
    for(let c in word){
        alpha[word.charCodeAt(c)-97]++;
    }

    let window = [];
    let ans = 0;

    /* Checking the occurrences of anagrams of the given word*/
    for(let i=0; i<text.length; i++){
        let c = text.charCodeAt(i);

        /* Adding the current character to the window if the word contains it*/
        if(alpha[c-97] > 0){
            /* Subtracting the given word as we have added it to the window */
            alpha[c-97]--;
            window.push(i);
        }else{

            /* Decrementing the window until it is feasible to accommodate the current character */
            while(window.length > 0 && alpha[c-97] <= 0){
                alpha[text.charCodeAt(window.shift()) - 97]++;
            }

            /* Adding the current character to the window if the word contains it */
            if(alpha[c-97] > 0){
                alpha[c-97]--;
                window.push(i);
            }
        }

        /* Increasing the answer if the window size = word size */
        if(window.length == word.length){
            ans++;
            /* Removing the first character of the window */
            alpha[text.charCodeAt(window.shift()) - 97]++;
        }
    }

    return ans;
}


console.log("Enter the word to be found and the text in which the word needs to be searched");

/* List stores the word and the text */
let list = readline()
    .split(" ")
    .map((element) => element);

/* Only two elements are present in the list, the first one 
represents the word to be searched and the second one 
represents the text in which the word is searched in  */
console.log("Number of substrings which contains the anagram ", list[0], " in ", list[1], " is ", countAnagrams(list[0], list[1]));

/* 
Example 1:

Input:

ab aab

Output:

Number of substrings which contains the anagram ab in aab is 1

Time Complexity: O(N)
Space Complexity: O(K)
*/

