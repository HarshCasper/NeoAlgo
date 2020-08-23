#include<iostream>
#include<list>
#include<vector>
#include<cstring>
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
                //cout<<vis[i]<<" ";
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

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(2,0);
    g.addEdge(1,2);
    g.addEdge(3,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,3);
    g.solve();
    return 0;
}
