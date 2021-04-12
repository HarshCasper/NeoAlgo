/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. 
Print true if the path exists and false otherwise.
*/

#include <iostream>
using namespace std;
// create a boolean fucntion to check path which return true or false
bool path(int V, int** mat, bool* visited, int v1, int v2){    
	
    //base case (check if the vertices are adjacent)
    if(mat[v1][v2]==1){        
        return true;
    }  
    visited[v1]=true;
    
    for(int i=0; i<V; i++){
        if(visited[i]){
            continue;
        }
        // visited[i]=true;
	//If this adjacent node is the destination node, then return true
        if(mat[v1][i]==1){
	    bool small=path(V, mat, visited, i, v2);
            if(small==true){
                return true;
            }
        }
    }    
    return false;
}

int main() {
    int V, E;
    //take input of the vertices and edges of the graph
    cin >> V >> E;
    int** mat= new int*[V];
    for(int i=0; i<V; i++){
    	mat[i]=new int[V];
    	for(int j=0; j<V; j++){
            mat[i][j]=0;
      	}
    }
    for(int i=0; i<E; i++){
        int f,g;
        cin>>f>>g;
        mat[f][g]=1;
        mat[g][f]=1;
    }
    
    bool* visited= new bool[V];
    for(int i=0; i<V; i++){
	// Mark all the vertices as not visited
        visited[i]=false;
    }
    int v1, v2;
    //take input of the vertices v1 and v2, to check if a path exists between them
    cin>>v1>>v2;
    
    //call the fucntion
    bool small=path(V, mat, visited, v1, v2);
    
    if(small){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}


/*
Time Complexity: O(V+E)

Space Complexity: O(V^2)
where V is the number of vertices and E is the number of edges in the input graph

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
*/
