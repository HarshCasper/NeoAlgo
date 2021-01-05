'''
~~~ RABIN KARP ALGORITHM: ~~~
This algorthm is used to search a pattern
in the given text.
Time complexity of the algorithm:
    best case: O(n+m)
    worst case: O(nm)
    where n and m are lengths of text and pattern
'''

def hash(text, pattern, d, q):
    '''
    function to calculate hash values of text
    and pattern
    parameters: text, pattern, base value,
        large enough prime number
    returns: a tuple containing hash of text
       and pattern
    '''
    p = 0
    t = 0
    m = len(pattern)
    # calculate hash for each window of size m
    # from both text and pattern
    for i in range(m):
        p = (d*p + ord(pattern[i])) % q
        t = (d*t + ord(text[i])) % q
    return (p,t)

def rabinKarp(pattern, text):
    '''
    function to perform search using rabin karp
    algorithm
    parameters: pattern and text
    returns: a list containing positions of matching
        sequences
        (or) -1 if not found
    '''
    m = len(pattern)    #length of pattern
    n = len(text)       #length of text
    # base of the numerical system
    d = 10
    # large enough prime number
    q = 101
    # list to store search results
    arr = []

    p = 0
    t = 0
    h = 1
    i = 0
    j = 0
    flag = False

    # check if length of pattern is greater than text
    # if yes then return
    if(m > n):
        arr.append(-1)
        return arr

    for i in range(m-1):
        h = (h*d) % q

    # calculate hash value for pattern and text
    (p, t) = hash(text, pattern, d, q)
    
    # find the match
    for i in range(n-m+1):
        if p == t:
            for j in range(m):
                if text[i+j] != pattern[j]:
                    break

            j += 1
            if j == m:
                # pattern found at index i
                # change flag status and append to list
                flag = True
                arr.append(i+1)

        if i < n-m:
            t = (d*(t-ord(text[i])*h) + ord(text[i+m])) % q

            if t < 0:
                t = t+q

    if( not flag):
        # pattern not found...append -1 to list and return
        arr.append(-1)

    return arr

def main():
    text = input("Text:")
    pattern = input("Pattern:")
    listing =  rabinKarp(pattern,text)

    if(listing == [-1]):
        print("Pattern not found")
    else:
        print (f"Pattern found at positions {listing}")

if __name__ == "__main__":
    main()
