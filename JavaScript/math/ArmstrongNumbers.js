//program for an armstrong number or not

//first we take input for the number
let number = "153"
    //window.prompt("enter a positive no");
    //then we calculate the no of digits 
let n = number.length
console.log(n)
    //we store our number in a temporary variable
let temp = number
    //variable for summing up the digits raised to the total no of digits
let sum = 0


while (temp > 0) {

    //extracting the last digit
    let rem = temp % 10;

    //summation
    sum += parseInt(rem ** n);

    // removing last digit from the number
    // convert float into integer
    temp = parseInt(temp / 10);
}

//checking for armstrong no.
if (sum == number) {
    console.log(`${number} is an Armstrong number`);
} else {
    console.log(`${number} is not an Armstrong number.`);
}