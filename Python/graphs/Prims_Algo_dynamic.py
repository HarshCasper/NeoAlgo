class graph:
    #Dictionary with keys to map the corresponding vertex object
    def __init__(self):
        self.vertices = {}
 
    #Adding vertex to the graph with the key provided
    def Addvertex(self, key):
        vertex = Vertex(key)
        self.vertices[key] = vertex
 
    #Getting vertex object with the corresponding key!
    def Getvertex(self, key):
        return self.vertices[key]
 
    def __contains__(self, key):
        return key in self.vertices
 
    #Adding edge from source key to the destination key with given weight
    def Addedge(self, source_key, destination_key, weight=1):
        self.vertices[source_key].Addnbr(self.vertices[destination_key], weight)
 
    #To check weather the edge exits or not.
    def Edge_exists(self, source_key, destination_key):
        return self.vertices[source_key].pointing_to(self.vertices[destination_key])
 
    def Display(self):
        print('Vertices: ', end='')
        for v in self:
            print(v.get_key(), end=' ')
        print("***")
 
        print('Edges: ')
        for v in self:
            for destination in v.getnbr():
                w = v.getweight(destination)
                print('(source={}, destination={}, weight={}) '.format(v.get_key(),
                                                             destination.get_key(), w))
 
    def __len__(self):
        return len(self.vertices)
 
    def __iter__(self):
        return iter(self.vertices.values())
 
 
class Vertex:
    def __init__(self, key):
        self.key = key
        self.points_to = {}
 
    #getting key corresponding to vertex object
    def get_key(self):
       return self.key
 
    #adding this vertex point to destination with provided edge weight
    def Addnbr(self, destination, weight):
        self.points_to[destination] = weight
 
    #Returns all vertices pointed by this vertex
    def getnbr(self):
        return self.points_to.keys()
 
    #Getting weight of edge from this vertex to destination.
    def getweight(self, destination):
        return self.points_to[destination]
 
    #returns true if the vertex points towards destination
    def pointing_to(self, destination):
        return destination in self.points_to
 
 
def Prims_mst(g):
    #creating new graph object to hold MST
    mst = graph() 
 
    #If graph is empty
    if not g:
        return mst
 
    #nearest neighbour of v in MST
    #v is a vertex outside the mst and has at least one neighbour in the MST
    nearest_nbr = {}
    #Smallest distance of v to the nearest neighbour
    smallest_distance = {}
    #v is not visited iff v is not added in the MST
    not_visited = set(g)
 
    u = next(iter(g)) # selects any one vertex from g
    mst.Addvertex(u.get_key())  #Adding a copy to MST
    not_visited.remove(u)
 
    # for each neighbour of vertex u
    for n in u.getnbr():
        if n is u:
            continue
        #updating dictionary
        nearest_nbr[n] = mst.Getvertex(u.get_key())
        smallest_distance[n] = u.getweight(n)
 
    #loop until smallest distance becomes NULL.
    while (smallest_distance):
        #Nearest vertex outside MST
        outside_mst = min(smallest_distance, key=smallest_distance.get)
        #nearest vertex inside MST
        inside_mst = nearest_nbr[outside_mst]
 
        #Adding a copy of the outside vertex to MST
        mst.Addvertex(outside_mst.get_key())
        #Adding edge to  MST
        mst.Addedge(outside_mst.get_key(), inside_mst.get_key(),smallest_distance[outside_mst])
        mst.Addedge(inside_mst.get_key(), outside_mst.get_key(),smallest_distance[outside_mst])
 
        #Outside MST added to MST successfully, hence removing from dictionaries and set not visited
        not_visited.remove(outside_mst)
        del smallest_distance[outside_mst]
        del nearest_nbr[outside_mst]
 
        #updating dictionary
        for n in outside_mst.getnbr():
            if n in not_visited:
                if n not in smallest_distance:
                    smallest_distance[n] = outside_mst.getweight(n)
                    nearest_nbr[n] = mst.Getvertex(outside_mst.get_key())
                else:
                    if smallest_distance[n] > outside_mst.getweight(n):
                        smallest_distance[n] = outside_mst.getweight(n)
                        nearest_nbr[n] = mst.Getvertex(outside_mst.get_key())
 
    return mst
 
 
g = graph()

print('||-Undirected Graph-||')
print('Menu')
print('***x***')
print('add vertex <key>')
print('add edge <source> <destination> <weight>')
print('mst')
print('Display')
print('quit')
print('***x***')
 
while True:
    do = input('What you wanna do? ').split()
 
    operation = do[0]
    if operation == 'add':
        suboperation = do[1]
        if suboperation == 'vertex':
            key = int(do[2])
            if key not in g:
                g.Addvertex(key)
            else:
                print('Vertex pre exists!!')
        elif suboperation == 'edge':
            source = int(do[2])
            destination = int(do[3])
            weight = int(do[4])
            if source not in g:
                print('Vertex {} does not exist.'.format(source))
            elif destination not in g:
                print('Vertex {} does not exist.'.format(destination))
            else:
                if not g.Edge_exists(source, destination):
                    g.Addedge(source, destination, weight)
                    g.Addedge(destination, source, weight)
                else:
                    print('Edge pre exists...')
 
    elif operation == 'mst':
        mst = Prims_mst(g)
        print('Minimum Spanning Tree:')
        mst.Display()
        print("***")
 
    elif operation == 'Display':
        g.Display()
        print("***")
 
    elif operation == 'quit':
        break
