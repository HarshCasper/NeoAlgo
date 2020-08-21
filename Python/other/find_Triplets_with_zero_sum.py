'''
  Author : Mohit Kumar
  
  python program to find triplets in a given  array whose sum is zero 

'''

# function to print triplets with 0 sum 

def find_Triplets_with_zero_sum(arr, n): 
   
    ''' find triplets in a given  array whose sum is zero 
        
        Parameteres : 
            arr : input array 
            n = size of input array

        Output :
            if triplets found print their values 
            else print No Triplet Found

    '''
   
    found = False

    # sort array elements 
    arr.sort() 

    for i in range(0, n - 1) : 
    
        # initialize left and right 
        l = i + 1
        r = n - 1
        x = arr[i] 
        
        while (l < r): 
            
            temp = x + arr[l] + arr[r] 
            
            if (temp == 0) : 
                # print elements if it's sum is zero 
                print(x, arr[l], arr[r]) 
                l+=1
                r-=1
                found = True
            

            # If sum of three elements is less 
            # than zero then increment in left 
            elif (temp < 0) : 
                l+=1

            # if sum is greater than zero than 
            # decrement in right side 
            else: 
                r-=1
        
    if (found == False): 
        print(" No Triplet Found") 

# DRIVER CODE STARTS

if __name__ == "__main__":
    
    n = int(input('Enter size of array\n'))
    print('Enter elements of array\n')
    
    arr = list(map(int,input().split()))
    
    print('Triplets with 0 sum are as : ')
    
    find_Triplets_with_zero_sum(arr, n) 

'''
SAMPLE INPUT 1 :
	arr = [0, -1, 2, -3, 1] 
OUTPUT :
	-1 0 1
	-3 2 1

COMPLEXITY ANALYSIS :

Time Complexity : O(n^2).
    Only two nested loops is required, so the time complexity is O(n2).

Auxiliary Space : O(1), no extra space is required, so the time complexity is constant.

'''
