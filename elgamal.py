#!/usr/bin/env python3

"""
Implementation of ElGamal over elliptic curves.
This version uses hash-based approach to encrypt a message M,
in order to avoid mapping M to a curve point.

For injective encodings to elliptic curves, see https://eprint.iacr.org/2013/373.pdf

Noxet
2019
"""

from random import randint
from hashlib import sha256

from ecc import EllipticCurve, ECPoint

def keygen():
    # use the secp256k1 curve
    p = int('FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F', 16)
    a = 0
    b = 7
    g = ECPoint(int('79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798', 16), 
        int('483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8', 16))
    G = EllipticCurve(p, g, a, b)

    # generate private key
    x = randint(1, p)
    h = G.mul(g, x)

    return (x, G, g, p, h)


def encrypt(m, G, g, p, h):
    """
    Encryption of plaintext m.

    Parameters
    ----------
    m: The message, a point on the curve
    G: The curve
    g: The curve base point
    p: The order of the field
    h: Public part of the shared secret
    """

    # TODO: implement a padding scheme for m, like OAEP

    y = randint(1, p)
    c1 = G.mul(g, y)
    s = G.mul(h, y)         # h*y = g*xy
    # c2 = m xor H(h*y)
    hs = sha256(repr(s).encode('utf-8')).digest()
    c2 = bytearray([i ^ j for i,j in zip(m, hs)])
    return (c1, bytes(c2))


def decrypt(c, x, G):
    """
    Decryption of ciphertext c.
    
    Parameters
    ----------
    c: The ciphertext tuple, (c1, c2)
    x: The private key
    G: The curve
    """
        
    c1, c2 = c
    s = G.mul(c1, x)
    # m = c2 xor H(c1*x)
    hs = sha256(repr(s).encode('utf-8')).digest()
    m = bytearray([i ^ j for i,j in zip(c2, hs)])
    return bytes(m)


if __name__ == '__main__':
    x, G, g, p, h = keygen()
    m = input('Enter message: ').encode('utf-8')

    c = encrypt(m, G, g, p, h)
    print('Encrypted: {}'.format(c))
    mp = decrypt(c, x, G)
    print('Decrypted:\t{}'.format(mp.decode()))
    assert m == mp
