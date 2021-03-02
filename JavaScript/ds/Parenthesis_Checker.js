function checkclosingParen(lastParen, currParen) {
  return (
    (lastParen === "(" && currParen === ")") ||
    (lastParen === "[" && currParen === "]") ||
    (lastParen === "{" && currParen === "}")
  );
}

function BalancedParen(parenString) {
  let pseudoStack = []; // Using Array(object) as stack therefore named as pseudoStack
  for (let i = 0; i < parenString.length; i++) {
    if (
      parenString[i] == "(" ||
      parenString[i] == "[" ||
      parenString[i] == "{"
    ) {
      pseudoStack.push(parenString[i]);
    } else {
      if (pseudoStack.length === 0) return "Unbalanced";
      else if (
        checkclosingParen(pseudoStack[pseudoStack.length - 1], parenString[i])
      )
        pseudoStack.pop();
      else return "Unbalanced";
    }
  }
  if (pseudoStack.length === 0) return "Balanced";
  else return "Unbalanced";
}

let parenString1 = "[]{}()";
let parenString2 = "[{}()]";
let parenString3 = "[{()}]";
let parenString4 = "][(){";
let parenString5 = "[{]}";

console.log(BalancedParen(parenString1)); // Balanced
console.log(BalancedParen(parenString2)); // Balanced
console.log(BalancedParen(parenString3)); // Balanced
console.log(BalancedParen(parenString4)); // Unbalanced
console.log(BalancedParen(parenString5)); // Unbalanced
