"""
Time complexity: O(ElogE + ElogV)
ElogE for sorting E number of edges
ElogV for FIND and UNION operations on V nodes
with E edges
"""
class MST:
    def __init__(self, V, E):
        self.V = V
        self.E = E
        self.edgelist = list()
        self.parent = {n: -1 for n in range(V)}
        self.rank = {n: 0 for n in range(V)}
        self.mst = list()

    def input_edge(self, frm, to, wt):
        self.edgelist.append([frm, to, wt])

    def find(self, n):
        if self.parent[n] == -1:
            return n
        else:
            self.parent[n] = self.find(self.parent[n])
            return self.parent[n]

    def union(self, frm, to):

        if self.rank[frm] > self.rank[to]:
            self.parent[to] = frm

        elif self.rank[frm] < self.rank[to]:
            self.parent[frm] = to

        else:
            self.parent[frm] = to
            self.rank[to] += 1

    def isCycle(self, frm, to):

        if frm == to:
            return True
        else:
            return False

    def kruskal(self):

        sorted(self.edgelist, key=lambda k: k[2])

        mst_edges = 0
        edge_ctr = 0
        while mst_edges < self.V - 1 and edge_ctr < self.E:

            abs_frm = self.find(self.edgelist[edge_ctr][0])
            abs_to = self.find(self.edgelist[edge_ctr][1])

            if self.isCycle(abs_frm, abs_to):
                edge_ctr += 1
                continue
            else:
                self.union(abs_frm, abs_to)
                self.mst.append(self.edgelist[edge_ctr])
                mst_edges += 1

    def outputMST(self):
        for edge in self.mst:
            o = f'from : {edge[0]} | to : {edge[1]} | wieght : {edge[2]}'
            print(o)


def main():
    print("Input number of nodes and edges: ")
    n, e = map(int, input().split())

    mst = MST(n, e)

    print("Input the edges along with weights (from to weight): ")
    for _ in range(e):
        frm, to, wt = map(int, input().split())
        mst.input_edge(frm, to, wt)

    mst.kruskal()
    mst.outputMST()


if __name__ == '__main__':
    main()


"""
Sample input:

$python3 min_spanning_tree.py
Input number of nodes and edges:
6 10
Input the edges along with weights (from to weight):
0 1 1
1 3 1
2 4 1
0 2 2
2 3 2
3 4 2
1 2 3
1 4 3
4 5 3
3 5 4
from : 0 | to : 1 | wieght : 1
from : 1 | to : 3 | wieght : 1
from : 2 | to : 4 | wieght : 1
from : 0 | to : 2 | wieght : 2
from : 4 | to : 5 | wieght : 3
"""
