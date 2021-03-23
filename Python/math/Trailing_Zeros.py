"""
This algorithm is used to calculate number of trailing zeros in n!
Calulating n! and then counting number of zeros is not fesible as n! will become very large for larger values of n.
We used the fact that a trailing zeros is produced by 2 and 5 (as 2*5 = 10). So we can calculate number of trailing zeros by counting numbers of 2s and 5s.
Another observation, number of 2s >= number of 5s. So, we only need to calculate number of 5s.
Number of 5s = n//5 + n//25 + n//125 ...
"""

n=int(input("Enter number: "))
num_zeros=0
curr_val=5
while n//curr_val>0:
    num_zeros=num_zeros+(n//curr_val)
    curr_val=curr_val*5
print("Number of trailing zeros:",num_zeros)

"""
Sample I/O
1.
    INPUT:
    Enter number: 1
    OUTPUT:
    Number of trailing zeros: 0
2.
    INPUT
    Enter number: 10
    OUTPUT:
    Number of trailing zeros: 2

3.
    INPUT
    Enter number: 1000
    OUTPUT:
    Number of trailing zeros: 249
"""

"""
Time Complexity: O(log(n))
Space Complexity: O(1)
"""