/*
Description:
Tarjan's algorithm is an efficient way to find the strongly connected components i.e. SCC in a directed graph.
SCC: A Strongly Connected Component in a graph is a self contained cycle in a directed graph in which from each vertex in that cycle we can reach every other vertex of the same cycle.
disk represents the time at which a particular node is discovered or visited during DFS traversal. For every node we increament the disk time value by 1.
low represents the node with lowest discovery time accessible from a given node. If there is a back edge from a node, then the low is updated value based on some conditions. The maximum value low for a node can be assigned is equal to the disk value of that node as the minimum discovery time for a node is the time to discover the node itself.
Working of the code:
1: A hash map is used to form the graph. Initially, both the disk and low arrays are intialized with -1 to show that none of the nodes are visited. The stack array and the boolean in_stack is used to differentiate between back edge and cross edge. If the node is present in the stack, then it is a back-edge, otherwise it is the cross edge.
Back-edge
if(Back-Edge), then low[u]=min(low[u],disk[v]).
Tree-Edge-edge
if(Tree-Edge), then low[u]=min(low[u],low[v]).
2: If the node is visited, then it is added to the stack and marked true in the boolean in_stack. A static Timer variable is also mainatined which is initialized to 0. 
3: After visiting this node on returning the call to its parent node the low value is updated for each node to make sure that the low value remains same for all nodes in the strongly connected component. If the node has disk[u]=low[u], then it is the head node of that SCC. Every SCC must have a head node. Then, the nodes are by popping out of the stack marking the in_stack as false for each popped out value. All the nodes of strongly connecetd components have equal low values.
*/
// JAVA Code:

import java.util.*;
public class Tarjan_SCC
{

  static HashMap<Integer,List<Integer>> adj=new HashMap<>(); // to form the graph
  static int low[]=new int[10];
  static int disk[]=new int[10];
  static boolean in_stack[]=new boolean[10];
  static Stack<Integer> stack=new Stack<>();
  static int time = 0; // static time so that it is initialized only for once 

  static void Traversal(int u)
  {

	disk[u]=time;
	low[u]=time;
	time++;
	stack.push(u);
	in_stack[u]=true;
    List<Integer> temp=adj.get(u); // to get the list of edges from the node

    if(temp==null)
    return;

    for(int v: temp) // To differentiate back-edge and cross-edge
	{
		if(disk[v]==-1)	// If v node is not visited/dicovered
		{
			Traversal(v); // if it is not present in the stack, then it is a cross edge
			low[u] = Math.min(low[u],low[v]); 
		}

		else if(in_stack[v])	// if it is present in the stack, then it is the part of the current cycle and hence it is the back edge
			low[u] = Math.min(low[u],disk[v]);
	}

	if(low[u]==disk[u])	//In case if u is the head node of SCC
	{
		System.out.print("SCC is: "); // to print all the nodes that make SSC by popping them until we reach the head node of SSC
		while(stack.peek()!=u)
		{
			System.out.print(stack.peek()+" ");
			in_stack[stack.peek()] = false;
			stack.pop();
		}
		System.out.println(stack.peek());
		in_stack[stack.peek()] = false;
		stack.pop();
	}
  }

static void find_SCC_Tarjan(int n)
  {

    for(int i=1;i<=n;i++)
    {
        disk[i]=-1;
        low[i]=-1;
        in_stack[i]=false; // in_stack used to differentiate between the back-edge and cross-edge
    }


	for(int i=1;i<=n;i++)
	{
		if(disk[i]==-1)
			Traversal(i);   // Traversal call for each node yet to be discovered/visited
	}
  }

  public static void main(String args[])
  {
    adj.put(2,new ArrayList<Integer>());
    adj.get(2).add(3);

    adj.put(3,new ArrayList<Integer>());
    adj.get(3).add(1);

	adj.put(6,new ArrayList<Integer>());
	adj.get(6).add(2);
	adj.get(6).add(4);

	adj.put(9,new ArrayList<Integer>());
	adj.get(9).add(5);

	adj.put(5,new ArrayList<Integer>());
	adj.get(5).add(6);

	adj.put(6,new ArrayList<Integer>());
	adj.get(6).add(7);

	adj.put(8,new ArrayList<Integer>());
	adj.get(8).add(4);

	find_SCC_Tarjan(7);
  }

}


/*
prints 
SCC is: 7 6
SCC is: 5
Time Complexity:  O(V+E)    where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V)
*/