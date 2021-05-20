"""
This program converts binary code
to gray code. By exor-ing
Example : 011 ->010
"""


def gray(li):
    gray_code = [li[0]]
    for i in range(len(li) - 1):
        n = li[i] ^ li[i + 1]
        gray_code.append(n)
    gray_code = map(str, gray_code)
    gray_code = "".join(gray_code)
    return(gray_code)

if __name__ == '__main__':
    string = input("Enter the binary number ")
    li = []
    li[:0] = string
    li = [int(i) for i in li]
    gray_code = gray(li)
    print(gray_code)

"""
Sample Input-Output:

binary_to_gray.py
Enter the binary number 011
010

Time complexity : O(n)
Space complexity : O(1)
"""


