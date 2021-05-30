/*
About Autokey Cipher: Autokey (Autoclave) Cipher is a Symmetric polyalphabetic (Polyceaser) substitution cipher. 
                      This algorithm is about changing plaintext letters based on secret key letters. 
                      Each letter of the message is shifted along some alphabet positions. 
                      The number of positions is equal to the place in the alphabet of the current key letter.

Formula for Encryption:
    Ei = (Pi + Ki) mod 26

Formula for Decryption:
    Di = (Ei - Ki + 26) mod 26
Where:
    Ei: Encrypted text
    Pi: Plain Text values
    Ki: Plain Text values after adding key.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_stdin()
{
    while (fgetc(stdin) != '\n')
        ;
}

void autokeycipher(char **text, char key, int encrypt)
{
    int textsize;
    textsize = strlen((*text));

    /* The first step is to convert all letter in plaintext either to lowercase or uppercase.*/
    for (int i = 0; i < textsize; ++i)
    {
        if (isalpha((*text)[i]))
        {
            // Converting to Upper
            (*text)[i] = toupper((*text)[i]);
        }
    }

    int nextkey, keyvalue, result;
    // now get the equivalent alphabetic values of plaintext.
    nextkey = toupper(key) - 'A';

    /* Shift the values of plaintext towards right and add key at first.*/
    /* Now, add both the above number. */
    for (int i = 0; i < textsize; ++i)
    {
        if (isalpha((*text)[i])) // checking for text type
        {
            keyvalue = nextkey;
            if (encrypt)
            {
                nextkey = (*text)[i] - 'A';
                // if the number/sum exceed 26, then we will start from beginning.
                (*text)[i] = ((*text)[i] - 'A' + keyvalue) % 26 + 'A';
            }
            else
            {
                result = ((*text)[i] - 'A' - keyvalue) % 26 + 'A';
                (*text)[i] = result < 'A' ? (result + 26) : (result);
                nextkey = (*text)[i] - 'A';
            }
        }
    }
}

int main(int argc, char **argv)
{
    char key, *plaintext;

    printf("Enter the Single Key word: ");
    scanf("%c", &key);

    int length;
    printf("Enter the length of Plain Text: ");
    scanf("%d", &length);

    // Allocating space at run-time
    plaintext = (char *)malloc((length + 1) * sizeof(char));
    flush_stdin();

    printf("Enter the Plain Text: ");
    fgets(plaintext, length + 1, stdin);
    flush_stdin();

    printf("\nThe Plain Text is: %s", plaintext);
    /* 3rd argument decides whither to do 1-Encryption or 0-Decryption. */
    // Encryption Process
    autokeycipher(&plaintext, key, 1);
    printf("\nThe Text after Encryption(Cipher text) is: %s", plaintext);

    // Decryption Process
    autokeycipher(&plaintext, key, 0);
    printf("\nAfter Decryption the Text is: %s", plaintext);

    // Freeing up allocated space
    free(plaintext);
    return 0;
}

/*
Sample Input:
    Enter the Single Key word: L //In A-Z, L will be at 11 index.
    Enter the length of Plain Text: 5
    Enter the Plain Text: hello


Sample Output:
    The Plain Text is: hello
    The Text after Encryption(Cipher text) is: slpwz

After Decryption the Text is: hello
*/
