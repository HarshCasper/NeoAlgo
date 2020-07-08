# This is the main code for the problem! Driver code should be same as present on HackerRank!

def isPalindrome(s):
    for idx in range(len(s)//2):
        if s[idx] != s[len(s)-idx-1]:
            return False
    return True
 
def palindromeIndex(s):
    for idx in range((len(s)+1)//2):
        if s[idx] != s[len(s)-idx-1]:
            if isPalindrome(s[:idx]+s[idx+1:]):
                return idx
            else:
                return len(s)-idx-1
    return -1