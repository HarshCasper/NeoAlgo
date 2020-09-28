"""Algorithm to find the first non-repeating character in a string
Input the string from the user.
Start traversing the string using two loops.
Use the first loop to scan the characters of the string one by one.
Use the second loop to find if the current character is occurring
in the latter part of the string or not.
If it is not occurring, print that character.
Else, continue traversing.
"""


def firstNotRepeatingCharacter(string):
    for i in range(len(string)):
        flag = False
        for j in range(len(string)):
            if string[i] == string[j] and i != j:
                flag = True
        if not flag:
            return string[i]
    return "_"

string = input("Enter a string: ")
index = firstNotRepeatingCharacter(string)
if index is None:
    print('No non repeating character found.
          All the characters are repeating.')
else:
    ind = string.find(index)
    print("Non Repeating character " +
          str(string[ind]) + " found at index " + str(ind))

"""
Sample input 1:
Input: "abaacd"
Output: Non Repeating character b found at index 1
Sample input 2:
Input:"aabbccdd"
Output: No non repeating character found. All the characters are repeating.
Time Complexity: O(n*2) - n being the length of string
Space Complexity: O(n)
    """
