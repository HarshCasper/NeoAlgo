# Given an undirected graph represented as an adjacency list, where
# graph[i] represents node i's neighbors.
# Return the number of possible edges that,
# if removed, causes the graph to become disconnected.
# Input:
#  GG = [
#     [1, 2, 3, 5],
#     [0],
#     [0, 3],
#     [0, 2, 4],
#     [3],
#     [0]
# ]
# output:
# 3

from collections import defaultdict

def solution(GG):
        n=len(GG)
        graph=defaultdict(list)
        # forming a dictionary with the given input to
        # contain all the elements as an adjacent list
        for i,ele in enumerate(GG):graph[i]+=ele
        seenAt,lowest_link,parent=([-1]*n, [-1]*n, [-1]*n)
        bridges=[]
        def tarjans(u,time):
            #initializing the discovered times and the lowest links
            seenAt[u]=lowest_link[u]=time
            # traversing the graphs
            for v in graph[u]:
                if seenAt[v]==-1:
                    #updating the parent
                    parent[v]=u
                    tarjans(v,time+1)
                    # backtracking to update the lowest link
                    lowest_link[u]=min(lowest_link[u],lowest_link[v])
                    # observing for any backedges
                    if lowest_link[v]>seenAt[u]: bridges.append((u,v))
                elif v!=parent[u]: lowest_link[u]=min(lowest_link[u],seenAt[v])
        for i in range(n):
            if seenAt[i]==-1:
                # call the tarjans() for each of the unvisited node
                tarjans(i,0)
        return len(bridges)


# Intuition:
# We can solve this in many ways , one of the approaches could to check connectivity with
# respect to each and every edge --> Time complexity O(E∗(V+E)) but it might
# not be an effective solution
# In this approach we are using the Trajan's Algorithm
# --> some of the observations which are going to be helpful
# *  a edge between two parts(subgraphs) of a graph can be a bridge
#  only if there exists no back-edge from one of the subgraphs to the
#  other i.e this edge is the only way we can connect different nodes
#  from these two subgraphs
# *  we should not consider the edge connecting the
#  parent and the child as a ** back edge **
# * to identify a back edge --> the lowest link of
# a node should should have a lesser value than its parent.
# if not such a node is a bridge
# if lowest_link[v] > seenAt[u]:
#      bridges.append((u, v))
# -->seenAt this array contains the value  for each node which
#  corresponds to the time at which we have seen that node this
#  remains constant throught the algorithm
# -->lowest_link this array contains the value for each node
#  which corresponds to  the lowest seenAt value node which is
#  accessible by this node
# -->parent array contains the parent for each node
# --> bridges contains the edge(vertex-pairs) which are the bridges
#  [ not necessary for the question , can be used to understand the answer better]
# -->time this is the variable which contains the seenAt time which increases
# by one for each recursive call
# Implementation:
# The implementation contains the use of the Trajan's Algorithm.
# along with some modifications made to accommodate the the conditions
# --> parent child edge exclusion
# --> back-edge detection

