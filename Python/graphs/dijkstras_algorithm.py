# Importing Libraries
import matplotlib.pyplot as plt
import networkx as nx

# Creating an empty Graph
g = nx.Graph()

# Adding Nodes to empty graph
for i in range(1, 7):
    g.add_node(i)

# Printing Nodes
# print("Nodes are ")
print(g.nodes())
# Adding Edges
g.add_edge(1, 2)
g.add_edge(1, 3)
g.add_edge(4, 6)
g.add_edge(5, 4)
g.add_edge(2, 3)
g.add_edge(2, 6)

# Edge Testing
print("Edges are ")
print(g.edges())

nx.draw(g)
plt.show()

# dijkstra's Algorithm
h = nx.Graph()
e = [('a', 'b', 1), ('b', 'c', 2),
     ('a', 'c', 3), ('c', 'd', 4), ('d', 'e', 2), ('b', 'e',  1)]

h.add_weighted_edges_from(e)
nx.draw(h, with_labels=True)
plt.show()

print(nx.dijkstra_path(h, 'a', 'e'))
