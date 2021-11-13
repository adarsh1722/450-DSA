#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class solution
{
public:
    vector<int> bfsOnGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;
        vector<int> vis(V);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node])
            {
                if (vis[it] == 0)
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
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
    vector<int> ans = obj.bfsOnGraph(n, adj);
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}
