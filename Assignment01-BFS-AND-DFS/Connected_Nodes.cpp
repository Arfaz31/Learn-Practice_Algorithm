#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int node;
        cin >> node;
        if (adj[node].empty())
        {
            cout << -1 << endl;
        }
        else
        {
            // sort descending order
            sort(adj[node].begin(), adj[node].end(), greater<int>());
            for (int x : adj[node])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}