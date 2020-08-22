def targettriplets(lst, rang, target):   
    lst.sort() # Sorting the list in ascending order
    i = 0
    for i in range(rang):
        left = i + 1
        right = rang - 1
        current = lst[i]
        while left < right:
            if current + lst[left] + lst[right] == target: # Checking for the sum if it's equal to target
                print(current, ' ',lst[left], ' ', lst[right])
                left += 1
                right -= 1
            elif current + lst[left] + lst[right] < target: # Checking sum is less than target if it is then increment left
                left += 1
            else: # Otherwise decrement right
                right -= 1  
                
lst = []
rang = int(input('Enter the Range for the Triplet:'))  
for i in range(rang):
    inp = int(input()) # Taking the input from the user
    lst.append(inp) # Appending the input elements at the end of the list
op = int(input('Enter the target for triplet:'))
print('The Target Triplet is')
targettriplets(lst, len(lst), op)   
