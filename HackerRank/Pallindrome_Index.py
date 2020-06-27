# Function to check pallindrome or not
def ispallin(s, start, end):
    
    if s[start : end + 1] == s[end : start - 1 : -1]:
        return True

    return False

# Function for checking pallindrome index
def palindromeIndex(s):
    
    l = [i for i in s]
    #r = list(reversed(l))
    
    for i in range(len(l)):
        if l[i] != l[len(l) - i - 1]:
            ind = i if ispallin(l, i + 1, len(l) - 1 - i) else len(l) - 1 - i
            return ind
    
    
    return -1
    
    
    
if __name__ == '__main__':
    
    q = 3

    for q_itr in range(q):
        s = input()

        result = palindromeIndex(s)

        print(str(result) + '\n')


