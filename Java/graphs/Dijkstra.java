import java.util.HashMap;
import java.util.Map;
import java.util.NavigableSet;
import java.util.TreeSet;

/**
 * There are more efficient ways of implementing this. The decision of using the predefined Java structures
 * was mainly due to laziness rather than any other thing.
 * 
 * @author Ricardo Prins
 * @since 6-26-2020
 */
public class Dijkstra {

    class Graph {
        // mapping of vertex names to Vertex objects, built from a set of Edges
        private final Map<String, Vertex> graph;
        
        public Graph(Edge[] edges) {
            graph = new HashMap<>(edges.length);

            // one pass to find all vertices
            for (Edge e : edges) {
                if (!graph.containsKey(e.v1)) graph.put(e.v1, new Vertex(e.v1));
                if (!graph.containsKey(e.v2)) graph.put(e.v2, new Vertex(e.v2));
            }

            // another pass to set neighbouring vertices
            for (Edge e : edges) {
                graph.get(e.v1).neighbours.put(graph.get(e.v2), e.dist);
                // graph.get(e.v2).neighbours.put(graph.get(e.v1), e.dist); //for an undirected graph
            }
        }

        public void dijkstra(String startName) {
            if (!graph.containsKey(startName)) {
                System.err.printf("Graph doesn't contain start vertex \"%s\"\n", startName);
                return;
            }
            final Vertex source = graph.get(startName);
            NavigableSet<Vertex> q = new TreeSet<>();

            for (Vertex v : graph.values()) {
                v.previous = v == source ? source : null;
                v.dist = v == source ? 0 : Integer.MAX_VALUE;
                q.add(v);
            }

            dijkstra(q);
        }

        private void dijkstra(final NavigableSet<Vertex> q) {
            Vertex u, v;
            while (!q.isEmpty()) {
                u = q.pollFirst();
                if (u.dist == Integer.MAX_VALUE) break;

                for (Map.Entry<Vertex, Integer> a : u.neighbours.entrySet()) {
                    v = a.getKey();

                    final int alternateDist = u.dist + a.getValue();
                    if (alternateDist < v.dist) {
                        q.remove(v);
                        v.dist = alternateDist;
                        v.previous = u;
                        q.add(v);
                    }
                }
            }
        }

        public void printPath(String endName) {
            if (!graph.containsKey(endName)) {
                System.err.printf("Graph doesn't contain end vertex \"%s\"\n", endName);
                return;
            }

            graph.get(endName).printPath();
            System.out.println();
        }

        public void printAllPaths() {
            for (Vertex v : graph.values()) {
                v.printPath();
                System.out.println();
            }
        }

        public class Edge {
            public final String v1, v2;
            public final int dist;

            public Edge(String v1, String v2, int dist) {
                this.v1 = v1;
                this.v2 = v2;
                this.dist = dist;
            }
        }

        public class Vertex implements Comparable<Vertex> {
            public final String name;
            public final Map<Vertex, Integer> neighbours = new HashMap<>();
            public int dist = Integer.MAX_VALUE; // MAX_VALUE here is used as assumption for a +infinite value
            public Vertex previous = null;

            public Vertex(String name) {
                this.name = name;
            }

            private void printPath() {
                if (this == this.previous) {
                    System.out.printf("%s", this.name);
                } else if (this.previous == null) {
                    System.out.printf("%s(unreached)", this.name);
                } else {
                    this.previous.printPath();
                    System.out.printf(" -> %s(%d)", this.name, this.dist);
                }
            }

            public int compareTo(Vertex other) {
                if (dist == other.dist)
                    return name.compareTo(other.name);

                return Integer.compare(dist, other.dist);
            }

            @Override
            public String toString() {
                return "(" + name + ", " + dist + ")";
            }
        }
    }
}
