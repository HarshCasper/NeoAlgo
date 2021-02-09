"""
Purpose:The problem is to find the shortest distance between all pairs of vertices in a weighted directed graph that can have negative edge weights. For the problem to be well-defined, there should be no cycles in the graph with a negative total weight.	
Method: Dynamic Programing

Applications:

- To find the shortest path is a directed graph
- To find the transitive closure of directed graphs
- To find the Inversion of real matrices
- For testing whether an undirected graph is bipartite

Reference: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

Time Complecity:  O(V^3)
Space Complexity: O(V^2)

"""
# Number of vertices in the graph
Vertices = 4

# You can change the number of vertices by:
# V=int(input('enter vertices: ')) and accordingly you have change the input

# Define INFinity as the large enough value. This value will be used for vertices not connected to each other
INF = 999999

# Solves all pair shortest path via Floyd Warshall Algorithm

# Floyd warshall function
def floydWarshall(graph):

	""" distance[][] will be the output matrix that will finally have the shortest distances between every pair of vertices """
	""" initializing the solution matrix same as input graph matrix OR we can say that the initial values of shortest distances are based on shortest paths considering no 
	intermediate vertices """
	""" Using lambda and map functios to take multiple inputs and process them. """
	
	distance = list(map(lambda i: list(map(lambda j: j, i)), graph))

	""" Add all vertices one by one to the set of intermediate vertices.
	---> Before start of an iteration, we have shortest distances between all pairs of vertices such that the shortest distances consider only the vertices in the set {0, 1, 2, .. k-1} as intermediate vertices.
	----> After the end of a iteration, vertex no. k is added to the set of intermediate vertices and the set becomes {0, 1, 2, .. k}
	"""
	
	for vertex in range(Vertices):

		# pick all vertices as source one by one
		for source_vertex in range(Vertices):

			# Pick all vertices as destination for the above picked source
			for destination_vertex in range(Vertices):

				# If vertex k is on the shortest path from i to j, then update the value of distance[source_vertex][destination_vertex]
				distance[source_vertex][destination_vertex] = min(distance[source_vertex][destination_vertex],
								distance[source_vertex][vertex] + distance[vertexk][destination_vertex]
								)
	# Function call
	printSolution(distance)	


# function to print the solution
def printSolution(distance):
	# selecting source vertex
	for source in range(Vertices):
		#selecting destination vertex
		for destination in range(Vertices):
			# checking if the distance is infinity or not
			if(distance[source][destination] == INF):
				print ("%8s" % ("INF"))
			else:
				# if it is not infinity then print the distance between source and destination
				print ("%7d\t" % (distance[source][destination]))
				
			if destination == Vertices-1:
				print ("")


# Driver program 
# The graph that will be created with given input
"""
	      10
	(0)------->(3)
	|	   /|\
       5|	    |
	|           | 1
       \|/	    |
	(1)------->(2)
	      3		
"""
# input
graph = [[0, 5, INF, 10],
         [INF, 0, 3, INF],
         [INF, INF, 0,   1],
         [INF, INF, INF, 0]
         ]
    
# FUntion call to print the solution
floydWarshall(graph)

'''
 Output:  
0	  5	      8	      9	
INF       0	      3	      4	
INF       INF         0	      1	
INF       INF        INF      0	
'''
