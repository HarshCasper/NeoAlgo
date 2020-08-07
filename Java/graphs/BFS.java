import java.util.*;

public class BFS {

	public static void breadthFirst(int edges[][],int V) {
//		A visited array to mark if the node is visited then not to go there again
		boolean visited[]=new boolean[V];
		
		for(int i=0;i<V;i++) {
			if(!visited[i]) {
				breadthFirstHelper(edges,visited,i);
			}
		}
	}
	
	public static void breadthFirstHelper(int edges[][],boolean visited[],int sv) {
		
		int V=edges.length;
		
		visited[sv]=true;
		
		Queue<Integer> queue=new LinkedList<Integer>();
		queue.add(sv);
		
		while(!queue.isEmpty()) {
			
			int size=queue.size();
			
			for(int i=0;i<size;i++) {
				int frontNode=queue.poll();
				for(int j=0;j<V;j++) {
					if(edges[frontNode][j]==1&&!visited[j]) {
						queue.add(j);
						visited[j]=true;
					}
				}
				System.out.print(frontNode+" ");
			}
		}
		
	}
	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
	
		System.out.println("Enter the number of vertices in Graph : ");
		int V=sc.nextInt();
		
		System.out.println("Enter the number of edges in the Graph : ");
		int E=sc.nextInt();
		
//		Adjaceny Matrix :
		int edges[][]=new int[V][V];
		
//		Taking edges as input :
		System.out.println("Enter the edges :");
		for(int i=0;i<E;i++) {
			int sv=sc.nextInt();
			int ev=sc.nextInt();
			edges[sv][ev]=1;
			edges[ev][sv]=1;
		}
		
		System.out.println("BFS Traversal : ");
		breadthFirst(edges,V);

	}
	
/*
Sample Case : 

Enter the number of vertices in Graph : 
4
Enter the number of edges in the Graph : 
4
Enter the edges :
0 1
1 2
0 2
2 3
BFS Traversal : 
0 1 2 3 
*/
	 
}
