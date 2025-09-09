#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

int bfs(int src, int dst, int n)
{
    vector<bool> vis(n, false);
    vector<int> level(n, -1);

    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
    return level[dst];
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
        adj_list[b].push_back(a); // undirected
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;
        cout << bfs(src, dst, n) << endl;
    }

    return 0;
}
