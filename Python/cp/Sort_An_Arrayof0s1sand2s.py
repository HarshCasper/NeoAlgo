def sort012(arr,n):
    listofZero = []
    listofOne = []
    listofTwo = []

    for i in range(0,n):
        if arr[i] == 0:
            listofZero.append(0)
        elif arr[i] == 1:
            listofOne.append(1)
        else:
            listofTwo.append(2)

    Total = listofZero+listofOne+listofTwo
    return Total 




arr = list(map(int,input("Enter the Number:\n").split()))
n = len(arr)
print(sort012(arr,n))

'''
Time Complexity is O(n)
Space Complexity is O(1)

Input: 
Enter the Number:
0 2 1 2 0

Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
'''