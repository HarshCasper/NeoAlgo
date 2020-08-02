# =============================================================================
# Complexity of this algortihm is O(log i)
# where, i is the position where the element lies or is supposed to lie.
# This is better than O(log n)
# where, n is the number of elements in the array.
# Hence, this is better than Binary Search.
# =============================================================================

def exponential_search(search_list, left, right, target):
    # just checking for the 0th index individually
    if search_list[0] == target: 
        return "Found at 0"
    
    # initializing the index to start searching for elements
    i = 1 
    
    # we only check until the index is greater than equal to the element to be found or until it goes beyond the length of the list
    while i < len(search_list) and search_list[i] <= target:
        i *= 2 # index is doubled in each iteration
    index = binary_search(search_list, i//2, min(i, len(search_list)-1), target) 
    return index
    
# applying binary search within the range where the element could be
def binary_search(search_list, left, right, target):
    if left > right:
        return "Not Found!"
    middle = (left + right) // 2
    if search_list[middle] == target:
        return "Found at " + str(middle)
    elif search_list[middle] > target:
        return binary_search(search_list, left, middle - 1, target)
    else:
        return binary_search(search_list, middle + 1, right, target)
    

def main():
    search_list = list(map(int, input("Enter space separated numbers for the list\n").split()))
    search_value = int(input("Enter value to search\n"))
    
    print("Sorted list:", sorted(search_list))
    print(exponential_search(sorted(search_list), 0, len(search_list)-1, search_value))
    
main() 
