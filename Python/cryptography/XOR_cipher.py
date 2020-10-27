from binascii import unhexlify as unhex


def encryption(message: str, key: int) -> str:
    """Return the ciphertext by xor the message with a repeating key"""

    return b"".join(
        [bytes([message[i] ^ key[i % len(key)]]) for i in range(len(message))]
    )


def decryption(cipher: str, key=None) -> str:
    """
    Decode repeating xor with optional key parameter
    """

    # find keysize
    keysize = find_keysize(cipher)

    if key is None:
        pt = []
        for ks in keysize:
            # find key
            key = find_key(cipher, ks["keysize"])
            # return plaintext
            plaintext = encryption(cipher, key)
            pt.append({
                "plaintext": plaintext, 
                "key": key, 
                "score": scoring_system(plaintext)
                })

        return sorted(pt, key=lambda pt: pt["score"], reverse=True)
    else:
        return encryption(cipher, key)


def single_xor(input_string: str, key_value: int) -> str:
    """Return the input_string xored with a key value"""

    return b"".join([bytes([byte ^ key_value]) for byte in input_string])


def scoring_system(input_string: str) -> int:
    """Return the score of input_string"""

    # create a dictionary to store value of frequency
    char_freq = {
        "a": 0.08497,
        "b": 0.01492,
        "c": 0.02202,
        "d": 0.04253,
        "e": 0.11162,
        "f": 0.02228,
        "g": 0.02015,
        "h": 0.06094,
        "i": 0.07456,
        "j": 0.00153,
        "k": 0.01292,
        "l": 0.04025,
        "m": 0.02406,
        "n": 0.06749,
        "o": 0.07507,
        "p": 0.01929,
        "q": 0.00095,
        "r": 0.07587,
        "s": 0.06327,
        "t": 0.09356,
        "u": 0.02758,
        "v": 0.00978,
        "w": 0.02560,
        "x": 0.00150,
        "y": 0.01994,
        "z": 0.00077,
        " ": 0.12000,
    }

    return sum([char_freq.get(chr(byte), 0) for byte in input_string.lower()])


def single_xor_decode(c: str) -> dict:
    """Return the decoded message."""

    result = []
    # XOR the encoded message with key from 0 to 255
    for key in range(256):
        # get the output message
        message = single_xor(c, key)

        output = {
            "message": message, 
            "score": scoring_system(message), 
            "key": key
            }
        result.append(output)

    # get the item with the maximum score
    return sorted(result, key=lambda result: result["score"], reverse=True)[0]


def hamming_dist(bytes1: str, bytes2: str) -> int:
    """
    Calculate the hamming distance between two byte string
    """

    return sum(bin(b1 ^ b2).count("1") for b1, b2 in zip(bytes1, bytes2))


# find the keysize of the cipher
def find_keysize(c: str) -> list:
    """
    Find the size of the key used to encrypt the message

    Return top 5 keysize with minimum normalized hamming distance
    """

    key_dist = []  # for storing the average distance of all key sizes

    # the suggested key size is from 2 to 50
    for ks in range(2, 51):

        if ks < len(c):
            # we will take at most 4 block
            block_count = min(len(c) // ks, 4)

            # calculate the normalized hamming distance 
            dt = [
                (hamming_dist(c[i*ks:(i + 1)*ks], c[(i + 1)*ks:(i + 2)*ks]))
                for i in range(0, block_count)
            ]

            result = {
                "keysize": ks,
                # calculate the average distance of keysize
                "avg_distance": sum(dt) / len(dt),
            }

            # add the keysize and distance to the distance list
            key_dist.append(result)

    # get the top 5 keysize with the smallest average distance
    key_size = sorted(key_dist, key=lambda keysize: keysize["avg_distance"])[:5]

    return key_size


def find_key(c: str, ks: int) -> str:
    """
    Return the key of keysize length for the ciphertext
    """

    key = b""

    for index in range(ks):
        # group the cipher by keysize
        block = b"".join([bytes([c[i]]) for i in range(index, len(c), ks)])

        # decode the block
        key += bytes([single_xor_decode(block)["key"]])
    return key


if __name__ == "__main__":
    msg = input("[*] Enter Message: ").encode()
    key = input("[*] Enter Key: ").encode()
    cipher = encryption(msg, key).hex()
    print("[*] Ciphertext:", cipher)
    decode = decryption(unhex(cipher))
    print("[*] Decoded Output (Top 5 Output):")
    for pt in decode:
        print("[----] Text:", pt["plaintext"])
        print("[----] Key:", pt["key"])


""" Sample Input And Output

[*] Enter Message: We do what we can to dull the pain
[*] Enter Key: ICE
[*] Ciphertext: 1e26652d2c653e2b243d63322c6326282d653d2c652d362925633121266539222c27
[*] Decoded Output (Top 5 Output):
[----] Text: b'\x19                                 '
[----] Key: b'\x07\x06E\r\x0cE\x1e\x0b\x04\x1dC\x12\x0cC\x06\x08\rE\x1d\x0cE\r\x16\t\x05C\x11\x01\x06E\x19\x02\x0c'
[----] Text: b'Sd                              ae'
[----] Key: b'MBE\r\x0cE\x1e\x0b\x04\x1dC\x12\x0cC\x06\x08\rE\x1d\x0cE\r\x16\t\x05C\x11\x01\x06E\x19\x02'
[----] Text: b'Teb                            ho '
[----] Key: b'JC\x07\r\x0cE\x1e\x0b\x04\x1dC\x12\x0cC\x06\x08\rE\x1d\x0cE\r\x16\t\x05C\x11\x01\x06E\x19'
[----] Text: b'We do what we can to dull the pain'
[----] Key: b'ICE'
[----] Text: b'[c hi {nax&wi&cmh xi hsl`&tdc |gib'
[----] Key: b'EE'

"""
