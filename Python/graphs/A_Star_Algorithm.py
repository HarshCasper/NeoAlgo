#!/usr/bin/env python
# coding: utf-8

# # A* Star Algorithm
# 
# ##### A* is a variant of Dijkstra's algorithm,A* assigns a weight to each open node equal to the weight of the edge to that node plus the approximate distance between that node and the finish. This approximate distance is found by the heuristic, and represents a minimum possible distance between that node and the end. This allows it to eliminate longer paths once an initial path is found.

# In[8]:


'''
g: The cost of the path from the start node.
h: estimation the cost of the path from present position to the goal
f: g+h : f is the least cost from one node to next node, A* selects the path that minimizes.
Child: all possible Paths towards solution
current: current node
start : Start node
end : end node
'''


class node():
    def __init__(self,parent=None,position=None):
        self.parent=parent #stores current parent
        self.position=position #current value
        self.g=0 #distance from start node to current node
        self.h=0 #heuristic dist between current node and end node
        self.f=0 #total cost
    def __eq__(self,other):
        return self.position==other.position

def a_star(maze,start,end):
    start=node(None,start) #initialising the start node
    start.g=0
    start.h=0
    start.f=0 #all distances are zero from start node
    end=node(None,end) #initialising end node
    end.g=0
    end.h=0
    end.f=0
    open_list=[] # list of all visited node's index
    closed_list=[]
    open_list.append(start)

    while len(open_list)>0: #looping until the open list is not empty
        current=open_list[0] #current node is equal to node with least value of f
        current_index=0
        for index,item in enumerate(open_list):
            if item.f<current.f:
                current=item
                current_index=index
        open_list.pop(current_index)#removing current node from open list
        closed_list.append(current)#adding current node to closed list
        
        if current==end: #checking if we have reached our goal
            path=[]
            current1=current
            while current1 is not None:
                path.append(current1.position)
                current1=current1.parent
            return path[::-1]
        children=[]
        
        for new_position in [(0, -1),(0, 1),(-1,0),(1,0),(-1, -1), (-1, 1), (1, -1), (1, 1)]:
            node_position=(current.position[0]+new_position[0],current.position[1]+new_position[1])
            
            if node_position[0]>(len(maze)-1) or node_position[0]<0 or node_position[1]>(len(maze[len(maze)-1])-1) or node_position[1]<0:
                continue
            
            if maze[node_position[0]][node_position[1]]!=0:
                continue
            new_node = node(current,node_position)
            children.append(new_node)
        
        for child in children:
            for closed_child in closed_list:
                if child ==closed_child:
                    continue
            child.g=current.g+1
            child.h=((child.position[0]-end.position[0])**2)+((child.position[1]-end.position[1])**2)
            child.f=child.g+child.h
            
            for open_node in open_list:
                if child==open_node and child.g > open_node.g:
                    continue
            open_list.append(child)

maze = [[0, 0, 0, 0, 1, 0],
       [0, 1, 0, 0, 1, 0],
       [1, 0, 1, 0, 1, 0],
       [0, 0, 0, 1, 1, 0],
       [0, 0, 1, 0, 1, 0],
       [0, 0, 0, 0, 0, 0]]
start=(0, 0)
end=(5, 5)
path=a_star(maze,start, end)
print(path)


# In[ ]:





# In[ ]:




