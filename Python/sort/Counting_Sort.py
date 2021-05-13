'''
Counting sort is a sorting algorithm that sorts the elements of an
array by counting the number of occurrences of each unique element in the array.
Worst Case Complexity: O(n+k)
Best Case Complexity: O(n+k)
Average Case Complexity: O(n+k)
where n is size of an array , and k is element range of the array.
In this program default 'k' is 1000.
'''

def counting_sort(l, k=None):
    #  creating an array for counting elements
    if k == None:
        arr = [0]*1000
    else:
        arr = [0]*(k+1)
    # counting the occurrence of elements
    for i in l:
        arr[i]+=1
    # generating sorted array
    l=[]
    for i in range(len(arr)):
        l+=[i]*arr[i]
    return l


if __name__ == "__main__":
    l = list(map(int,input("Enter the elements of the list to be sorted:").split()))
    l = counting_sort(l)
    print("List after sorting:",*l)

'''
Sample Input:
Enter the elements of the list to be sorted:12 0 1 3 5 3 3 2 1 1

Sample Output:
List after sorting:0 1 1 1 2 3 3 3 5 12
'''
