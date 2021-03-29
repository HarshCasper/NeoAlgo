'''
Problem - 
	To find the time taken for all oranges to get rotten.

Algorithm - 
    We follow by DFS search starting from those points that have rotten oranges and finding thoses fresh oranges in adjacent to them.
    We keep a queue and as we get a new rotten orange we push it into the queue and do this until all possible oranges are rotten.
    The time taken is then returned.
	
'''

from queue import Queue
import copy

class rotten_Oranges():
    def __init__(self, arr):
        self.arr = copy.deepcopy(arr)
        self.R = len(arr)
        self.C = len(arr[0])
        self.time = -1
    
    # Checks if the index in consideration is valid or not
    def isValid(self, x, y):
        return (x >= 0 and x < self.R and y >= 0 and y < self.C)
    
    # Checks if there are still some fresh oranges left
    def checkall(self):
    	for i in range(self.R):
    		for j in range(self.C):
    			if (self.arr[i][j] == 1):
    				return True;
    	return False;
    
    # A checker to take care of all corner case. In case the matrix is all zero then this checker takes care of such cases
    def checkzero(self):
    	for i in range(self.R):
    		for j in range(self.C):
    			if (self.arr[i][j] != 0):
    				return False;
    	return True;

    # The main function where the calculation for time taken takes place
    def timeTaken(self):
        q = Queue(0)
        xindex = [1, -1, 0, 0]
        yindex = [0, 0, 1, -1]
        
        for i in range(self.R):
            for j in range(self.C):
                if (self.arr[i][j] == 2):
                    q.put([i, j])
        
        while (not q.empty()):
            self.time += 1
            lsize = q.qsize()
            
            for i in range(lsize):
                curr_x, curr_y = q.get()
                
                for j in range(4):
                    x = curr_x + xindex[j]
                    y = curr_y + yindex[j]
                
                    if (not self.isValid(x, y)):
                        continue
            
                    if (self.arr[x][y] == 1):
                        self.arr[x][y] = 2
                        q.put([x, y])
    
        if (self.checkzero()):
            return 0
	
        return self.time if(not self.checkall()) else -1

arr = []
R, C = map(int, input("Enter number of rows and columns : ").split())
for i in range(R):
    print(("\nEnter for {}th row : ").format(i+1), end = "")
    arr.append(list(map(int, input().split())))

obj = rotten_Oranges(arr)
time = obj.timeTaken()
if (time == -1):
    print("\nAll the oranges cannot be rotten !!")
else:
    print("\nIt takes {} seconds.".format(time))

'''
Test run example - 
	Enter number of rows and columns : 3 5
	Enter for 1th row : 2 1 0 2 1
	Enter for 2th row : 1 0 1 2 1
    	Enter for 3th row : 1 0 0 2 1
    
    	It takes 2 seconds.

Time and Space Complexity - 
	Time - O(R * C)
	Space - O(R * C)
'''
