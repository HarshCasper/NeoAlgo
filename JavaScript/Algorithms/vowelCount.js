//Program to count the number of vowels in a sentence

function vowelCount(str){
    const vowels=["a","e","i","o","u","A","E","I","O","U"]
    let count=0
    for(let character of str){
        if(vowels.includes(character)){
            count++;
        }
    }
    return count;
}
const str=prompt("Enter string:")
const count=vowelCount(str)
console.log(count)

/*
Time Complexity: O(n)
Example:
Input:
Enter string: Javascript is necessary for web development
Output:
13
*/ 
