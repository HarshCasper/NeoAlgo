#Python program to implement Selection Sort

def selectionSort(array, n):
    i = 0
    while i < n:
        #Initilizing mini as i
        mini = i
        j = i + 1
        while j < n:
            #If element at j is smaller than mini then change mini to j
            if array[j] < array[mini]:
                mini = j
            j += 1
        #swapping elements at mini and i    
        (array[i], array[mini]) = (array[mini], array[i])
        i += 1          


data = []
n = int(input("Enter the size of array :"))
 
print('Enter the elements of array:');
for i in range(n):
    data.append(int(input()))
    
# Sending element to get sorted
selectionSort(data, n)
 
# Priting Elements after Getting Sorted
for d in data:
    print(d, end = " ")

"""
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

INPUT
Enter the size of array: 5
Enter the elements of array: 
5
4 
3 
2 
1

OUTPUT
1 2 3 4 5

"""