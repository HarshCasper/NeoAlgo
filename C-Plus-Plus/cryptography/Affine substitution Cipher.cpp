#include <bits/stdc++.h>
using namespace std;

const int a = 19;
const int b = 20;
const int m = 26;

string encryption(string message) {
    string cipher;
    for (int i = 0; i < message.size(); ++i) {
        if(message[i]!=' ') {
            cipher += (char)((a * (message[i] - 'A') + b) % 26 + 'A');
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
    for (int i = 0; i < cipher.size(); ++i) {
        if(cipher[i] != ' '){
            message += (char)(a_inv * (cipher[i] + 'A' - b) % 26 + 'A');
        }
        else {
            message += cipher[i];
        }
    }
    return message;
}

int main() {
    string message = "TESSERACTCODINGNEOALGO";
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
