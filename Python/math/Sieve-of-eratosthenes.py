'''
The sieve of Eratosthenes is an algorithm for finding 
all prime numbers up to any given limit. It is 
computationally highly efficient algorithm.
'''


def sieve_of_eratosthenes(n):
    sieve = [True for i in range(n + 1)]
    p = 2
    while p ** 2 <= n:
        if sieve[p]:
            i = p * p
            while i <= n:
                sieve[i] = False
                i += p
        p += 1
    length = len(sieve)
    for i in range(2, length):
        if sieve[i]:
            print(i, end=" ")


def main():
    print("Enter the number upto which prime numbers are to be computed: ")
    n = int(input())
    print("The number of prime numbers less than " + str(n) + " is :")
    sieve_of_eratosthenes(n)


if __name__ == "__main__":
    main()


'''
Sample I/O:

Enter the number upto which prime numbers are to be computed:
30
The number of prime numbers less than 30 is :
2 3 5 7 11 13 17 19 23 29

Time complexity : O(n*(log(log(n))))
Space complexity : O(n)
'''
