import java.util.ArrayList;
import java.util.HashMap;

public class Bellman_Ford {

	public static void main(String[] args) {

		ArrayList<String> Vertices = new ArrayList<>();
		ArrayList<Edge> EdgeList = new ArrayList<>();

		// vertices
		Vertices.add("A");
		Vertices.add("B");
		Vertices.add("C");
		Vertices.add("D");

		// edges
		EdgeList.add(new Edge("A", "B", 3));
		EdgeList.add(new Edge("A", "D", 8));
		EdgeList.add(new Edge("B", "C", 1));
		EdgeList.add(new Edge("C", "A", -1));
//		EdgeList.add(new Edge("C", "A", -5));	// negative cycle case
		EdgeList.add(new Edge("C", "D", 2));

		// result
		HashMap<String, BFpair> result = new HashMap<>();

		String srcname = "A";

		for (String vname : Vertices) {
			BFpair bfp = new BFpair();
			if (vname.equals(srcname)) {
				bfp.csf = 0;
				bfp.psf = vname;
			} else {
				bfp.csf = Integer.MAX_VALUE;
				bfp.psf = null;
			}
			result.put(vname, bfp);
		}

		for (int i = 1; i <= Vertices.size() - 1; i++) {
			for (Edge edge : EdgeList) {
				String svname = edge.v1name;// source vertex
				String dvname = edge.v2name;// destination vertex
				int wt = edge.weight;

				BFpair sp = result.get(svname);// src pair
				BFpair dp = result.get(dvname);// dest pair

				if (sp.psf == null) {
		 			continue;
				} else if (sp.csf + wt < dp.csf) {
					dp.csf = sp.csf + wt;
					dp.psf = sp.psf + dvname;
				}

				result.put(dvname, dp);
			}
		}

		// check for cycle
		for (Edge edge : EdgeList) {
			String svname = edge.v1name;// source vertex
			String dvname = edge.v2name;// destination vertex
			int wt = edge.weight;

			BFpair sp = result.get(svname);// src pair
			BFpair dp = result.get(dvname);// dest pair

			if (sp.psf == null) {
				continue;
			} else if (sp.csf + wt < dp.csf) {
				System.out.println("negative cycle present");
				break;
//				dp.csf = sp.csf + wt;
//				dp.psf = sp.csf + dvname;
			}
			result.put(dvname, dp);
		}

		System.out.println(result);

	}

	public static class Edge {
		String v1name;
		String v2name;
		int weight;

		public Edge(String v1, String v2, int w) {
			this.v1name = v1;
			this.v2name = v2;
			this.weight = w;
		}
	}

	public static class BFpair {
		int csf;
		String psf;

		public String toString() {
			return " @ " + this.csf + " via " + this.psf;
		}
	}

}