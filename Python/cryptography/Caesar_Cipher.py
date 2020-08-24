# CAESAR CIPHER

"""
The Caesar Cipher technique is one of the earliest and simplest method of encryption technique. It’s simply a type of
substitution cipher,i.e., each letter of a given text is replaced by a letter some fixed number of positions down the
alphabet. For example with a shift of 1, A would be replaced by B, B would become C, and so on. The method is apparently
named after Julius Caesar, who apparently used it to communicate with his officials.Thus to cipher a given text we need
an integer value, known as shift which indicates the number of position each letter of the text has been moved down.

In the below code messages are encrypted with a shift of the value provided as key by users
"""

# Decrypt Caesar Cipher Messages

"""Function to decrypt a caesar ciphered message"""
def decrypt(text, shift):
    message = ""

    """Looping through all the characters present in text"""
    for character in range(len(text)):

        """Saving current character in current_character"""
        current_character = text[character]

        """If current characater is space adding it directly to message"""
        if current_character == ' ':
            message += current_character
            continue

        """If current characater is an uppercase letter adding it after shifting with key value to message"""
        if current_character.isupper():
            message += chr((ord(current_character) - shift - 65) % 26 + 65)
            continue

        """If current characater is an lowercase letter adding it after shifting with key value to message"""
        if current_character.islower():
            message += chr((ord(current_character) - shift - 97) % 26 + 97)
            continue

    """Returning the message"""
    return message


# Encrypt Caesar Cipher Messages

"""Function to encrypt a message"""
def encrypt(text, shift):
    message = ""

    """Looping through all the characters present in text"""
    for character in range(len(text)):

        """Saving current character in current_character"""
        current_character = text[character]

        """If current characater is space adding it directly to message"""
        if current_character == ' ':
            message += current_character
            continue

        """If current characater is an uppercase letter adding it after shifting with key value to message"""
        if current_character.isupper():
            message += chr((ord(current_character) + shift - 65) % 26 + 65)
            continue

        """If current characater is an lowercase letter adding it after shifting with key value to message"""
        if current_character.islower():
            message += chr((ord(current_character) + shift - 97) % 26 + 97)
            continue

    """Returning message"""
    return message


# Driver main function
if __name__ == '__main__':
    choice = input("Choose 1 for ENCRYPT and 2 for DECRYPT : ")
    if int(choice) == 1:
        print("Enter message to encrypt")
        text = input()
        print("Enter key value")
        shift = int(input())
        encrypted_message = encrypt(text, shift)
        print("Encrypted message : " + encrypted_message)

    elif int(choice) == 2:
        print("Enter message to decrypt")
        text = input()
        print("Enter key value")
        shift = int(input())
        decrypted_message = decrypt(text, shift)
        print("Decrypted message : " + decrypted_message)

    else:
        print("Wrong Choice")


'''
Input Description :
Line 1 : Choice 1 or 2
Line 2 : Message 
Line 3 : Key shift value

 
Input and Output Examples:

Input 1:
        Line 1: 1
        Line 2: "Hello"
        Line 3: 2
        
Output 1:  
        Encrypted message : Jgnnq


Input 2:
        Line 1: 2
        Line 2: "Jgnnq"
        Line 3: 2
        
Output 2: 
        Decrypted message : Hello
        
'''
