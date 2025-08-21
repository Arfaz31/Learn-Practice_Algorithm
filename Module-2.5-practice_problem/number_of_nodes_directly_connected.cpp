#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n); // vector of vectors

    // Graph input
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int node;
    cin >> node;

    // Directly connected node count
    cout << adj[node].size() << endl;

    return 0;
}
