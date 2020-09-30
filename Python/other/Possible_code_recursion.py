# Given a string s, and assuming that a=1, b=2, c=3, d=4, .... z=26
# Python recursive function to print all the possible codes for the strings.


def output(original, previous):

    if len(original) == 0:  # if length is zero print 0th value i.e., '`'
        print(previous)
        return
    if len(original) == 1:
        print (previous + chr(96 + int(original)))  # checking range
        return

    if int(original[0:2]) < 27:
        new_character = chr(96 + int(original[0:2]))  # getting  new character
        output(original[2:], previous + new_character)
    new_character = chr(96 + int(original[0:1]))
    output(original[1:], previous + new_character)

# driver code
if __name__ == '__main__':
    string = input()
    output(string, '')

'''
Sample I/O:
    Input:
    1123
    Output:
    kw
    kbc
    alc
    aaw
    aabc

Time Complexity: O(N) ,where N =String
Space Complexity: O(1)
'''
