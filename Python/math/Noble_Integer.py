''' An integer x is said to be Noble given an array 
if the number of integers greater than x are equal to x.
If noble integer is not found output is -1. 
'''
# To find the noble integer from the given list
def nobleint():
    x = 0
    lst.sort()
    for i in range(0, num - 1):
        if lst[i] == lst[i + 1]:
            continue
        if lst[i] == num - i - 1:
            x = 1
            return num - i - 1
    if x == 0:
        return -1

if __name__ == '__main__':
    num = int(input('Enter the number of elements:'))
    lst = list(map(int, input('Enter the elements:').split()))
    print nobleint(lst, num)

'''
Sample Output

Enter the number of elements:4
Enter the elements:7 3 9 81
3
Enter the number of elements:3
Enter the elements:2 2 2
-1

Complexities
Time Complexity:O(nlogn)
Space Complexity:O(1)
'''

