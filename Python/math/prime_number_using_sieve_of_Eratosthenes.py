def sieve_of_Eratosthenes(num):

    not_prime_num = set()
    prime_nums = []

    for i in range(2, num+1):
        # checks if the number is in the not_prime_num list
        if i in not_prime_num:
            continue

        # if number absent in not_prime_num then add that number to prime_num list
        # and every multiple of that number to the not_prime_num list
        for f in range(i*2, num+1, i):
            not_prime_num.add(f)

        prime_nums.append(i)

    # returns a list of prime numbers less then the given number
    return prime_nums


if __name__ == "__main__":
    user_input = int(input("Enter a sequence of comma seprated numbers: "))

    # calling the sieve_of_Eratosthenes function
    prime_numbers = sieve_of_Eratosthenes(user_input)
    print(prime_numbers)
