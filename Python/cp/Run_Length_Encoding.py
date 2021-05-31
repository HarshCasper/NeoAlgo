def encode(s):
 
    j = 0
    #lenght of the input string
    length = len(s)

    while (j < length- 1):
 
       # counter for keeping the track of character  
        counter = 1
        while (j < length - 1 and s[j] == s[j + 1]):
            counter += 1
            j += 1
        j += 1
        # printing the encoded value
        print(s[j - 1] + str(counter), end = " ")
             

s = input("Enter the string to encode \n")
print("Encoded string")
encode(s)

'''
Time complexity : O(N)
Space complexity  O(1)
'''

'''
Test Case :
 Input :
    Enter the string to encode 
    tttyyss
 Output :   
    Encoded string
    t3 y2 s2 
'''