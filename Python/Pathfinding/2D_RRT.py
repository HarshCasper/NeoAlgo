"""
Rapidly-exploring Random Trees

Purpose: A robot is attempting to navigate its path from the start point to a specified goal region, 
        while avoiding the set of all obstacles.Will be  Using tree structure
"""

import matplotlib.pyplot as plt
import math
import random
from shapely.geometry import Point
from shapely.geometry import Polygon, MultiPolygon, LineString


# tree structure definition
class Tree():

    def __init__(self, data=Point(0,0), children=None, par=None):
        self.data = data
        self.children = []
        if children is not None:
            for child in children:
                self.add_child(child)
        self.par = par

    def add_child(self, node):
        self.children.append(node)
        node.par = self
                
    def __str__(self, level=0):
        ret = "\t"*level+repr(self.data.x)+" "+repr(self.data.y)+"\n"
        for child in self.children:
            ret += child.__str__(level+1)
        return ret

    def __repr__(self):
        return '<tree node representation>'

    # to trace final path
    def tb(self,n):
        ax = []
        ay = []
        ax.append(n.data.x)
        ay.append(n.data.y)
        while n.data != self.data:
            n = n.par
            ax.append(n.data.x)
            ay.append(n.data.y)
        return ax,ay


# defining obstacles as a set of polygons
def obst(arr):
    ans = []
    for coord in arr:
        m = Polygon(coord)
        ans.append(m)
    t = MultiPolygon(ans)
    return t

# defining goal region as polygon
def dgoal(coord):
    m = Polygon(coord)
    t = MultiPolygon([m])
    return t

# distance between two points
def distance(pt1,pt2):
    ans = math.sqrt((pt1.x - pt2.x) ** 2 + (pt1.y-pt2.y) ** 2)
    return ans

# finding nearest neighbour
def nearestNode(pt,root,mind):
    if distance(root.data,pt) < mind:
        mind = distance(root.data,pt)
    ans = root
    for i in root.children:
        d = nearestNode(pt,i,mind)
        if d[0] < mind:
            mind = d[0]
            ans = d[1]
    return (mind, ans)


# check if point is within polygon
def IsInObstacle(arr,pt):
    for i in arr.geoms:
        if i.contains(pt):
            return True
    return False

# linking new point to existing tree
def chain(node,pt):
    last = Tree(pt)
    node.add_child(last)
    return last



def RRT(start,goal,obstacle_list):

    '''
    The search space will be a rectangular space defined by
    (0,0),(0,10),(10,0),(10,10)
    '''

    goalr = [(goal[0]-0.3,goal[1]-0.3),(goal[0]+0.3,goal[1]-0.3), (goal[0]+0.3,goal[1]+0.3), (goal[0]-0.3,goal[1]+0.3)]
    Qgoal = dgoal(goalr)

    obstacles = obst(obstacle_list)
    
    cnt = 0 
    graph = Tree(Point(start[0],start[1])) 
    
    while cnt < 5000:
        
        x = random.random() * 10
        y = random.random() * 10
        p = Point(x,y)
        
        if IsInObstacle(obstacles, p):
            continue
            
        n = nearestNode(p, graph, 10**6) 
        line = LineString([n[1].data,p])

        if n[0] >= 1:
            p = line.interpolate(1)
            x = p.x
            y = p.y
            line = LineString([n[1].data,p])
            
        if line.crosses(obstacles):
            continue
            
        last = chain(n[1],p)
        
        if IsInObstacle(Qgoal,p):
            print("Found it!")
            return graph.tb(last),Qgoal

        cnt += 1

    return graph.tb(last),Qgoal


def visualize(path,obstacle_list,Qgoal):

    '''
    The matplot code required to visulaize both the path and obstacles in
    the environment go here.
    '''

    plt.figure()

    plt.plot(path[0],path[1],"b.-")

    m = obst(obstacle_list)
    for i in m:
        x,y = i.exterior.xy
        plt.plot(x,y,"black")

    for i in Qgoal:
        x,y = i.exterior.xy
        plt.plot(x,y,"red")

    plt.show()


def main():
    
    obstacle_list = [
            [(2, 10), (7, 10), (6, 7), (4, 7), (4, 9), (2, 9)],
            [(3, 1), (3, 6), (4, 6), (4, 1)],
            [(7, 3), (7, 8), (9, 8), (9, 3)],
        ]

    print("Sample space defined by a square grid of 10*10 units")

    print("Enter start point: ")
    x,y = map(int,input().split())
    start = (x,y)

    print("Enter goal point: ")
    x,y = map(int,input().split())
    goal = (x,y)
    
    path = RRT(start,goal,obstacle_list)
    visualize(path[0],obstacle_list,path[1])

if __name__ == "__main__": 
    main()   

"""
Sample I/O: 

Input - 
start: 1 1
goal: 10 10

Output - 
A graph plotted using matplotlib with required path avoiding obtsacles, and the sampled points.

Time Complexity: O(N)
Space Complexity: O(N)
"""
