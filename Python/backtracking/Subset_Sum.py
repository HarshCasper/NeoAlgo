"""
Purpose: From a list of integers, check and return a set of
        integers whose sum will be equal to the target value K.
Problem Link:- https://en.wikipedia.org/wiki/Subset_sum_problem

Method: Backtracking
Time Complexity:  O(2^n)
Space Complexity: O(n)

Argument: List, Target
Return:   List
"""


# Main Recursive function to find the desired Subset Sum
def Subset_Sum(li, target, ans=[]):

    # Base Cases
    if target == 0 and ans != []:
        return ans

    elif li == []:
        return False

    # li[0] is not included in the answer Subset
    temp = Subset_Sum(li[1:], target, ans)
    if temp:
        return temp

    # li[0] included in the answer Subset
    temp = Subset_Sum(li[1:], target - li[0], ans + [li[0]])

    return temp

# --------------------------- DRIVER CODE------------------------------


if __name__ == "__main__":

    li = [int(i) for i in input("Enter the List of Integers: ").split()]
    Target = int(input("Enter the Target value: "))

    ans = Subset_Sum(li, Target)
    if not ans:
        print("No Subset Sum matched to the Target")
    else:
        print("The Required Subset is : ", *ans)

"""
Sample Input / Output

Enter the List of Integers: 7 9 -3 9 7 4 5 -4 -6 -2 -5
Enter the Target value: -1
The Required Subset is :  5 -6


Enter the List of Integers: 1 2 3 4 5 6 7 8 9
Enter the Target value: 19
The Required Subset is :  5 6 8

Enter the List of Integers: -1 2 6 7 -4 7 5 -2 
Enter the Target value: 0
The Required Subset is :  6 -4 -2
"""
