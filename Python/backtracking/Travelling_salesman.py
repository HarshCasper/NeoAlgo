"""
Purpose:  The traveling salesman problem (TSP) is an algorithmic problem tasked 
          with finding the shortest route between a set of points and 
          locations that must be visited. In the problem statement, the 
          points are the cities a salesperson might visit.
         
Problem Link:- https://en.wikipedia.org/wiki/Travelling_salesman_problem

Visualization:- https://nicechay.github.io/tsp/

Method: Backtracking Algorithm

Intution: Start with a specific node which will be starting and ending node
          of the cycle. Start traversing to its adjacent nodes in dfs manner and calculate cost of every traversal and keep track of minimum cost, return the permutation with minimum cost.

Worst-Case Time Complexity:  O(N!)

Space Complexity: O(N^2)

Return  : Minimum cost of the route

"""


# Function to find the minimum weight 
def tsp(graph, v, currPos, n, count, cost): 

	# If last node is reached and it has 
	# a link to the starting node i.e 
	# the source then keep the minimum 
	# value out of the total cost of 
	# traversal and "ans" 
	# Finally return to check for 
	# more possible values 
	if (count == n and graph[currPos][0]): 
		answer.append(cost + graph[currPos][0]) 
		return

	# BACKTRACKING STEP 
	# Loop to traverse the adjacency list 
	# of currPos node and increasing the count 
	# by 1 and cost by graph[currPos][i] value 
	for i in range(n): 
		if (v[i] == False and graph[currPos][i]): 
			
			# Mark as visited 
			v[i] = True
			tsp(graph, v, i, n, count + 1, cost + graph[currPos][i]) 
			
			# Mark ith node as unvisited 
			v[i] = False

# Driver code 

# n is the number of nodes 
if __name__ == '__main__': 

	answer = [] 
    # n is the number of nodes
	n = int(input("Enter number of nodes: "))

	print("Enter distance table:")
	graph = []
	for i in range(n):
		graph.append([int(j) for j in input().split()])
	# Boolean array to check if a node 
	# has been visited or not 
	v = [False for i in range(n)] 
	
	# Mark 0th node as visited 
	v[0] = True

	tsp(graph, v, 0, n, 1, 0) 

	print("Minimum cost of the route: ", min(answer)) 


"""
Sample Input / Output:

Enter number of nodes: 4
Enter distance table:
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0
Minimum cost of the route:  35

Enter number of nodes: 6
Enter distance table:
0 12 29 22 13 24
12 0 19 3 25 6
29 19 0 21 23 28
22 3 21 0 4 5
13 25 23 4 0 16
24 6 28 5 6 0
Minimum cost of the route:  75

"""


