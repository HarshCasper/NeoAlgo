#!/usr/bin/env python
# coding: utf-8

# In[1]:


'''

Aim: Given a number N, the aim is to print an integer denoting the maximum number of consecutive 1s in its binary representation. 

'''

n = int(input())                        # getting input
rmd = []
while n > 0:                            # loop to convert the number N into its binary form
    rm = n % 2
    n = n//2
    rmd.append(rm)                      # appending the result at each step in a list
count,result = 0,0
for i in range(0,len(rmd)):             # loop to find out the number of maximum consecutive 1s
    if rmd[i] == 0:
        count = 0
    else:
        count +=1                       # counter that will increase each time a series of 1s is encountered
        result = max(result,count)      # max function will help in finding the max streak of 1s
print(result)

'''

COMPLEXITY:

     Time Complexity -> O(N log(N))
     Space Complexity -> O(1)
   
Sample Test Case:
Input: 
5
Output: 
1

'''

