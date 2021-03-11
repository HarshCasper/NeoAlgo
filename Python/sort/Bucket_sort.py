#Bucket Sort
''' Bucket Sort is a sorting algorithm used to deal with input that is distributed over a range. It is a comparison sort algorithm.
Here,the elements of the list are distributed into a number of buckets(or bins). Each bucket is then individually sorted using any sorting algoritm or by recursively applying the bucket algorithm. After sorting of each is bucket is completed, all the buckets are mergedand we geta sorted list.
Bucket Sort has a scatter-order-gather approach: the list elments are first scattered into buckets, then each bucket is ordered and at last all buckets are gathered together to form sorted list. ''' 


def bucket_sort(arr):
    #create a list containing n empty buckets where buckets are also list
    bucket_list = []
    for i in range(len(arr)):
        bucket_list.append([])  

    #numerical range of each bucket
    maximum = max(arr)
    size = maximum / len(arr)    

    #Put list elements into their respective buckets i.e Scatter 
    for i in range(len(arr)):
        j = int(arr[i]/size)
        if j != len(arr):
            bucket_list[j].append(arr[i])
        else:
            bucket_list[len(arr) - 1].append(arr[i])    

    #Sorting each bucket individually and Merging
    sorted_arr = []
    for bucket in bucket_list:
        curr = bucket
        curr.sort()                               #Order
        if len(curr) != 0:
            sorted_arr.extend(curr)               #Gather

    sorted_arr = [str(i) for i in sorted_arr]
    res = " ".join(sorted_arr)       
    return res

def main():
    n = input('Length of the list: ')
    print('Enter the elements:- ')      #Entering list of elements to be sorted
    arr = []
    for i in range(int(n)):
        arr.append(input()) 
    arr = [float(i) for i in arr]       

    sorted_list = bucket_sort(arr) 

    print('Sorted List')                #Printing sorted list
    print(sorted_list)

if __name__ == "__main__":
    main()       

'''
Sample I/O

Length of the list: 6
Enter the elements:- 
6.3
12.5
7.7
2.6
1.2
4.0
Sorted List
1.2 2.6 4.0 6.3 7.7 12.5


Time Complexity -
    1. Best case - O(n+k)
    2. Average case - O(n+k)
    3. Worst case - O(n^2)
    where n = number of elements in the input array
    
Space Complexity - O(nk)
'''