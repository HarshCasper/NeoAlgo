# Python program to count the number of set bits in a number

def countNumSetBits(num):
    cnt = 0
    while(num > 0):
        cnt = cnt + (num & 1)
        num = (num >> 1)
    return cnt


if __name__ == '__main__':
    print("Enter the number: ")
    num = int(input())
    res = countNumSetBits(num)
    print("The number of set bits present in the given number is $res")


"""
Time Complexity: O(log(n)), where n is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the number: 12354
The number of set bits present in the given number is 4

SAMPLE II

Enter the number: 2048
The number of set bits present in the given number is 1
"""
