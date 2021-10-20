'''
Given an array of n integers where each value represents the number of chocolates in a packet. 
Each packet can have a variable number of chocolates. There are m students, 
the task is to distribute chocolate packets such that: 

1.Each student gets one packet.
2.The difference between the number of chocolates in the packet with maximum chocolates and 
packet with minimum chocolates given to the students is minimum.
'''
def chunks(arr, M):
    """Yield sublist of arr of length M."""
    for i in range(0, len(arr)):
        r = arr[i:i+M]
        if len(r) == M:
            yield r

def main(arr, M):
    """Chocolate Distribution Problem."""
    arr = sorted(arr)
    min_ = None
    for x in chunks(arr, M):
        diff = x[-1] - x[0]
        if min_ is None or diff <= min_:
            min_ = diff
    #result
    return min_


if __name__ == "__main__":
    arr = list(map(int,input("Enter the Chocolate bars: ").split()))
    M = int(input("Enter the number student to distribute: "))
    print("Minimum Difference is ",main(arr,M))

"""
Time complexcity : O(n log n)
Space Complexcity : O(n log n)

Input:
Enter the Chocolate bars: 7 3 2 4 9 12 56
Enter the number student to distribute: 3

Output:
Minimum Difference is  2

"""
