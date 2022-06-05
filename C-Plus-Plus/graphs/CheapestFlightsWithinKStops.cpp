// Cheapest flights within K stops

class Solution { 
public:
    // Function to find the cheapest price from source to destination 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX); // Initialize all distances as infinite
        vector<vector<pair<int,int>>> adj(n); // Initialize all adjacency lists as empty
        for(auto t:flights){ // Add all flights to the adjacency list
            adj[t[0]].push_back({t[1],t[2]}); // Add the destination and price to the adjacency list
        }
        int ans = INT_MAX; // Initialize the answer as infinite
        int level=0; // Initialize the level as 0
        queue<pair<int,int>> q; // Initialize the queue as empty
        dist[src]=0; // Set the source distance as 0
        q.push({src,0}); // Push the source to the queue
        while(!q.empty() && level<=k){ // While the queue is not empty and the level is less than or equal to k
            int sz =q.size();
            while(sz-- >0){ 
                int curNode = q.front().first; // Get the current node
                int curDis = q.front().second; // Get the current distance
                q.pop(); // Pop the current node from the queue
                if(curDis>dist[curNode]) continue; // If the current distance is greater than the current node distance, continue
                dist[curNode]= curDis; // Set the current node distance as the current distance
                for(auto adjEdge:adj[curNode]){ // For all the adjacent edges of the current node
                    if(adjEdge.first==dst) 
                        ans = min(ans,curDis+adjEdge.second); // If the destination is reached, update the answer
                    q.push({adjEdge.first,adjEdge.second+curDis}); // Push the destination and the current distance to the queue
                }
            }
            level++; // Increment the level
        }
        return ans==INT_MAX?-1:ans; // Return the answer if it is not infinite else return -1
    }
};


/*
Time Complexity: O(K*V)
Space Complexity: O(K*V)
where K is the maximum number of stops and V is the number of vertices 
*/

