'''
Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 
'''
def trapping_rain(buildings):
    #let take water zero
    water = 0
    #taking the loop for how many block in left and right 
    for i in range(1, len(buildings) - 1):
        left = max(buildings[:i])
        right = max(buildings[i + 1:])

        if buildings[i] < left and buildings[i] < right:
            water = water + min(left, right) - buildings[i]
    #result
    return water

def main():
   #taking the input 
   building = list(map(int,input("Enter the blocks: ").split()))
   print("total unit of water trapped is ",trapping_rain(building))
   

if __name__=='__main__':
    main()

'''
Time Complexity: O(N)
Space Complexity: O(1)

INPUT:

Enter the blocks: 3 0 0 2 0 4

OUTPUT:
total unit of water trapped is  10

'''
