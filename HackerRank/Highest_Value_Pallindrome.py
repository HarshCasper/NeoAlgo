def ispallindrome(n):
    
    if n == "".join(reversed(n)):
        return True
    
    return False

    def highestValuePalindrome(s, n, k):

    s = str(s)
    
    pallindromes = []
    possibilities = [0,1,2,3,4,5,6,7,8,9]
    #numbers = s.split()
    temp = []
    
    while k > 0:
        for i in range(n):
            for e in possibilities:
                if i == 0: 
                    temp = str(e) + s[i + 1 : ]
                elif i == len(s) - 1:
                    temp = s[ : i] + str(e) 
                else:
                    temp = s[ : i] + str(e) + s[i + 1 : ]

                #print(temp)
                if ispallindrome(max(s, "".join(temp))):
                    pallindromes.append(max(s, "".join(temp)))
                    
        k -= 1
        
        '''if not pallindromes:
            s = list(s)
            s[0] = max(possibilities)
            s[n - 1] = max(possibilities)
            s = str(s)'''
            
        s = list(s)
        m = min(s)
        ind = s.index(m)
        s.remove(m)
        s.insert(ind, str(max(possibilities)))
        s = str("".join(s))
        
    if not pallindromes:
        return -1
    else:
        print(pallindromes) 
        print(len(pallindromes))
        return max(pallindromes)
    
           