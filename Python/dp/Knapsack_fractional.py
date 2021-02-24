""" 
Knapsack problem using the fractional/greedy method
given the weights and their corresponding profit values, 
fractional implementation allows filling knapsacks with parts/fractions of the items
We fill knapsack of capacity W to obtain maximum possible value in bottom-up manner.
Time Complexity = O(n logn)
"""
def knapsack_fractional(weights,values,capacity):
    """ takes weights and values of items and capacity of knapsack as input
    and returns the maximum profit possible for the given capacity of knapsack 
    using the fractional knapsack algorithm"""
    #initialisaing the value of max_profit variable
    max_profit=0
    for pair in sorted(zip(weights,values),key=lambda x:-x[1]/x[0]): # sorting the pair of values in descending order
       #if weight of highest pair is greater than capacity, the amount is added in fractions
        if pair[0]>capacity:
           # while((pair[1]/(pair[0]/capacity))!=0)
            max_profit+=int(pair[1]/(pair[0]/capacity))
            capacity=0
        #if highest pair is lesser than capacity then the next pair is also added in fractions    
        elif pair[0]<= capacity:
            max_profit+=pair[1]
            capacity-=pair[0]
    #returns nearest possible integer value of profit
    return int(max_profit) 

if __name__ == '__main__':

    print("Enter Capacity:")
    capacity = int(input())
   
    print("Enter weights:")
    weights = list(map(int, input().split()))
    
    print("Enter values:")
    values = list(map(int, input().split()))

    print('The maximum possible profit is ',knapsack_fractional(weights,values,capacity)) 

"""
Sample Input:
capacity = 50
weights = 1 5 10
values = 10 50 100
Sample Output:
160
"""          
