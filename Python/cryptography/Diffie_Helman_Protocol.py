"""
    Introduction:
        Symmetric encryption is a powerful encryption strategy used for transferring digital
        information over an in-secure channer. For this however we need a key which is present
        with both the Sender and the Receiver. The same key would be used for the encryption and
        decryption. However, exchange of the symmetric key needs to be secure to ensure that the
        transmitted data is not tampered with. Here comes, Diffie Helman Key Exchange protocol using
        which two parties can generate a common symmetric key based on the data transmitted between them.
        The symmetric key, however is never shared directly between the two parties.

    Purpose:
        The code segment below mimics the diffie helman protocol in the real world. It shows the flow
        of information from the beginning of a connection till the end where both parties have
        successfully generated a symmetric key at their respective ends.
"""

import random
from math import sqrt

def miller_rabin(num):
    """
        Probabilistic measure to check whether a large number is a prime or not
    """

    # Find d in d*2^r
    r = 0
    d = num-1
    while d % 2 == 0:
        d //= 2
        r += 1
    a = random.randint(2, num-2)

    result = fast_exponentiation(a, d, num)
    if result == 1 or result == num-1:
        # Is a prime number
        return True

    while d != num-1:
        result = (result*result) % num
        d *= 2
        if result == 1:
            # Is a composite number
            return False
        if result == num-1:
            # Is a prime number
            return True

    # Is a composite number
    return False

def get_prime(start=20, end=25):
    """
        Generates a prime number in the inclusive range [2**start, 2**end]. Default value of\
        start is 20 and end is 25.
    """

    n = random.randint(2**start, 2**end)
    while n % 2 == 0:
        n = random.randint(2**start, 2**end)

    if not miller_rabin(n):
        # Recursively call itself, unless a prime is found
        return get_prime(start, end)

    # Return the prime number
    return n

def fast_exponentiation(base, exp, n):
    """
        Iteratively finds the result of the expression (base**exp) mod n
    """

    bin_exp = bin(exp)[2:]
    output = 1
    for i in bin_exp:
        output = (output ** 2) % n
        if i == "1":
            output = (output*base) % n
    return output

def findPrimeFactors(n):
    """
        Returns all the prime factors of a number n in a set()
    """

    s = set()

    # Print the number of 2s that divide n
    while (n % 2 == 0):
        s.add(2)
        n = n // 2

    # n must be odd at this po. So we can
    # skip one element (Note i = i +2)
    for i in range(3, int(sqrt(n)), 2):
        # While i divides n, print i and divide n
        while (n % i == 0):
            s.add(i)
            n = n // i

    # This condition is to handle the case
    # when n is a prime number greater than 2
    if (n > 2):
        s.add(n)
    return s

def find_root(n):
    """
        Returns the primitive root for a finite field
    """

    phi = n-1
    factors = findPrimeFactors(phi)
    for r in range(2, phi + 1):
        # Iterate through all prime factors of phi.
        # and check if we found a power with value 1
        flag = False
        for it in factors:

            # Check if r^((phi)/primefactors)
            # mod n is 1 or not  
            if (fast_exponentiation(r, phi // it, n) == 1):

                flag = True
                break

        # If there was no power with value 1.
        if (flag == False): 
            return r  

    # If no primitive root found
    return None

class Diffie_Helman:
    """
        Contains static methods to be used in order to perform tasks related to
        the Diffie Helman Key Exchange protocol.
    """

    @staticmethod
    def initialize():
        ## Generate prime number

        # # For testing, take prime = 761
        prime = 761
        
        # prime = get_prime(start=10, end=15)
        root = find_root(prime)
        if root is None:
            # Recursively calls itself till a primtive root exists for a prime number
            return Diffie_Helman.initialize()

        print("\nPublic Variables:\nPrime Number: {}\nPrimitive Root: {}\n".format(prime, root))
        return (prime, root)


    @staticmethod
    def generate_key(prime, root):
        """Generate a pair of public and private keys based on the given details"""

        k_pri = random.randint(2, prime-2)
        k_pub = fast_exponentiation(root, k_pri, prime)
        return {"pub":k_pub, "pri":k_pri}

class User:
    """
        Instantiates a user class, to generate and exchange keys
    """

    def __init__(self, name=None, prime=None, root=None):
        """Establishes the value of name, prime number and primitive root for a user"""

        if name is None:
            raise Exception("Invalid name")
        if prime is None:
            raise Exception("Invalid prime value")
        if root is None:
            raise Exception("Invalid root value")
        self.name = name
        self.prime = prime
        self.root = root


    def keygen(self):
        """Generate a pair of public and private keys using the already set prime number and\
            primitive root"""

        keys = Diffie_Helman.generate_key(self.prime, self.root)
        self.k_pri = keys["pri"]
        self.k_pub = keys["pub"]
        return self.k_pub

    def exchange(self, public):
        self.result = fast_exponentiation(public, self.k_pri, self.prime)
        print(self)

    def __str__(self):
        return "User: {}\nPublic Key: {}\nFinal Key: {}\n".format(self.name, self.k_pub, self.result)


if __name__ == '__main__':
    # Generate a prime number and primitive root of the finite field
    prime, root = Diffie_Helman.initialize()

    # Share the two elements with different users
    alice = User("Alice", prime, root)
    bob = User("Bob", prime, root)

    alice_public = alice.keygen()
    bob_public = bob.keygen()

    # Exchange each other's public keys. Both users can now generate a private key by themselves
    alice.exchange(bob_public)
    bob.exchange(alice_public)

"""
    Sample Input Output-
        Input: 
            None

        Output:
            Public Variables:
            Prime Number: 761
            Primitive Root: 6

            User: Alice
            Public Key: 476
            Final Key: 465

            User: Bob
            Public Key: 291
            Final Key: 465

    Time Complexity:
        Miller Rabin Primality: O(k.log^3.n), n is the prime number and k is the no of rounds
        Modular Exponentiation: O(n)
"""
