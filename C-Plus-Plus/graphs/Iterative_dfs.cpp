/*
->Stack is used to display dfs traversal of the graph.
->Similar to bfs traversal , only the queue is replaced by stack.
->A vector list is returned containing the dfs traversal from source vertex as 0.
->Two stacks are maintained for printing dfs starting from Oth vertex from left to right.
*/

#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <stack>
class graph
{
public:
    int v;
    list<int> *l;
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    /*
    Function to display the graph
    void printg()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            for (int nbrs : l[i])
            {
                cout << nbrs << ",";
            }
            cout << "\n";
        }
    }
    */
};
vector<int> iterative_dfs(graph g, vector<bool> &visited, int src)
{
    stack<int> helper_st;
    stack<int> main_st;
    vector<int> dfs_ans;

    main_st.push(0);
    //loop until main stack is empty
    while (main_st.size() > 0)
    {
        if (visited[main_st.top()] == true)
        {
            main_st.pop();
            continue;
        }
        int t = main_st.top();
        dfs_ans.push_back(main_st.top());

        visited[main_st.top()] = true;
        main_st.pop();

        for (int nbrs : g.l[t])
        {
            if (visited[nbrs] == false)
            {
                helper_st.push(nbrs);
            }
        }
        //Copying contents from helper to main stack for printing nbrs left to right
        while (helper_st.size() > 0)
        {
            main_st.push(helper_st.top());
            helper_st.pop();
        }
    }
    return dfs_ans;
}
int main()
{
    int vertices, edges;
    //cout<<"Enter no of vertices and edges: ";
    cin >> vertices >> edges;
    graph g(vertices);
    int x, y;
    for (int i = 0; i < edges; i++)
    {
        cin >> x >> y;
        g.addEdge(x, y);
    }
    // g.printg();
    vector<bool> visited(vertices, false);

    //Function call to iterative_dfs with source as 0th vertex
    vector<int> ans = iterative_dfs(g, visited, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
/*
Sample Input:
5 4
0 1
0 2
0 4
4 3

Output:
0 1 2 4 3

*/
