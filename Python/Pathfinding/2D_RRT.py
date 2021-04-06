#Rapidly-exploring Random Trees

#Purpose: A robot is attempting to navigate its path from the start point to a specified goal region, while avoiding the set of all obstacles.

#Method: using tree structure

#Intuition:
#In RRT, points are randomly generated within a specified radius and connected to the nearest existing node in a tree. 
#Each time a node is created, we check that it lies outside of the obstacles. 
#Furthermore, chaining the node to its closest neighbor must also avoid obstacles. 
#The algorithm ends when a node is generated within the goal region, or a limit is hit.


#have matplotlib and shapely installed
import matplotlib.pyplot as plt
import math
import random
from shapely.geometry import Point
from shapely.geometry import Polygon, MultiPolygon, LineString


#tree structure definition
class Tree():

    def __init__(self, data = Point(0,0), children=None, par=None):
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

    #to trace final path
    def tb(self,n):
        ax = []
        ay = []
        ax.append(n.data.x)
        ay.append(n.data.y)
        while n.data != self.data:
            n = n.par
            ax.append(n.data.x)
            ay.append(n.data.y)
        plt.plot(ax,ay,"b.-")


#defining obstacles as a set of polygons
def obst(arr):
    ans = []
    for coord in arr:
        m = Polygon(coord)
        x,y = m.exterior.xy
        plt.plot(x,y,"black")
        ans.append(m)
    t = MultiPolygon(ans)
    return t

#defining goal region as polygon
def goal(coord):
    m = Polygon(coord)
    x,y = m.exterior.xy
    plt.plot(x,y,"black")
    t = MultiPolygon([m])
    return t

#distance between two points
def distance(pt1,pt2):
    ans = math.sqrt((pt1.x-pt2.x)**2 + (pt1.y-pt2.y)**2)
    return ans

#finding nearest neighbour
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


#check if point is within polygon
def IsInObstacle(arr,pt):
    for i in arr.geoms:
        if i.contains(pt):
            return True
    return False

#linking new point to existing tree
def chain(node,pt):
    last = Tree(pt)
    node.add_child(last)
    return last

#drawing the link
def link(node,pt):
    plt.plot([node.data.x,pt.x],[node.data.y,pt.y],"r")

#main rrt function
def rrt(Qgoal,obstacles,lim):
    
    Qgoal = goal(Qgoal)
    obstacles = obst(obstacles)
    
    cnt = 0 
    graph = Tree() #Graph containing edges and vertices, initialized as empty
    
    while cnt < lim:
        
        x = random.random()*100
        y = random.random()*100
        p = Point(x,y)
        
        if IsInObstacle(obstacles,p):
            continue
            
        n = nearestNode(p,graph,10**6) #find nearest vertex
        line = LineString([n[1].data,p])

        if n[0] >= 2:
            p = line.interpolate(2)
            x = p.x
            y = p.y
            line = LineString([n[1].data,p])
            
        if line.crosses(obstacles):
            continue
            
        plt.scatter([x],[y],c="r", s=3)
            
        last = chain(n[1],p)
        link(n[1],p)
        
        if IsInObstacle(Qgoal,p):
            print("Found it!")
            graph.tb(last)
            plt.show()
            return graph
        cnt += 1
    graph.tb(last)
    plt.show()  
    return graph

#driver code
def main():
    plt.figure(figsize=(15,10))
    #define goal region here
    Qgoal = [(90,90),(92,90),(92,92),(90,92)]

    #define obstacles here
    obstacles = [[(10,20),(10,95),(20,95),(20,20)],[(50,0),(50,80),(45,80),(45,0)],[(80,50),(80,90),(82,90),(82,50)]]

    #number of iterations algorithm should run for
    lim = 5000 

    rrt(Qgoal,obstacles,lim)

# call the main method 
if __name__ == "__main__": 
    main()	 
