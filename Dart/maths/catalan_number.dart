/*
Catalan numbers is a "number sequence", Its useful in a number of
combinatorial problems, often involving recursively-defined objects.
*/

import 'dart:io';

// To find nth catalan number using recursive function
int catalan(int n){
  if (n <= 1)
    return 1;
  int res = 0;
  for (int i = 0; i < n; i++)
    res = res + catalan(i) * catalan(n - i - 1);

  return res;
}

int main(){
  print("Enter the Number:");
  int n  = int.parse(stdin.readLineSync()!);
  for (int i = 0; i < n; i++)
  {
    stdout.write(catalan(i));
    stdout.write(" ");
  }
  return 0;
}

/*
Input:
Enter the Number:
13
Output:
1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 

Time Complexity: O(2^n)
Space Complexity: O(1)
*/