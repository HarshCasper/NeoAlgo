"""
Given a sorted array and a target value,
return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

"""
# taking the input from the user

x = list(map(int, input("Enter the elements in the list: ").strip().split()))
target = int(input("Enter the Element whose index has to be found: "))

# finding whether the target value is in the list or not

if target in x:
    a = x.index(target)
    print(
        "The number is present at the index {}.".format(a)
    )  # if target is present then printing the index
else:
    x.append(target)  # adding the target in the list
    x.sort()  # sorting the list
    a = x.index(target)
    print(
        "Number not found. It can be inserted at index {}.".format(a)
    )  # printing the target index

