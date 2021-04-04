"""
Edit Distance using dynamic programming
Problem on Leetcode: https://leetcode.com/problems/edit-distance/

Given two strings, return the minimum number of operations required to convert one word to other.
You can apply the following operatiions:
1. Insert a character
2. Delete a character
3. Replace a character

m: length of first string
n: length of second string
Time Complexity : O(m*n) (Looping through both strings)
Space Complexity : O(m*n) (Matrix distance)
"""


def editDist(first_string, second_string):
    # Length of both strings
    first_length = len(first_string)
    second_length = len(second_string)

    # Distance table for computing edit distance
    # Initializing edit distances as 0
    distance = [[0 for x in range(second_length + 1)]
                for x in range(first_length + 1)]

    # Looping and comparing each letter of first_string with each of second_string
    for first_sub_string in range(first_length + 1):
        for second_sub_string in range(second_length + 1):

            if first_sub_string == 0:
                # first_sub_string is empty, so insert all charecters of second_sub_string
                distance[first_sub_string][second_sub_string] = second_sub_string

            elif second_sub_string == 0:
                # second_sub_string is empty, so insert all charecters of first_sub_string
                distance[first_sub_string][second_sub_string] = first_sub_string

            elif first_string[first_sub_string - 1] == second_string[second_sub_string - 1]:
                # If last charecters of both substring are same, no operation required here
                # It's value will be equal to the edit distance of the substring without this same charecters ie. Diagonal value
                distance[first_sub_string][second_sub_string] = distance[
                    first_sub_string - 1
                ][second_sub_string - 1]

            else:
                # If last charecters of both substring are not same, we can either insert, remove or replace a charecter
                # We choose minimum possible edit distance of the substrings before performing operation
                # and we add 1 to edit distance for the one operation we need to perform to convert first_string to second_string
                distance[first_sub_string][second_sub_string] = 1 + min(
                    distance[first_sub_string][second_sub_string - 1],  # Insert
                    distance[first_sub_string - 1][second_sub_string],  # Remove
                    distance[first_sub_string - 1][second_sub_string - 1],  # Replace
                )
    return distance[first_length][second_length]


if __name__ == '__main__':
    print("Enter First string: ")
    first_string = input()
    print("Enter Second string: ")
    second_string = input()
    print("Minimum number of edits required: ",
          editDist(first_string, second_string))


"""
Sample Input:
Enter First string:
shine
Enter Second string:
sings

Sample Output:
Minimum number of edits required: 3
"""
