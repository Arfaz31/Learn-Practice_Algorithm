#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

void bfs(int src)
{
    queue<int> q; // space complexity O(V)
    q.push(src);
    vis[src] = true;

    while (!q.empty()) // O(V) Number of vertices
    {
        int par = q.front();
        q.pop();
        cout << par << " ";

        for (int child : adj_list[par]) // O(E) Number of edges, Here this loop does not depend on the number of nodes (parent while loop). so the time complexity is O(V+E)
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    bfs(0);
    return 0;
}