'''
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

INPUT
Enter the list 1: 1 5 5
Enter the list 2: 3 4 5 5 10
Enter the list 3: 5 5 10 20

Output: 5 5

Explanation: 5 and 5 are the only
common elements in list1, list2 and list3.

'''
def common_elements(arr1,arr2,arr3):
        #Take the lists in set 
        setofarr1 = set(arr1)
        setofarr2 = set(arr2)
        setofarr3 = set(arr3)
        
        #using the intersection method  we can find out common elements between arr1 and arr2   
        t = setofarr1.intersection(setofarr2)
        
        #using the intersection method  we can find out common elements between arr1 and arr2 and arr3  
        Total = list(t.intersection(setofarr3))
        #sort the Total array 
        Total.sort()
        #print out the result 
        return Total

if __name__ == "__main__":
    arr1 = list(map(int,input("Enter the list 1: ").split()))
    arr2 = list(map(int,input("Enter the list 2: ").split()))
    arr3 = list(map(int,input("Enter the list 3: ").split()))
    print("Common elements from three lists are ",common_elements(arr1, arr2, arr3))

'''
Time Complexity: O(n1 + n2 + n3)
Space Complexity: O(n1 + n2 + n3)

INPUT
Enter the list 1: 1 5 10 20 40 80
Enter the list 2: 6 7 20 80 100
Enter the list 3: 3 4 15 20 30 70 80 120

OUTPUT
Common elements from three lists are [20, 80]


'''