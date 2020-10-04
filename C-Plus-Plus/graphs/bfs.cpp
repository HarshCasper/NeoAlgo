#include<iostream>
#include<conio.h>
#include <queue> 
using namespace std;
int main(){
    int n,i;
    cout<<"\nEnter the no. of vertex of graph";
    cin>>n;
    int graph[n][n];
    cout<<"\nEnter the graph edges(0 if the edge is not present and 1 if present b/w two vertex)\n"; 
    for( i=0; i<n; i++){
    for (int j=0; j<n; j++) {
       cin>>graph[i][j];
    }
  }
  cout<<"\nThe adjacency matrix of your graph so that you can check you input the edges correctly\n";
  for(int i=0; i<n; i++)
{
    for (int j=0; j<n; j++)
    {
       cout<<" "<<graph[i][j];
    }
    cout<<"\n";

 }

bool visited[n];
int arr[n];
for (int m = 0; m < n; m++)
{
       arr[m]=-1;
}

int k=0;
int source;
cout<<"\nEnter the source node \n";
cin>>source;
queue<int>q;
q.push(source);
arr[k]=source;
visited[source]=true;
while (!q.empty())
{
    int i;
    i=q.front();
    q.pop();
    for (int j = 0; j < n; j++)
    {
        if (graph[i][j]==1&&visited[j]!=true)
        {
            visited[j]=true;
            q.push(j);
            arr[k+1]=j;
            k++;
        }
        
    }
    
}
cout<<"\nThe bfs traversal starting from source node "<<source<<endl; 
for (int l= 0; l<n ; l++) {
            cout<<" "<<arr[l];
        }


return 0;

}
