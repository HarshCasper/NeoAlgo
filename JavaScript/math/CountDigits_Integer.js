let number = 1234567      

// Iterative Method
function countDigitsIterative(num) {
    let digits = 0;
    while(num){                         // This condition becomes false when num becomes 0(zero) 
        digits++;
        num = parseInt(num/10);         
        // Here, parseInt method is used to convert divided decimal number to integer, e.g. 126/10 = 12.6, parseInt(12.6) = 12  
    }
    return digits;
}

console.log(countDigitsIterative(number));                      // Output : 7


// Recursive Method
function countDigitsRecursive(num) {
    if(num === 0){
        return 0;
    }
    return 1 + countDigitsRecursive(parseInt(num/10));
}

console.log(countDigitsRecursive(number));                      // Output : 7


// String Method
let strNum = number.toString();     // convert number to string , 1234 -> "1234"

console.log(strNum.length);                                     // Output : 7


// Logarithm Approach
let logNum = 1 + Math.floor(Math.log10(number));

console.log(logNum);                                            // Output : 7


// Not very useful but still a working approach
let numArr = strNum.split("");      // splitting a string and converting it into an Array , "1234" -> ["1", "2", "3", "4"]

console.log(numArr.length);                                     // Output : 7