"""
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
"""


def longestcommansubsequence(a,b):
    
    x=len(a);y=len(b) #get the lengths of the sequences
    
    #create the table
    table=[[0 for i in range(y+1)] for j in range(x+1)]
    
    #DP
    for i in range(x+1):
        for j in range(y+1):
            if(i==0 and j==0):
                table[i][j]=0
            #check if the letters at the given positions of the strings are equal or not 
            elif(a[i-1]==b[j-1]):                
                table[i][j]=table[i-1][j-1]+1
            else:
                #find the max since we need to fing the longest subsequence
                table[i][j]=max(table[i-1][j],table[i][j-1])
    print(table[x][y])

a = "djjradc"
b = "jwrwadfc"
longestcommansubsequence(a,b)

"""
Sample
ABCDGH
AEDFHR
Output: 3
"""
