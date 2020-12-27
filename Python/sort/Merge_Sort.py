'''
According to wikipedia- In computer science, merge sort (also commonly spelled mergesort) is an efficient, 
general-purpose, comparison-based sorting algorithm. Most implementations produce a stable sort, 
which means that the order of equal elements is the same in the input and output. Merge sort is a divide and 
conquer algorithm.

How does it work?

Assume you have 8 elements, we first split the array into 2, so now we have 2 arrays each of 4 elements
then we split it again to have 4 arrays now of 2 elements each. Then we sort all these arrays one by one and
merge in the same way they were dissected. 

Python implementation of merge sort:

'''

def merging(arr, first, middle,last):
    # Initial values for variables 
    i=first
    j=middle+1
    
     # create temp array
    temp=[]

    while (i<=middle) and (j<=last):
        if int(arr[i])<int(arr[j]):
            temp.append(arr[i])
            i=i+1
        else:
            temp.append(arr[j])
            j=j+1
        
    while (i<=middle):
        temp.append(arr[i])
        i=i+1
        
    while (j<=last):
        temp.append(arr[j])
        j=j+1
        
    k=first
    for x in temp:
        arr[k]=x
        k=k+1
    
        
def mergesort(arr,beg,end):
    if (beg<end):
        # partition into 2 parts
        mid=int((beg+end)/2)
        # Sort first and second halves 
        mergesort(arr,beg,mid)
        mergesort(arr,mid+1,end)
        merging(arr,beg,mid,end)
 
 
#function to print array after sorting       
def display(arr,n ):
    i=0
    while (i<n):
        #printing the array after sorting
        print(arr[i], end=" ")
        i=i+1
        


#taking the size of array as input
n=5
#demo array:
arr=[41,15,25,12,21]
#calling the function for sorting 
mergesort(arr,0,n-1)
display(arr,n)