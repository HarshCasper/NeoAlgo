from collections import deque

class Graph:
    def __init__(self, directed=True):
        self.edges = {}
        self.directed = directed

    def add_edge(self, node1, node2, __reversed=False):
        try: neighbors = self.edges[node1]
        except KeyError: neighbors = set()
        neighbors.add(node2)
        self.edges[node1] = neighbors
        if not self.directed and not __reversed: self.add_edge(node2, node1, True)

    def neighbors(self, node):
        try: return self.edges[node]
        except KeyError: return []

    def depth_limited_search(self, start, goal, limit=-1):
        print('Depth limit =', limit)
        found, fringe, visited, came_from = False, deque([(0, start)]), set([start]), {start: None}
        print('{:11s} | {}'.format('Expand Node', 'Fringe'))
        print('--------------------')
        print('{:11s} | {}'.format('-', start))
        while not found and len(fringe):
            depth, current = fringe.pop()
            print('{:11s}'.format(current), end=' | ')
            if current == goal: found = True; break
            if limit == -1 or depth < limit:
                for node in self.neighbors(current):
                    if node not in visited:
                        visited.add(node); fringe.append((depth + 1, node))
                        came_from[node] = current
            print(', '.join([n for _, n in fringe]))
        if found: print(); return came_from
        else: print('No path from {} to {}'.format(start, goal))

    @staticmethod
    def print_path(came_from, goal):
        parent = came_from[goal]
        if parent:
            Graph.print_path(came_from, parent)
        else: print(goal, end='');return
        print(' =>', goal, end='')

    def __str__(self):
        return str(self.edges)


graph = Graph(directed=False)
graph.add_edge('A', 'B')
graph.add_edge('A', 'S')
graph.add_edge('S', 'G')
graph.add_edge('S', 'C')
graph.add_edge('C', 'F')
graph.add_edge('G', 'F')
graph.add_edge('C', 'D')
graph.add_edge('C', 'E')
graph.add_edge('E', 'H')
graph.add_edge('G', 'H')
start, goal, l = 'A', 'H', 3
traced_path = graph.depth_limited_search(start, goal, l)
if (traced_path): print('Path:', end=' '); Graph.print_path(traced_path, goal);print()


"""
Output:
Depth limit = 3
Expand Node | Fringe
--------------------
-           | A
A           | S, B
B           | S
S           | G, C
C           | G, D, E, F
F           | G, D, E
E           | G, D
D           | G
G           | H
H           | 
Path: A => S => G => H
"""