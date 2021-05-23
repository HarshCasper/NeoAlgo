/*
About Play Fair Cipher: In Play fair, The Key Matrix will be always 5x5 dimension. It neither depends on key nor on plain text. 
                        We have to build always a 5x5 matrix. Now, this 5x5 grid of matrix consists of alphabets(a-z) which is used to encrypt/decrypt the text. 
                        Each of the 25 alphabets must be unique and we have to assume I and J as a single char(it's our choice to select I or J). 
                        Because, 5x5 grid contains only 25 slots. If the plaintext contains J/I, then it is replaced by I/J(based on our assumption).

Rules:
    1. Form a rectangle with the two letters and take the letters on the horizontal opposite corner of the rectangle.
    2. If both the letters are in the same row: Take the letter to the right of each one (going back to the leftmost if at the rightmost position).
    3. If both the letters are in the same column: Take the letter below each one (going back to the top if at the bottom).
*/

#include <bits/stdc++.h>
#define dim 5 //dimension 5x5

std::string resulttext;
char matrix[dim][dim], choosechar(int a, int b);
bool chooseindex(char l, int &a, int &b);
void formmatrix(std::string k, bool ij);

// Argument e_d: Encryption or Decryption(true/false)
std::string play_fair(std::string key, std::string text, bool ij, int e_d)
{
    formmatrix(key, ij);
    // Placing I/J in one cell in matrix
    for (std::string::iterator i = text.begin(); i != text.end(); ++i)
    {
        *i = toupper(*i);
        if (*i < 65 || *i > 90)
            continue;
        if (*i == 'J' && ij)
            *i = 'I';
        else if (*i == 'Q' && !ij)
            continue;
        resulttext += *i;
    }
    // For Encryption
    if (e_d)
    {
        std::string temptext = "";
        size_t len = resulttext.length();
        for (size_t x = 0; x < len; x += 2)
        {
            temptext += resulttext[x];
            if (x + 1 < len)
            {
                if (resulttext[x] == resulttext[x + 1])
                    temptext += 'X';
                temptext += resulttext[x + 1];
            }
        }
        resulttext = temptext;
    }
    if (resulttext.length() & 1)
        resulttext += 'X';

    // for Indexes
    int a, b, c, d;
    // Result strings
    std::string tempresult = "";
    // Iterating through out the string(all chars)
    for (std::string::const_iterator i = resulttext.begin(); i != resulttext.end(); ++i)
    {
        // Selecting the indexes from matrix
        if (chooseindex(*i++, a, b))
            if (chooseindex(*i, c, d))
            {
                if (a == c)
                {
                    tempresult += choosechar(a, b + e_d);
                    tempresult += choosechar(c, d + e_d);
                }
                else if (b == d)
                {
                    tempresult += choosechar(a + e_d, b);
                    tempresult += choosechar(c + e_d, d);
                }
                else
                {
                    tempresult += choosechar(c, b);
                    tempresult += choosechar(a, d);
                }
            }
    }
    resulttext = tempresult;
    return resulttext;
}

// Selecting char from matrix with provided indexes(parameters)
char choosechar(int a, int b)
{
    return matrix[(b + dim) % dim][(a + dim) % dim];
}

// Validation
bool chooseindex(char character, int &a, int &b)
{
    for (int y = 0; y < dim; ++y)
        for (int x = 0; x < dim; ++x)
            if (matrix[y][x] == character)
            {
                a = x;
                b = y;
                return true;
            }
    return false;
}

/*
First, We have fill the matrix with letters/characters of key without repeating any character(skip duplicates).
(*) = empty
fill the other slots with remaining characters(a-z) sequentially. Place I/J in one slot(index). Now the resultant will be our Key matrix
*/
void formmatrix(std::string key, bool ij)
{
    if (key.length() < 1)
        key = "";
    key += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string tempKey = "";
    for (std::string::iterator i = key.begin(); i != key.end(); ++i)
    {
        *i = toupper(*i);
        if (*i < 65 || *i > 90)
            continue;
        if ((*i == 'J' && ij) || (*i == 'Q' && !ij))
            continue;
        if (tempKey.find(*i) == -1)
            tempKey += *i;
    }
    copy(tempKey.begin(), tempKey.end(), &matrix[0][0]);
}

// Driver code starts
int main(int argc, char *argv[])
{
    std::string key = "harry";
    std::string plaintext = "my name is ravi";
    std::string encryptedtext, decryptedtext;
    std::cout << "\nPlain Text is : " << plaintext;
    // Encryption Process starts
    encryptedtext = play_fair(key, plaintext, true, 1);
    std::cout << "\n\nEncrypted Text is : " << encryptedtext; // Displaying Encrypted Key
    // Decryption Process starts
    decryptedtext = play_fair(key, encryptedtext, true, -1);
    decryptedtext = decryptedtext.substr(0, decryptedtext.length() / 2);
    std::cout << "\nDecrypted Text is: " << decryptedtext; // Displaying Decrypted Key
    return 0;
}

/*
Sample Input:
    Key: harry
    plainText: my name is ravi

Sample Output:
    Plain Text is : my name is ravi
    Encrypted Text is : SFKBLFMOYRUK
    Decrypted Text is: MYNAMEISRAVI
*/
