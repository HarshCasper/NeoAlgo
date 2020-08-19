#INTERPOLATION SEARCH

# If the searching element is present in array, then returns index of it, else returns -1 
def interpolationSearch(arr, n, x): 
    #Assigning indexes 
    lo = 0
    hi = (n - 1) 
   
    # As array is going to be sorted, an element present in array must be in range defined by corner 
    while lo <= hi and x >= arr[lo] and x <= arr[hi]: 
        if lo == hi: 
            if arr[lo] == x:  
                return lo; 
            return -1; 
        
        pos  = lo + int(((float(hi - lo) / 
            ( arr[hi] - arr[lo])) * ( x - arr[lo]))) 
  
        # Condition of element found 
        if arr[pos] == x: 
            return pos 
   
        # If x is larger, x is in upper part 
        if arr[pos] < x: 
            lo = pos + 1; 
   
        # If x is smaller, x is in lower part 
        else: 
            hi = pos - 1; 
      
    return -1
  
 
#Starting with the main code
#Creating array of the size n
#Size would be taken into the variable n from user
arr = []
n = int(input("Enter the size of array : ")) 

#Entering the elements in the array
print ("Enter elements :")
for i in range(0, n): 
    ele = int(input())
    arr.append(ele)
print("The elements entered are:\n",arr,"\n")

#Sorting our array
print("The sorted array is: ")
arr.sort()
print(arr,"\n")

#Entering the searching element
x = int(input("Enter the element to be searched: "))  

index = interpolationSearch(arr, n, x) 
 
#If element was found  
if index != -1: 
    print ("Element found at index",index)   #Returning the index of the element
else: 
    print ("Element not found")              #Returning -1 as element has not found

