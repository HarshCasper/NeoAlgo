
# CAESAR CIPHER

'''

The Caesar Cipher technique is one of the earliest and simplest method of encryption technique. It’s simply a type of
substitution cipher,i.e., each letter of a given text is replaced by a letter some fixed number of positions down the
alphabet. For example with a shift of 1, A would be replaced by B, B would become C, and so on. The method is apparently
named after Julius Caesar, who apparently used it to communicate with his officials.Thus to cipher a given text we need
an integer value, known as shift which indicates the number of position each letter of the text has been moved down.

In the below code messages are encrypted with a shift of the value provided as key by users
'''

# Decrypt Caesar Cipher Messages
def c_decrypt(strn, sft):
    msg = ""
    for i in range(len(strn)):
        ch = strn[i]

        if ch == ' ':
            msg += ch
            continue
        if ch.isupper():
            msg += chr((ord(ch) - sft - 65) % 26 + 65)
        else:
            msg += chr((ord(ch) - sft - 97) % 26 + 97)
    return msg


# Encrypt Caesar Cipher Messages
def c_encrypt(strn, sft):
    msg = ""
    for i in range(len(strn)):
        ch = strn[i]

        if ch == ' ':
            msg += ch
            continue
        if ch.isupper():
            msg += chr((ord(ch) + sft - 65) % 26 + 65)
        else:
            msg += chr((ord(ch) + sft - 97) % 26 + 97)
    return msg


t = ""
while t != "exit" :

    choice = input("Choose 1 for ENCRYPT and 2 for DECRYPT : ")

    if int(choice) == 1:
        print("Enter message to encrypt")
        st = input()
        print("Enter key value")
        s = int(input())
        e_msg = c_encrypt(st, s)
        print("Encrypted message : "+e_msg)

    elif int(choice) == 2:
        print("Enter message to decrypt")
        st = input()
        print("Enter key value")
        s = int(input())
        e_msg = c_decrypt(st, s)
        print("Decrypted message : "+e_msg)

    else:
        print("Wrong Choice")

    print("Want to encrypt/decrypt again? Press 'c' to continue. Or Press 'exit' to end process.")
    t = input()
