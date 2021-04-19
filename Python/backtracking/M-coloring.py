'''
Problem Statement: Given an undirected graph and an integer M. 
The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color.

Input formate:
Line1: The number of testcases
Line2: Number of nodes 
Line3: Number of colors
Line4: Number of edges 
Line5: Edges seperated by spaces 

Output Formate:
Print 1 if it is possible to colour vertices and 0 otherwise.

Method:
Backtracking 

Intuition:  We consider all the different combinations of the colors for the given graph using backtacking 

Argument: Array,int,int
Return: Boolean
'''
def isSafe(graph,v,n,temp,color):
    #This check wheather if it saf to color the given node with temp color i.e checking if the adjacent nodes are different from temp 
    for i in range(v):
        if (graph[n][i]==1 and color[i]==temp):
            return False
    return True
def check(graph,m,v,n,color):
    #This function iteratively checks different combinations.
    if(n==v):# base case : if all the nodes are traversed return 
        return True
    for i in range(1,m+1):
        if(isSafe(graph,v,n,i,color)):#checking if it is safe to color 
            color[n]=i
            if(check(graph,m,v,n+1,color)):
                return True
            color[n]=0
    return False
def graphcoloring(graph,M,V):
    color=[0]*(V+1) # assigning colors to different nodes 
    return check(graph,M,V,0,color)
#driver code 
def main():
    for _ in range(int(input())):
        V=int(input())
        M=int(input())
        E=int(input())
        list=[int(x) for x in input().strip().split()]
        graph =[[0 for i in range(V)] for j in range(V)]
        cnt=0
        for i in range(E):
            graph[list[cnt]-1][list[cnt+1]-1]=1
            graph[list[cnt+1]-1][list[cnt]-1]=1
            cnt+=2
        if(graphcoloring(graph,M,V)==True):
            print(1,"/n")
        else:
            print(0,"/n")

if __name__ =='__main__':
    main()



'''
Sample Input:
2
4
3
5
1 2 2 3 3 4 4 1 1 3

3
2
3
1 2 2 3 1 3

Sample Output:
1
0

Time Complexity: O(M*V)
Space complexity: O(V)
'''
