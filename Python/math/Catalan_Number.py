"""
Purpose: Calculate Nth Catalan Number

Argument : Integer
Return   : Integer ( Nth Catalan Number)

Time Complexity:  O(n)
Space Complexity: O(n)

Note: The Catalan Number can be to large, hence answer
        is given mod of 10**9.
"""
# Catalan_Number (N) = ((2*N)!) / ((N+1)!*N!)

# Global Variables
MOD = 10**9+7
facto = [1]  # Factorial Table

# To construct the factorial numbers using DP


def factorial(n):
    global facto
    for i in range(1, n+1):
        facto += [(facto[-1]*i) % MOD]


# For Modular Inverse of num with respect to 10^9+7
def Mod_Inv(num):
    return pow(num, MOD-2, MOD)


def Catalan_Number(num):
    if num == 0 or num == 1:
        return 1
    factorial(2*num)
    Numerator = facto[2*num]
    Denominator = (facto[num+1]*facto[num]) % MOD

    Catalan = (Numerator * Mod_Inv(Denominator)) % MOD
    return Catalan

# ------------------------DRIVER CODE ------------------------


if __name__ == "__main__":
    n = int(input("Enter the number: "))
    print(n, "th Catalan Number = ", Catalan_Number(n), sep="")

"""
SAMPLE INPUT/OUTPUT

Enter the number: 5
5th Catalan Number = 42

Enter the number: 10
10th Catalan Number = 16796
"""
