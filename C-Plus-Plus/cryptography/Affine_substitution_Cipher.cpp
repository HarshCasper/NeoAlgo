#include <bits/stdc++.h>
using namespace std;

const int a = 19;
const int b = 20;
const int m = 26;

string encryption(string message) {
    string cipher;
    /*
     Encrypted Message(x) = ( a * x + b ) mod m 
    modulus m: size of the alphabet, here 26
    a and b: key of the cipher.
    a and m should be coprime.
    */

    for (int i = 0; i < message.size(); ++i) {
        if(message[i]!=' ') { // Spaces should not be encrypted
            cipher += (char)((a * (message[i] - 'A') + b) % 26 + 'A');
            //to make it in range of ASCII alphabet addition of "A" is done
        }
        else {
            cipher += message[i];
        }
    }
    return cipher;
}

string decryption(string cipher) {
    string message;
    int a_inv = 0;
    for (int i = 0; i < 26; ++i) {
        if((a * i) % 26 == 1){
            a_inv = i;
            break;
        }
    }
    /*
    Decrypted Message(x) = a_inv ( x - b ) mod m
    a_inv : modular multiplicative inverse of a modulo m
    1 = (a * a_inv) mod m .
    */
    for (int i = 0; i < cipher.size(); ++i) {
        if(cipher[i] != ' '){ // Spaces were not encrypted
            message += (char)(a_inv * (cipher[i] + 'A' - b) % 26 + 'A');
            //to make it in range of ASCII alphabet addition of "A" is done
        }
        else {
            message += cipher[i];
        }
    }
    return message;
}

int main() {
    string message = "TESSERACTCODINGNEOALGO";
    //use only uppercase characters (you can modify the code for lowercase characters)
    string new_message = encryption(message);
    cout << "Encrypted Message: " << new_message<<"\n";
    string original_message = decryption(new_message);
    cout << "Decrypted Message: " << original_message;
    return 0;
}

/*
OUTPUT
Encrypted Message: RSYYSFUGRGAZQHEHSAUVEA
Decrypted Message: TESSERACTCODINGNEOALGO
*/
