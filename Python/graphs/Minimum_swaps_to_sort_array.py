'''
Task : You are given an array of length N which has all the numbers from 1 to N(without repitition) in an
random order. Your task is to find the least number of swaps required to sort the array.

The way num_min_swaps works is follows:
Since we know the array contains all numbers from 1 to N, when the array is sorted, an element with
value 'i' will be in the index i-1 i.e '1' will be in index 0, '2' will be in index 1 and so on.
So for every index i in the unsorted array, if arr[i] is not equal to i+1, we repeatedly swap it till
the correct element reaches the i'th position.

Uncomment the print statements for better understanding.
'''

def num_min_swaps(arr):
    count = 0
    for i in range(len(arr)):
        #print('Iteration: ' , i)
        #print('Before: ' , arr)
        if arr[i] != i+1:
            while(arr[i]!=i+1):  #swapping arr[i] with arr[arr[i]-1] which is the position it should be at
                temp = arr[arr[i] - 1];
                arr[arr[i] - 1] = arr[i];
                arr[i] = temp;
                #print('After: ' , arr)
                count += 1
                #print('Count: ' , count)
    return count

if __name__ == "__main__":
    #arr = list(map(int, input().split())) #uncomment for custom input
    arr = [2,10,1,3,6,4,7,5,8,9];
    print('Minumum number of swaps required is: ', num_min_swaps(arr))
