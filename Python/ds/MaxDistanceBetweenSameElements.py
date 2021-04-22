'''
This is a simple program of appliaction of hashing , we have to find the maximum distance between same elements
for eg : if array is [1,2,3,4,2,1] then max distance is between 1 at 0 index and 1 at 5 index so the output will be
5-0 = 5
Approch : First of all we make a dummy array of all zeros.
          Then we will create a hashmap and check if element is in hashmap or not .
          If element is not in hashmap then we will store the position (first occurence) of element.
          else we will find the difference in current position and first occurence and store it to dummy array.
          After this we just have to return the max difference.        
'''

# This function will return a intger as max distance
def maxDistance(arr, n):
    arr2 = [0*x for x in range(n)]
    #This dictionary works as hashmap for hashing
    dict1 =  {}
    res = 0
    for i in range(n):
        if arr[i] not in dict1.keys():
            dict1[arr[i]] = i
        else:
            first_occ = dict1[arr[i]]
            diff = i - first_occ
            try:
                if diff >= arr2[arr[i]]:
                    arr2[arr[i]] = diff
            except:
                pass
            if diff>=res:
                res = diff
    return res

# Driver Code Starts
if __name__=='__main__':
    print("Enter the no of Elements in Array")
    n = int(input())
    print("Enter the Array")
    arr = list(map(int, input().strip().split()))
    print(maxDistance(arr, n))
# Driver Code Ends

'''
Sample Input/Output :

- Test case 1:
Enter the no of Elements in Array : 5
Enter the Array : 1 2 3 3 3 4 1
Output : 6

- Test case 2:
Enter the no of Elements in Array : 11
Enter the Array : 1 2 3 3 3 4 1 2 2 3 4 
Output : 7

Time complexity : 0(n)
Space complexity : 0(n)
'''
