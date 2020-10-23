from binascii import unhexlify as unhex


def encryption(message : str, key: int) -> str:
    ''' Return the ciphertext by xor the message with a repeating key
    '''

    return b''.join([bytes([message[i] ^ key[i % len(key)]]) for i in range(len(message))]
)


def decryption(cipher: str) ->  str:
    '''
    Decode repeating xor
    '''

    #find keysize
    keysize = find_keysize(cipher)

    pt = []
    for ks in keysize:
        #find key
        key = find_key(cipher, ks['keysize'])
        #return plaintext
        plaintext = encryption(cipher, key)
        pt.append({'plaintext':plaintext, 'key': key ,'score': scoring_system(plaintext)})

    return sorted(pt, key = lambda pt: pt['score'], reverse=True)


def single_xor(input_string :  str, key_value : int) -> str:
    ''' Return the input_string xored with a key value
    '''

    return b''.join([bytes([byte ^ key_value]) for byte in input_string])


def scoring_system(input_string : str) -> int:
    '''Return the score of input_string
    '''

    #create a dictionary to store value of frequency
    char_freq = {
        'a': 0.08497, 'b': 0.01492, 'c': 0.02202, 'd': 0.04253,
        'e': 0.11162, 'f': 0.02228, 'g': 0.02015, 'h': 0.06094,
        'i': 0.07456, 'j': 0.00153, 'k': 0.01292, 'l': 0.04025,
        'm': 0.02406, 'n': 0.06749, 'o': 0.07507, 'p': 0.01929,
        'q': 0.00095, 'r': 0.07587, 's': 0.06327, 't': 0.09356,
        'u': 0.02758, 'v': 0.00978, 'w': 0.02560, 'x': 0.00150,
        'y': 0.01994, 'z': 0.00077, ' ': 0.12000
    }

    return sum([char_freq.get(chr(byte),0) for byte in input_string.lower()])


def single_xor_decode(c : str) -> dict:
    ''' Return the decoded message.
    '''

    result = []
    #XOR the encoded message with key from 0 to 255
    for key in range(256):
        #get the output message
        message = single_xor(c, key)

        output = {
            'message': message,
            'score': scoring_system(message),
            'key': key
        }
        result.append(output)

     # get the item with the maximum score
    return sorted(result, key = lambda result: result['score'], reverse=True)[0]



def hamming_dist(bytes1: str, bytes2: str) -> int:
    """
    Calculate the hamming distance between two byte string 
    """

    return sum(bin(b1^b2).count('1') for b1, b2 in zip(bytes1, bytes2))



#find the keysize of the cipher
def find_keysize(c: str) -> list:
    """
    Find the size of the key used to encrypt the message

    Return top 5 keysize with minimum normalized hamming distance
    """

    key_dist = [] # for storing the average distance of all key sizes

    # the suggested key size is from 2 to 50
    for ks in range(2, 51):

        if ks < len(c):
            #we will take at most 4 block 
            block_count = min(len(c) // ks, 4)

            #calculate the normalized hamming distance between two string of the same length
            dt = [(hamming_dist(c[i * ks : (i +1) * ks], c[(i + 1) * ks : (i + 2) * ks])) for i in range(0, block_count)]
            
            result = {
                'keysize' : ks,
                #calculate the average distance of keysize
                'avg_distance' : sum(dt) / len(dt)
            }

            #add the keysize and distance to the distance list
            key_dist.append(result)

    #get the top 5 keysize with the smallest average distance
    key_size = sorted(key_dist, key = lambda keysize: keysize['avg_distance'])[:5]

    return key_size



def find_key(c: str, ks: int) -> str:
    '''
    Return the key of keysize length for the ciphertext
    '''

    key = b''

    for index in range(ks):
        #group the cipher by keysize
        block = b''.join([bytes([c[i]]) for i in range(index, len(c), ks)])

        #decode the block
        key += bytes([single_xor_decode(block)['key']])
    return key

    

if __name__ == "__main__":
    msg = input("[*] Enter Message: ").encode()
    key = input("[*] Enter Key: ").encode()
    cipher = encryption(msg, key).hex()
    print("[*] Ciphertext:", cipher)
    decode = decryption(unhex(cipher))
    print("[*] Decoded Output (Top 5 Output):")
    for pt in decode:
        print("[----] Text:", pt['plaintext'])
        print("[----] Key:", pt['key'])


''' Sample Input And Output

[*] Enter Message: We do what we can to dull the pain. Pinky promise things still stay the same
[*] Enter Key: YOUNG
[*] Ciphertext: 0e2a752a2879383d2f337938306e243821753a28792b20222b793b3d2b67292e3c2069791f3c202c206f253c283426262b672d273c20202a6f263a2e3523753d333836753a2f3c6f262f2a3c
[*] Decoded Output (Top 5 Output):
[----] Text: b'We do what we can to dull the pain. Pinky promise things still stay the same'
[----] Key: b'YOUNG'
[----] Text: b'@m=ef>prat1w~)lwo2rg7lhme>sre aarg!6Q{hcn(msfsnie ehrghe!ara{d=r}\x7f~:tht hhbs'
[----] Key: b'NGHO'
[----] Text: b"We:df6ar`}7wi!kvo:cg6enmr6tse(pasn'6Fsobn |sgzhir(biroye htall:s}wo:uar \x7f`er"
[----] Key: b'YOONNO'
[----] Text: b"@d:df6vs`}7w~ kvo:tf6enme7tse(g`sn'6Qrobn krgzhie)birond hta{m:s}wx;uar haer"
[----] Key: b'NNO'
[----] Text: b"@e;ef6vra|7w~!jwo:tg7dnme6ure(garo'6Qsncn ksf{hie(chrone!ita{l;r}wx:t`r h`ds"
[----] Key: b'NO'

'''