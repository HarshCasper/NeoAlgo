import 'dart:io';

// List to store all permutations possible
List allPermutations = [];

// Function to backtrack and find all possible combinations of a input string
void permute(List word, int current_letter) {
  // when the cursor gets this far, we've found one permutation, so save it
  if (current_letter == word.length) {
    allPermutations.add(word);
    return;
  }

  for (int count = current_letter; count < word.length; count++) {
    List permutation = new List.from(word);
    permutation[current_letter] = word[count];
    permutation[count] = word[current_letter];
    permute(permutation, current_letter + 1);
  }
}

// Function to call recursive function and return the list of permutations
List<String> getPermutations(String input_string) {
  // Pass input string to recursive function
  permute(input_string.split(''), 0);

  //Join individual letters from all permutations and return as list
  List<String> permutations = [];
  for (List permutation in allPermutations) {
    permutations.add(permutation.join());
  }
  return permutations;
}

// Main function with driver code
void main() {
  // Get user input
  print("Enter String:");
  String str = stdin.readLineSync()!;

  // pass arguments into function
  List<String> permutations = getPermutations(str);
  print("All possible permutations for $str are: ");

  Set<String> set = new Set<String>.from(permutations);
  for (var permutation in set) {
    print(permutation);
  }
}

/*
Time Complexity:  O(n^2 * n!)
Space Complexity: O(1)
 
Sample I/O:

Enter String:
fun
All possible permutations for fun are:
fun
fnu
ufn
unf
nuf
nfu

Enter String:
lol
All possible permutations for lol are:
lol
llo
oll
*/

