'''
- Phone Keypad Sequence:
    Given a keypad as shown in the diagram, and an n digit number,
    list all words which are possible by pressing these numbers.
- Example:
    Input number: 23

    Output: ad ae af
            bd be bf
            cd ce cf
- Approach :
    1. As observed each digit can represent 3 to 4 different
    alphabets (except 0 and 1)
    2. Map each number with its keypad string equivalent.
    3. Use recrsive function to try all alphabets mapped to the
    current digit in alphabetic order, and again call the recursive
    function for the next digit and will pass on the current output string.
'''

keypad = [
    # 0 and 1 digit don't have any characters associated
    [],
    [],
    ['a', 'b', 'c'],
    ['d', 'e', 'f'],
    ['g', 'h', 'i'],
    ['j', 'k', 'l'],
    ['m', 'n', 'o'],
    ['p', 'q', 'r', 's'],
    ['t', 'u', 'v'],
    ['w', 'x', 'y', 'z']
]
# input number in the form of a list (number cannot start from 0 or 1)
input_num = [2, 3]


def printAllCombinations(index, result=""):
    # if we have processed every digit of the key, print the result
    if index == -1:
        print(result, end=' ')
        return

    # stores the current digit
    digit = input_num[index]

    # get the size of the list corresponding to the current digit
    length = len(keypad[digit])

    # one by one, replace the digit with each character in the corresponding
    # list and recur for the next digit
    for i in range(length):
        printAllCombinations(index -
                             1, keypad[digit][i] + result)


printAllCombinations(len(input_num) - 1)


# - Output
#    ad ae af bd be bf cd ce cf

# - Complexity Analysis :
#     Time Complexity : O(4^n)
#         here as each digit of the number has 3 or 4 alphabets
#         we have taken the upper bound
#         so that all cases can be incorporated in it.

#     Space Complexity :
#         O(1)
#         No extra space is needed

#         Note: Each recursive approach consumes a definite amount of
#         space called call stack for it's execution but for simplicity
#         purpose I've not taken that into account.
