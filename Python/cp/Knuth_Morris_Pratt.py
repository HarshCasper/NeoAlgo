# Implementation of Knuth Morris Pratt Algorithm in Python
def KMP_Search(pattern, text):
    a = len(text)
    b = len(pattern)
    prefix = prefix_arr(pattern, b)
  
    initial = []
    m = 0
    n = 0
  
    while m != a:
       
        if text[m] == pattern[n]:
            m += 1
            n += 1
      
        else:
            n = prefix[n-1]
       
        if n == b:
            initial.append(m-n)
            n = prefiX[n-1]
        elif n == 0:
            m += 1
   
    return initial
def prefix_arr(pattern, b):
    prefix = [0] * b
    n = 0
    m = 1
    while m != b:
        if pattern[m] == pattern[n]:
            n += 1
            prefix[m] = n
            m += 1
        elif n != 0:
                n = prefix[n-1]
        else:
            prefix[m] = 0
            m += 1
    return prefix_arr
string = input()
pat = input()
print('Pattern is found in string at index',KMP_Search(pat, string))
"""
Output:-
Pattern is found in string at index 10
"""
