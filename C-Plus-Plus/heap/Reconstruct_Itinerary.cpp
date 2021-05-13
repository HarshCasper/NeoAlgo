/*--------------- RECONSTRUCT ITINERARY-------*/

/* In this problem we are given a 2-d vector named Tickets
   You are given a list of airline tickets where 
   tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight.

   ---TASK---
   You are to return the vector that contains the inorder form of the intinerary. 
   All of the tickets belong to a man who departs from "JFK", thus, the itinerary 
   must begin with "JFK". 
   If there are multiple valid itineraries, you should return the itinerary that has 
   the smallest lexical order when read as a single string. 

   ---EXAMPLE---
   Given tickets vector
   [["MUC","LHR"],
    ["JFK","MUC"],
    ["SFO","SJC"],
    ["LHR","SFO"]]

   ---APPROACH---
   1. Make an adjacency list from the given 2-d vector of the form 
       string -> multiset of strings
   2. Make a stack
   3. Iterate over the list, for every list[i] add the strings in the multiset to stack and remove it from the set
   4. If the list[i] is empty then, pop the top element from the stack ans push it to the final answer vector
   5. Keep on repeating the steps 3 and 4 untill the stack is empty
   6. Now the answer vector stores the reverse inorder for our itinerary
   7. Reverse the ans vector and then return.
*/

#include <bits/stdc++.h>
using namespace std;
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    // map to store the adjacency list of the airports
    // Multiset is used so that the airports are in lexicographic order
    map<string, multiset<string>> adj;

    // vector to store the answer
    vector<string> ans;

    stack<string> myStack;
    myStack.push("JFK"); // for the starting is always from JFK

    // making the adjacency list of the strings
    for (int i = 0; i < tickets.size(); i++)
    {
        adj[tickets[i][0]].insert(tickets[i][1]);
    }
    // Iterating over the list and stack
    while (!myStack.empty())
    {
        //  get the top element
        string src = myStack.top();

        // check if size of multiset of src is zero or not
        if (adj[src].size() == 0)
        {
            ans.push_back(src);
            myStack.pop();
        }
        else
        {
            auto desti = adj[src].begin();
            myStack.push(*desti);
            adj[src].erase(desti);
        }
    }
    // reverse the ans vector to get the final inorder
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // n denotes the number of tickets
    int n;
    cin >> n;

    vector<vector<string>> tickets(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            string a;
            cin >> a;
            tickets[i].push_back(a);
        }
    }

    vector<string> ans = findItinerary(tickets);
    // printing the ans vector
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i] << endl;
        cout << ans[i] << " -> ";
    }
}
/*------ CODE COMPLEXITY------
1. Firstly, making of adjacency list takes O(n) time
2. Then we enter the while loop, in which we traverse over every airport once and perform some 
   constant check-> O(2*n)
3. reverse the whole answer vector which also takes O(n) time

in whole TC of the code = O(n) + O(2*n) + O(n) = O(n) 
*/

/*-----SAMPLE INPUT-------
        
        MUC LHR 
        JFC MUC 
        SFO SJC 
        LHR SFO
 
 ------SAMPLE OUTPUT------
  
      JFK -> MUC -> LHR -> SFO -> SJC
 
 
 */
