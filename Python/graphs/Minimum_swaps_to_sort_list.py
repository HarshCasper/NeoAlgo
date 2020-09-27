'''
Task : You are given an array of length N which has all the numbers from 1 to N(without repitition) in an
random order. Your task is to find the least number of swaps required to sort the array.

The way num_min_swaps works is follows:
Since we know the array contains all numbers from 1 to N, when the array is sorted, an element with
value 'i' will be in the index i-1 i.e '1' will be in index 0, '2' will be in index 1 and so on.
So for every index i in the unsorted array, if arr[i] is not equal to i+1, we repeatedly swap it till
the correct element reaches the i'th position.
'''

'''
method num_min_swaps()
            - Takes parameter list
            - returns the minimum number of swaps required to sort the list
'''
def num_min_swaps(arr):
    count = 0
    for index in range(len(arr)):
        if arr[index] != index+1:
            while(arr[index]!=index+1):  #swapping arr[i] with arr[arr[i]-1] which is the position it should be at
                temp = arr[arr[index] - 1];
                arr[arr[index] - 1] = arr[index];
                arr[index] = temp;
                count += 1
    return count

if __name__ == "__main__":
    arr = list(map(int, input().split()))
    print('Minumum number of swaps required is: ', num_min_swaps(arr))
