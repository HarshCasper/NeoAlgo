"""
    Introduction:
        Two pointer technique is an optimization technique which is a really clever way of using
        brute-force to search for a particular pattern in a sorted list.

    Purpose:
        The code segment below solves the Three Sum Problem. We have to find a triplet out of the
        given list of numbers such that the sum of that triplet equals to another given value.
        The Naive Approach is to calculate the sum of all possible triplets and return the one with
        the required sum or None. This approach takes O(N^3) time to run. However, by using Two pointer
        search technique we can reduce the time complexity to O(N^2).

    Method:
        Three Sum Problem using Two Pointer Technique
"""

def three_sum_problem(numbers, sum_val):
    """
        Returns a triplet (x1,x2, x3) in list of numbers if found, whose sum equals sum_val, or None
    """

    # Sort the given list of numbers
    # Time complexity: O(N.logN)
    numbers.sort()
    size = len(numbers)

    # Two nested loops
    # Time complexity: O(N^2)
    for i in range(size-3+1):
        # Reduce the problem to two sum problem
        two_sum = sum_val - numbers[i]
        
        # Initialize the two pointers
        left = i+1
        right = size-1
        
        # Search in the array until the two pointers overlap
        while left < right:
            curr_sum = numbers[left] + numbers[right]

            # Update the pointers
            if curr_sum < two_sum:
                left += 1
            elif curr_sum > two_sum:
                right -= 1
            else:
                # Return the numbers that form the desired triplet
                return "({},{},{})".format(numbers[i], numbers[left], numbers[right])
    
    # No triplet found
    return None



def main():
    """
        Takes user input and calls the necessary function
    """

    # Take user input
    numbers = list(map(int, input("Enter the list of numbers: ").split()))
    sum_val = int(input("Enter the value of sum: "))

    # Find the triplet
    triplet = three_sum_problem(numbers, sum_val)

    if triplet is None:
        print(f"No triplet found with sum: {sum_val}")
    else:
        print(f"{triplet} is the triplet with sum: {sum_val}")


if __name__ == "__main__":
    # Driver code
    main()


"""
    Sample Input 1:
    Enter the list of numbers: 12 3 4 1 6 9
    Enter the value of sum: 24

    Sample Output 1:
    (3,9,12) is the triplet with sum: 24

    Time Complexity:
    For sorting:                O(N.log N)
    For two-pointer technique:  O(N^2)
    T = O(N.log N) + O(N^2)
    T = O(N^2)
"""