#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int level[1005];

void bfs(int src)
{
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
    memset(level, -1, sizeof(level));

    bfs(0); // source always 0

    int L;
    cin >> L;

    vector<int> nodesAtLevel;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == L)
        {
            nodesAtLevel.push_back(i);
        }
    }

    sort(nodesAtLevel.rbegin(), nodesAtLevel.rend()); // descending order

    for (int node : nodesAtLevel)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
