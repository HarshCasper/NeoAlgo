# This is the main code for the problem! Driver code should be same as present on HackerRank!

def check_pallindrome(string, start, end):
    if start == 0:
        if string[start: end + 1] == string[end:: -1]:
            return True

    else:
        if string[start: end + 1] == string[end: start - 1: -1]:
            return True

    return False


def pallindrome_index(string):
    if check_pallindrome(string=string, start=0, end=len(string) - 1):
        return -1
    else:
        for i in range(len(string)):
            if check_pallindrome(string=string, start=i + 1, end=len(string) - 1 - i):
                return i
            if check_pallindrome(string=string, start=i, end=len(string) - 2 - i):
                return len(string) - 1 - i
