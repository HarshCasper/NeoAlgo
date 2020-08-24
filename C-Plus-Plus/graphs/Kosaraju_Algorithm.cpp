#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    list<int> *rl;
    int V;
    vector<int> order;
    int vis[1000],comp[1000];

    public:

        Graph(int V){
            this->V=V;
            l=new list<int>[V];
            rl=new list<int>[V];

        }

        void addEdge(int x,int y){
            l[x].push_back(y);
            rl[y].push_back(x);
        }

        void dfs(int cur){
            vis[cur]=1;
            for(auto x:l[cur]){
                if(!vis[x]){
                    dfs(x);
                }
            }
            order.push_back(cur);
        }

         void dfs_reverse(int cur,int col){
            vis[cur]=1;
            comp[cur]=col;
            for(auto x:rl[cur]){
                if(!vis[x]){
                    dfs_reverse(x,col);
                }
            }

        }

        void solve(){

            memset(vis,0,V);

            for(int i=0;i<V;i++){
                if(!vis[i]){
                    dfs(i);
                }
            }
            for(int i=0;i<V;i++){
                vis[i]=0;
            }
            int col=1;
            for(int i=V-1;i>=0;i--){
                if(!vis[order[i]]){
                    dfs_reverse(order[i],col);
                    col++;
                }

            }

            for(int i=0;i<V;i++){
                cout<<i<<": "<<comp[i]<<endl;
            }

        }
};

int main(){
    int n,e;
    cout<<"Enter number of vertices and edges";
    cin>>n>>e;
    Graph g(n);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        g.addEdge(x,y);
    }

    g.solve();
    return 0;
}
