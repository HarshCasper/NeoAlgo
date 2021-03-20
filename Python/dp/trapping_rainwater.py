#given n towers of specified height, stacked alongside each other, the goal is to find the amount of water stored by the stacking towers, if rain water falls without any upper bound. We assume that 1 unit space between the towers store 1 unit water.
import math
def trapped(tower):
    #tower is a list such that tower[i] represents height of ith tower from the left
    waterLevel = []# waterLevel is another list that stores the water trapped such that waterLevel[i] stores the the water trapped by ith tower block, depending upon the shorter of the tower on its either side.  
    left = 0
     #The the maximum water trapped in at a position depends on the shorter tower on either side, hence now we can treat each tower segment as an independent water body and subtracting the tower height from that body of standing water will give the water trapped in that segment.
    for h in tower:
        left = max(left, h) 
        waterLevel += [left] 
    right = 0
    #each block is first hypothetically filled with water upto tallest tower on its left, and then sunk out to the tallest level to its right, to make sure the lesser out the two is used. 
    for i, h in reversed(list(enumerate(tower))):
        right = max(right, h)
        waterLevel[i] = min(waterLevel[i], right) - h 
    return sum(waterLevel)
def main():
        tower= []
        n = int(input("Enter number of towers : "))
        for i in range(0, n): 
            ele = int(input()) 
            tower.append(ele)
        print("water trapped by towers is ", trapped(tower))    
if __name__ == "__main__":
    main()

'''
Enter number of towers : 6
4
2
0
3
2
5
water trapped by towers is  9
'''