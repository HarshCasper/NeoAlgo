'''
Activity Selection Problem :
Given "row" number of activities with start and end time,
select activities in such manner that we can perform maximum
number of activities among them. Note, activities are not sorted.
Approach used is greedy, sorting the activities according to their
end time and then comparing it with start time of next one.
If start time is greater than or equal to the previous activity
end time then it can be completed and hence added in the solution matrix.
'''


def final_activities():
    row = int(input("Enter the number of rows: "))
    # 2d list is used to enter the start and end time of jobs
    Activity = []
    print("Enter elements of matrix row wise:")
    for x in range(row):
        print("Elements of row", end = " ")
        print(x)
        arr = []
        for _ in range(0, 2):
            arr.append(int(input()))
        Activity.append(arr)
    # sorting the 2d list according to the second key
    Activity.sort(key=lambda sec: sec[1])

    ptr = 0
    # matrix for activities selceted
    activity_selected = []
    # initial activity is always selected
    activity_selected.append(Activity[ptr])

    # If the starting time of next activity is greater than/equal
    # to the end time of previous, then it will be selected
    for itr in range(1, row):
        if Activity[ptr][1] <= Activity[itr][0]:
            activity_selected.append(Activity[itr])
            ptr = itr
    # printing the selected activities
    print("Following activities are selected :")
    print(activity_selected)


if __name__ == "__main__":
    final_activities()


'''
Sample Input:
Enter the number of rows: 
4
Enter elements of matrix row wise:
Elements of row 0
1
2
Elements of row 1
2
4
Elements of row 2
3
5
Elements of row 3
4
6

Sample Output:
Following activities are selected :
[[1, 2], [2, 4], [4, 6]]

Time Complexity: O(nlogn), n = row, for sorting the list
Space Complexity: O(2*n), n = row, for making the matrix "activity_selected"

'''
