/*

  Conversion from decimal to Hexadecimal number in dart

*/

import "dart:io";

void decimalToHexadecimal(int decimalNumber) {
  List<int> ans = [];

  int lastDigit = 0, hexCodeLen = 0;

  while (decimalNumber != 0) {
    lastDigit = decimalNumber % 16;
    decimalNumber = (decimalNumber / 16).floor();

    /*
     If lastDigit is greater than 9 then X will be alphabet(hexadecimal),
     else X will be a number(hexadecimal)
     */
    int hexCharCode;
    if (lastDigit > 9)
      hexCharCode = lastDigit + 'A'.codeUnitAt(0) - 10;
    else
      hexCharCode = lastDigit + '0'.codeUnitAt(0);

    ans.add(hexCharCode);
    hexCodeLen++;
  }

  //Loop for printing String in Reverse order
  stdout.write("Hexadecimal Number: ");
  for (int k = hexCodeLen - 1; k >= 0; k--) {
    stdout.write(String.fromCharCode(ans[k]));
  }
}

int main() {
  stdout.write("Enter the Decimal Number: ");

  int decimalNumber = int.parse(stdin.readLineSync()!);
  decimalToHexadecimal(decimalNumber);

  return 0;
}

/* Testcases:

  Test 1
  Enter the Decimal Number: 3452
  Hexadecimal Number: D7C

  Test 2
  Enter the Decimal Number:100
  Hexadecimal Number: 64

  Test 3
  Enter the Decimal Number: 12341234244333 
  Hexadecimal Number: B396AE21AED

  Time Complexity- O(n);
  Space Complexity- O(1);

*/
