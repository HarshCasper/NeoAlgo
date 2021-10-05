"""
KMP Algorithm: In computer science, the Knuth–Morris–Pratt string-searching algorithm
        (or KMP algorithm) searches for occurrences of a "word" W within a main 
        "text string" S by employing the observation that when a mismatch occurs, 
        the word itself embodies sufficient information to determine where the next match 
        could begin, thus bypassing re-examination of previously matched characters.

Problem Link: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
Purpose: Pattern searching is an important problem in computer science. 
        When we do search for a string in notepad/word file or browser or 
        database, pattern searching algorithms are used to show the search results.
Method : Dynamic Programming

Time Complexity:  O(N)
Space Complexity: O(N)
Argument : Text(search Domain), Pattern(string to be searched)
Return   : int (index of the first occurrence)

Reffrence: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

"""
# Function to compute the Longest prefix array(lps)
def computeLPSArray(pat, M, lps):

    # intialization of global variables
    len = 0
    lps[0] = 0
    i = 1
  
    # the loop calculates lps[i] for i = 1 to M-1
    while i < M:
        if pat[i]== pat[len]:
            len += 1
            lps[i] = len
            i += 1
        else:
            if len != 0:
                len = lps[len-1]
  
                # Also, note that we do not increment i here
            else:
                lps[i] = 0
                i += 1

# Main Function to be called for the solution
def KMPSearch(txt, pat):
    M = len(pat)
    N = len(txt)
  
    # create lps[] that will hold the longest prefix suffix 
    # values for pattern
    lps = [0]*M
    j = 0 # index for pat[]
  
    # Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps)
  
    i = 0 # index for txt[]
    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1
  
        if j == M:
            print ("Found pattern at index " + str(i-j))
            j = lps[j-1]
  
        # mis match after j matches
        elif i < N and pat[j] != txt[i]:
            # Do not match lps[0..lps[j-1]] characters,
            # they will match anyway
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
if __name__ == "__main__":
    txt = "ABABDABACDABABCABAB"
    pat = "ABABCABAB"
    KMPSearch(txt, pat)
