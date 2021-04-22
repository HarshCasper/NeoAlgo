''' K-TH LARGEST NUMBER 
    To find the k-th largest number from an array of distinct numbers
    * The array is sorted in descending order
    * arr[k-1] gives the k-th largest number
'''

# to sort the array- Bubble Sort
def sort_arr(arr):
    n = len(arr)
    for i in range(0, n-1):
        for j in range(0, n-i-1):
            if(arr[j] < arr[j+1]):
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    return arr

#to find k-th largest element
def k_largest(arr, k):
    return arr[k-1]

#driver code
def main():
    #accept array and k as user inputs
    arr = list(map(int, input("Enter the array: ").split()))
    k = int(input("Enter the value of k: "))
    print(k_largest(sort_arr(arr), k))

if __name__ == '__main__':
    main()

'''
    Sample Input:
    Enter the array: 1 5 3 6 2 7
    Enter the value of k: 3

    Sample Output:
    5

    Time Complexity: O(n^2)
    Space complexity: O(n)
'''
