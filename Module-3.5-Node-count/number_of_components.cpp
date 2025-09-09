#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void dfs(int src)
{
    // cout << src << " ";

    visited[src] = true;
    for (int child : adj_list[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
            // cout << endl;
        }
    }

    cout << cnt << endl;

    return 0;
}