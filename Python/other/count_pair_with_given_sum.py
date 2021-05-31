'''
Count pairs with given sum
Given an array of integers, and a number sum find the number of pairs of integers in the array whose sum is equal to sum.
Examples:
 Input  :  arr[] = {1, 5, 7, -1},
           k = 6
 Output :  2
 Pairs with sum 6 are (1, 5) and (7, -1)


 Input  :  arr[] = {1, 1, 1, 1}
           k = 2
 Output :  6
 There are 3! pairs with sum 2.

'''
def Count_pairs_with_given_sum(arr,k):
    import collections
    hashmap = collections.defaultdict(int) #this will help to find distinct values 
    for val in arr:
        #length of distinct values 
        hashmap[val] += 1  
    res = 0 
    for num in arr:
        num_2 = k- num
        if num_2 in hashmap: 
            res += hashmap[num_2]
        
        if num_2 == num:  
            res -= 1
     #result        
    return res//2 # for approximate value 

if __name__ == "__main__":
    k = int(input("Enter the  target value: "))
    arr = list(map(int,input("Enter the list: ").split()))
    print("Pairs are ",Count_pairs_with_given_sum(arr,k))
    
'''
Time Complexity : O(n)
Space Complexity : O(1)

INPUT

Enter the value: 6 
Enter the list: 1 5 7 -1

OUTPUT
Pairs are 2 

'''
