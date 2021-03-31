/*
Query: Travelling Salesman Problem

Task:
We are given a set of cities and distances between each pair of cities,
we have to find the shortest possible path visiting every city 
exactly once and returning to the initial city.


Input :A matrix representing the distance between each nodes

Output :The minimum cost of visiting every city once and returning to the starting point.

*/

#include<bits/stdc++.h>
using namespace std;

/*Number of cities */
int CITIES;
/*
The answer is the min distance to travel all the cities
once and returning back to the initial city 
*/
int  min_dist = INT_MAX;

/* Here int the function we have:
    a) dist vector: Distanve Vector By the User
    b) visited vector : boolean Visited vector denoting whether the current City
                        is visited or not
    c) count : Count of the number of cities visited
    d) cost : Cost till current visit
    e) ans : Final minimum cost of travelling Salesman Problem
*/
void tsp(vector<vector<int> > dist, vector<bool>& visited, int curCity, int count, int cost, int& ans)
{
  
    /* 
	If last city is reached and it has a path 
    to the starting node then keep the
	minimum value out of the total cost
    of traversal 
    */
    if (count == CITIES && dist[curCity][0]) {
        ans = min(ans, cost + dist[curCity][0]);
        return;
    }
  
    // BACKTRACKING STEP
    /* 
		Traverse the dist matrix
	    of curCity node and increasing the count
	    by 1 and cost by dist[curCity][i] value
    */
    for (int city_1 = 0; city_1 < CITIES ; city_1++) {
        if (!visited[city_1] && dist[curCity][city_1]) {
  
            // Mark as visited
            visited[city_1] = true;
            tsp(dist, visited , city_1, count + 1, cost + dist[curCity][city_1], ans);
  
            // Mark ith node as unvisited
            visited[city_1] = false;
        }
    }
}
  

int main(){
	
	/* Input the number of cities */   
    cin >> CITIES; 
    
    /* The answer */
    min_dist = INT_MAX;
	   
   
    /* init the distance maatrix*/
    vector<vector<int> > dist( CITIES , vector<int> ( CITIES , 0 ));
    
    /* Visited vector */
    vector<bool> visited(CITIES);
    
    /*Enter the distance*/
    for(int city_1=0 ; city_1 < CITIES ; city_1++){
        for(int city_2=0 ; city_2 < CITIES ; city_2++){
        	
            cin >> dist[city_1][city_2];
            
            visited[city_1] = false;
        }
    }
	

    /* Mark 0th node as visited */
    visited[0] = true;
    
  
    /* Find the minimum weight Hamiltonian Cycle */
    tsp(dist, visited , 0, 1, 0,  min_dist);
  
    /* min_dist is the minimum weight Hamiltonian Cycle   */     
	cout<<"Travelling Salesman Distance is "<< min_dist;

	return 0;
}


/*Complexities:
	Time Complexity : O (n!)

   Sample Test Cases:
		Input 1:
			{ 0, 10, 15, 20 },
			{ 10, 0, 35, 25 },
			{ 15, 35, 0, 30 },
			{ 20, 25, 30, 0 }
		Output:
			80
			
		Input 2:
			{ 0, 10, 15, 20 },
			{ 5, 0, 9, 10 },
			{ 6, 13, 0, 12 },
			{ 8, 8, 9, 0 }
		Output:
			35
			
*/