def extended_gcd(aa, bb):
    lastremainder, remainder = abs(aa), abs(bb)
    x, lastx, y, lasty = 0, 1, 1, 0
    while remainder:
        lastremainder, (quotient, remainder) = remainder, divmod(lastremainder, remainder)
        x, lastx = lastx - quotient*x, x
        y, lasty = lasty - quotient*y, y
    return lastremainder, lastx * (-1 if aa < 0 else 1), lasty * (-1 if bb < 0 else 1)

def modinv(a, m):
        g, x, y = extended_gcd(a, m)
        if g != 1:
            raise ValueError
        return x % m


    #encrypting using affine cipher
def encrypt_affine(plaintext,k1,k2):
    ciphertext = ""
    for i in range(len(plaintext)):
        if plaintext[i] is " ":
            ciphertext += " "
        else:
            ciphertext += chr(((k1 * (ord(plaintext[i])-97) + k2 ) % 26 )+ord('a'))

    return(ciphertext)

#decryption
def decrypt_affine(ciphertext,k1,k2):
    plaintext = ""
    for i in range(len(ciphertext)):
        if ciphertext[i] is " ":
            plaintext += " "
        else:
            plaintext += chr((( modinv(k1, 26)*(ord(ciphertext[i]) - ord('a') - k2))  % 26) + ord('a'))

    return(plaintext)

# taking the input
plaintext = (input("Plaintext: "))
k1 = int(input("Key1: "))
k2 = int(input("Key2: "))
#encrypt
result_ciphertex= encrypt_affine(plaintext,k1,k2)
print(result_ciphertex)
#decrypt
result_plain = decrypt_affine(result_ciphertex,(k1),(k2))
print(result_plain)
