/**
Topological sort is linear ordering of vertices
in a directed acyclic graph (DAG). This algorithm is useful in 
solving many other applications on DAG
**/

import java.io.*; 
import java.util.*;

public class TopologicalSort {
	private static void dfs_visit(ArrayList<ArrayList<Integer> > graph, int src, Stack<Integer> s, boolean[] visit) {
		visit[src] = true;
		for(int i = 0; i < graph.get(src).size(); i++)
			if(visit[graph.get(src).get(i)] == false)
			    dfs_visit(graph, graph.get(src).get(i), s, visit);
	    s.push(new Integer(src));
	}

	private static void dfs(ArrayList<ArrayList<Integer> > graph, int v, Stack<Integer> s) {
		boolean[] visit = new boolean[v];
		for(int i = 0; i < v; i++)
			if(visit[i] == false)
				dfs_visit(graph, i, s, visit);
	}

	private static void topological_sort(ArrayList<ArrayList<Integer> > graph, int v) {
		Stack<Integer> s = new Stack<Integer>();
		dfs(graph, v, s);
		while(s.empty() == false)
			System.out.print(s.pop() + " ");
		System.out.println();
	}

	public static void main(String[] args) {
		int v, e, a, b;
		// all vertices are labelled from 0 to v-1
		Scanner sc= new Scanner(System.in);
		v = sc.nextInt();
		e = sc.nextInt();
		ArrayList<ArrayList<Integer> > graph = new ArrayList<ArrayList<Integer> >(v);
		for (int i = 0; i < v; i++) 
            graph.add(new ArrayList<Integer>());
		// all directed edges
		for(int i = 0; i < e; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			// edge a -> b
			graph.get(a).add(b);
		} 
		topological_sort(graph, v);
	}
}

/**
Input :
6 8
0 3
0 4
0 5
1 5
1 0
2 1
3 4
4 5
Output :
2 1 0 3 4 5
Time Complexity : O(v+e)
Space Complexity : O(v)
**/

