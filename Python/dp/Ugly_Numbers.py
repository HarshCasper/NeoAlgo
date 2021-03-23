"""
Ugly Number : Ugly numbers are numbers whose only prime factors
         are 2, 3 or 5. By convention, 1 is included.The sequence
         1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first
         11 ugly numbers.

Purpose: Return the Nth smallest Ugly Number
Method:  Dynamic Programing
Intution: The ugly-number sequence is 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
     because every number can only be divided by 2, 3, 5, one way to
     look at the sequence is to split the sequence to three groups as below:

        (1) 1×2, 2×2, 3×2, 4×2, 5×2, …
        (2) 1×3, 2×3, 3×3, 4×3, 5×3, …
        (3) 1×5, 2×5, 3×5, 4×5, 5×5, …

      We can find that every subsequence is the ugly-sequence itself
      (1, 2, 3, 4, 5, …) multiply 2, 3, 5. Then we use similar merge method as
      merge sort, to get every ugly number from the three subsequence.
      Every step we choose the smallest one, and move one step after.

Time Complexity: O(N)
Space Complexity: O(N)

Argument: Integer
Return  : Integer (Nth smallest Ugly Number)

"""


def Ugly_Number(num):

    # Initilize the DP table for ugly Number
    # Base Case: 1 is considered to be the first Ugly Number
    ugly_num = [1]

    # Store the multiples of 2, 3, 5
    two = 2
    three = 3
    five = 5

    # start the indexing of the table from 0
    in2 = in3 = in5 = 0

    # Push the next N ugly number into the DP table
    for i in range(1, n):

        # Extract the next Ugly Number in the seriese
        next_ugly = min(two, three, five)

        # Push the next_ugly into the table
        ugly_num.append(next_ugly)

        # For all the three factors, check wether it is equal to the next_ugly
        # if yes then increase the top by 1 and assign the respective value
        if next_ugly == two:
            in2 += 1
            two = ugly_num[in2] * 2

        if next_ugly == three:
            in3 += 1
            three = ugly_num[in3] * 3

        if next_ugly == five:
            in5 += 1
            five = ugly_num[in5] * 5

    # Return the last element in the table which is the
    # Nth smallest Ugly Number
    return ugly_num[-1]


# --------------------------------- DRIVER CODE -------------------------------


if __name__ == "__main__":
    n = int(input("Enter the number: "))

    # Calling the Ugly_Number() function
    answer = Ugly_Number(n)
    print(n, "th Ugly Number = ", answer, sep="")

"""
Sample Input / Output

Enter the number: 10
10th Ugly Number = 12


Enter the number: 100
100th Ugly Number = 1536


Enter the number: 1000
1000th Ugly Number = 51200000


Enter the number: 100000
100000th Ugly Number = 290142196707511001929482240000000000000
"""
