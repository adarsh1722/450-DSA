#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class solution
{
public:
    void Dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
    {
        dfs.pb(node);
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                Dfs(it, vis, adj, dfs);
            }
        }
    }
    vector<int> dfsOnGraph(int V, vector<int> adj[])
    {
        vector<int> dfs;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                Dfs(i, vis, adj, dfs);
            }
        }

        return dfs;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    solution obj;
    vector<int> ans = obj.dfsOnGraph(n, adj);
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}
