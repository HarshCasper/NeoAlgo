# Python program to toggle the k-th bit of a number.
def toggle(num, k):
    return (num ^ (1 << (k-1)))


if __name__ == '__main__':
    print("Enter the number: ", end="")
    n = int(input())
    print("Enter the value of k(where you need to toggle the k'th bit): ", end="")
    b = int(input())
    res = toggle(n, b)
    print("The given number, after toggling the k-th bit is {}".format(res))

"""
Time Complexity: O(1)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 24
Enter the value of k(where you need to toggle the k'th bit): 3
The given number, after toggling the k-th bit is 28.

SAMPLE 2
Enter the number: 33
Enter the value of k(where you need to toggle the k'th bit): 12
The given number, after toggling the k-th bit is 2081.
"""
