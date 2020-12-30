"""
Inversion: Inversion Count for an array indicates – how far (or close)
        the array is from being sorted. If the array is already sorted then
        inversion count is 0. If the array is sorted in the reverse order that
        inversion count is the maximum.
        Formally speaking, two elements a[i] and a[j] form an inversion
        if a[i] > a[j] and i < j.

Purpose: Given an array A of length N containing distinct integers from 1
        to N. If we make 2 sets containing N numbers, one arranged serially
        another in the give array order. If we connect the i_th number from
        the 1st set to the i_th number in the second set, Find the number of
        intersection.
        Example: A = [1, 2, 5, 4, 3]

          SET 1         SET 2
		   (1)-----------(1)
		   (2)-----------(2)
		   (3)		     (5)
		     \		     /
		      \		    /
		  (4)--X-------X----(4)
                \     /
                 \   /
                  \ /
                   X
                  / \
                 /   \
		     	/     \
              (5)     (3)

        Number of intersection = 3

Method: Divide and Conquer / Merge-Sort
Intuition: This is a typical problem for Divide and Conquer algorithm also
            referred to as the inversion problem.
        1. The idea is similar to merge sort, divide the array into two equal
            or almost equal halves in each step until the base case is reached.
        2. Create a function merge that counts the number of inversions when
            two halves of the array are merged, create two indices i and j, i
            is the index for the first half and j is an index of the second half.
            if a[i] is greater than a[j], then there are (mid – i) inversions
            because the left and right subarrays are sorted, so all the remaining
            elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
        3. Create a recursive function to divide the array into halves and find
            the answer by summing the number of inversions is the first half,
            number of inversion in the second half and the number of inversions
            by merging the two.
        4. The base case of recursion is when there is only one element in the given half.

Reference: https://www.geeksforgeeks.org/counting-inversions/

Time Complexity:    O(N*log_N)
Space Complexity:   O(N)

Argument:  List
Return:    Integer

"""

# Main Function


def Count_Inversion(arr):
    return Sort_n_Count(arr)[1]


# Modified Merge-sort function to sort and count inversions
def Sort_n_Count(arr):

    n = len(arr)

    # Base Case: if length of the array is 1
    if(n == 1):
        return arr, 0

    # To count the inversions
    count = 0

    # Sort and count the first and second half of the array
    temp1, x = Sort_n_Count(arr[:n // 2])
    temp2, y = Sort_n_Count(arr[n // 2:])
    count += x + y

    i, j = 0, 0
    len1 = n // 2
    len2 = n - n // 2
    sorted_array = []

    # Merge and count the inversions from first and second half
    while(i != len1 and j != len2):
        if(temp1[i] <= temp2[j]):
            sorted_array.append(temp1[i])
            i += 1
        else:
            sorted_array.append(temp2[j])
            j += 1
            count += len1 - i

    while(i != len1):
        sorted_array.append(temp1[i])
        i += 1
    while(j != len2):
        sorted_array.append(temp2[j])
        j += 1

    # Return the sorted array and inversion count
    return sorted_array, count


# --------------------------------DRIVER CODE ---------------------------------


if __name__ == "__main__":
    print("Enter the array: ", end='')
    a = [int(i) for i in input().split()]

    ans = Count_Inversion(a)

    print("Number of intersection = ", ans)

"""
Sample Input / Output

Enter the array: 1 2 5 4 3
Number of intersection =  3

Enter the array: 1 2 3 4 5 6
Number of intersection =  0

          SET 1            SET 2
           (1)--------------(1)
		   (2)--------------(2)
		   (3)--------------(3)
		   (4)--------------(4)
		   (5)--------------(5)
		   (6)--------------(6)


Enter the array: 2 3 4 5 1
Number of intersection =  4

          SET 1         SET 2
		   (1)
             \
		      \
		  (2)--X-----------(2)
                \
          (3)----X---------(3)
                  \
          (4)-------X------(4)
                     \
		  (5)---------X----(5)
                       \
                        \
                         (1)
"""
