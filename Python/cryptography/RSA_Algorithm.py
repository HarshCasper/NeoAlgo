import math


def inverse_mod(p, m):
    p = p % m
    for i in range(1, m):
        if(p * i) % m == 1:
            return i
    return 1

if __name__ == '__main__':
    '''p and q  are prime numbers. pt is plain text.
    e is derived number which lies between 1 and (p-1)*(q-1)
    '''
    p, q, e, pt = [int(x) for x in input("Enter p, q, e and plaintext: ").split()]
    n = p * q
    fn = (p-1) * (q-1)
    d = inverse_mod(e, fn)
    ct = pow(pt, e, n)
    print(f'Encryption for PlainText = {pt}, is CipherText = {ct}')
    new_pt = pow(ct, d, n)
    print(f'Decryption for CipherText = {ct}, is PlainText = {new_pt}')

'''Sample input and output
Enter p, q, e and plaintext: 7 13 5 10
Encryption for PlainText = 10, is CipherText = 82
Decryption for CipherText = 82, is PlainText = 10

Complexities
time: O(n)
space: O(1)
'''