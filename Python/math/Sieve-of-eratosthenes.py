"""
The sieve of Eratosthenes is an algorithm for finding all prime numbers up to any given limit. 
It is computationally highly efficient algorithm.Let us take the number `n = 100` , so we create list from `2` to `100` . According to the algorithm , we mark all the numbers which are divisible by `2` which are greater than or equal to the square of it . Then we move to the next number `3` , 
we mark all the numbers which are divisible by `3`  which are greater than or equal to the square of it. 
we continue this process until the square of the number is greater than `n`. 
The numbers which are unmarked in the list are the prime numbers less than `n`.
"""


def sieve_of_eratosthenes(n):
    sieve = [True for i in range(n + 1)]
    p = 2
    while p ** 2 <= n:
        if sieve[p] == True:
            i = p * p
            while i <= n:
                sieve[i] = False
                i += p
        p += 1
    for i in range(2, len(sieve)):
        if sieve[i] == True:
            print(i, end=" ")


def main():
    print("Enter the number upto which prime numbers are to be computed: ")
    n = int(input())
    print("The number of prime numbers less than " + str(n) + " is :")
    sieve_of_eratosthenes(n)


if __name__ == "__main__":
    main()


"""
Sample I/O:

Enter the number upto which prime numbers are to be computed:
30
The number of prime numbers less than 30 is :
2 3 5 7 11 13 17 19 23 29

Time complexity : O(n*(log(log(n))))
Space complexity : O(n)
"""
