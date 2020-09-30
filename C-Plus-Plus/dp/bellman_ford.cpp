#include<bits/stdc++.h>
using namespace std;
#define MAX 10

//Structure
typedef struct ed
{
  int from,dest,wt;
}ed;

//Bellman ford function began
void bellman(int nv,ed e[],int src_graph,int ne)
{
  int u,v,weight,i,j=0;
  int arr[MAX];
  
  /* initializing array 'arr' with 999.*/
  for(i=0;i<nv;i++)
  {
    //999 is infinte distance
    arr[i]=999;
  }
  arr[src_graph]=0;
  for(i=0;i<nv-1;i++)
  {
    for(j=0;j<ne;j++)
    {
      u=e[j].from;
      v=e[j].dest;
      weight=e[j].wt;
      if(arr[u]!=999 && arr[u]+weight < arr[v])
      {
        arr[v]=arr[u]+weight;
      }  
    } 
  }
  
  /* check for negative cycle*/
  for(j=0;j<ne;j++)
  {
    u=e[j].from;
    v=e[j].dest;
    weight=e[j].wt;
    
    if(arr[u]+weight < arr[v])
    {
      cout<<"\n\nThere is NEGATIVE CYCLE!!\n";
      return;
    }  
  }
  // Print the output
  cout<<"\n\tOUTPUT\n";
  cout<<"\nVertex"<<"  Distance from source";
  for(i=1;i<=nv;i++)
  {
    cout<<"\n"<<i<<"\t"<<arr[i];
  }
}
//Bellman Ford function end

//Main Function began
int main()
{
  int nv,ne,src_graph;
  ed e[MAX];
  //Take input from the user
  cout<<"Enter the number of vertices: ";
  cin>>nv;  
  
  /* if you enter no of vertices: 5 then vertices will be 1,2,3,4,5.*/
  printf("Enter the source vertex: ");
  cin>>src_graph;  
  //Enter number of edges 
  cout<<"\nEnter no. of edges: ";
  cin>>ne;
  
  for(int i=0;i<ne;i++)
  {
    cout<<"\nEdge "<<i+1<<"=>";
    cout<<"\nEnter source vertex :";
    cin>>e[i].from;
    cout<<"Enter destination vertex :";
    cin>>e[i].dest;
    cout<<"Enter weight :";
    cin>>e[i].wt;  
  }
  //calling bellman ford function
  bellman(nv,e,src_graph,ne);
  return 0;
}
//Main function ends

/*Sample Input Output

Enter the number of vertices: 4
Enter the source vertex: 1

Enter no. of edges: 4

Edge 1=>
Enter source vertex :1
Enter destination vertex :2
Enter weight :4

Edge 2=>
Enter source vertex :1
Enter destination vertex :3
Enter weight :3

Edge 3=>
Enter source vertex :2
Enter destination vertex :4
Enter weight :7

Edge 4=>
Enter source vertex :3
Enter destination vertex :4
Enter weight :-2

Vertex  Distance from source
1       0
2       4
3       3
4       1

Time Complexity : O(V*E)
where V is no. of vertices and E is no. of edges in the graph.
*/
