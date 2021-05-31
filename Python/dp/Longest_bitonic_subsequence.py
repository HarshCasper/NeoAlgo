'''
The longest bitonic subsequence is a sequence in which the sequence is first increasing then decreasing ,
The below program finds the length of the longest bitonic subsequence.
'''

def longest_bitonic_subsequence(v,n):
    v_increase = []
    for i in range(n+1):
        v_increase.append(1)
    for i in range(n):
        for j in range(i):
            if(v[i] > v[j]):
                if(v_increase[i] <= v_increase[j]):
                    v_increase[i] = v_increase[j] + 1

    v_decrease = []
    for i in range(n+1):
        v_decrease.append(1)

    for i in range(n-2,-1,-1):
        for j in range(n-1,i,-1):
            if(v[i] > v[j]):
                if(v_decrease[i] <= v_decrease[j]):
                    v_decrease[i] = v_decrease[j] + 1
    max = 0
    for i in range(n):
        temp = v_decrease[i] + v_increase[i] -1
        if(temp > max):
            max = temp
    return max


if __name__ == '__main__':
    n = int(input("Enter the number of elements in the sequence : "))
    print("Enter the elements of the sequence")
    v = list(map(int, input().split(' ')))
    print("The length of longest bitonic subsequence is : " + str(longest_bitonic_subsequence(v, n)))



'''
Sample I/O:

Enter the number of elements in the sequence : 10
Enter the elements of the sequence
1 2 6 3 12 14 4 9 10 7
The length of longest bitonic subsequence is : 7

Time Complexity : O(n^2) 
Space Complexity : O(n)
'''