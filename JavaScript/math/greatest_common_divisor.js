//                  Greatest Common Divisor(GCD)

// The greatest common divisor (GCD), also called the greatest common factor, of two numbers is the largest number that divides both the number. For example, the greatest common factor of 12 and 15 is 3, since 3 divides both 15 and 12 and no larger number than 3 has this property. 

// Finding GCD using naive approach
// Iterative approach
function gcdNaiveSolution(numberA, numberB){
    // calculate minimum value out of two inputs using min function
    let res = Math.min(numberA,numberB);
    
    // start dividing  both the numbers by minimum value and decrement that number till both numbers gets divided.
    while(res>0){
        // Here we divide both the numbers by min value, if it gets divided, then we got our GCD and stops the loop. Otherwise decrement the min value and try again.
        if((numberA%res == 0) && (numberB%res == 0)){
            break;
        }
        res--;
    }
    return res;
}

let gcdValueOfTwoNumbers = gcdNaiveSolution(12,15);
console.log(gcdValueOfTwoNumbers); // prints 3

// Finding GCD using Euclidean Algorithm

// The algorithm is based on the below facts. 
// If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
// Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.

function gcdUsingEuclidean(numberA, numberB){
    while(numberA!=numberB){
        if(numberA>numberB){
            numberA=numberA-numberB;
        }else{
            numberB=numberB-numberA;
        }
    }
    return numberA;
}

let gcdValueOfTwoNumbersUsingEuclideanAlgorithm = gcdUsingEuclidean(15,20);
console.log(gcdValueOfTwoNumbersUsingEuclideanAlgorithm); // prints 5


// Most optimized way of finding GCD using Euclidean Algorithm
// Recursive approach
function gcdUsingrecursiveWay(numberA, numberB){
      return numberB == 0 ? numberA : gcdUsingrecursiveWay(numberB, numberA%numberB);   
}


let gcdValueOfTwoNumbersUsingRecursiveWay = gcdUsingrecursiveWay(15,20);
console.log(gcdValueOfTwoNumbersUsingRecursiveWay); // prints 5
