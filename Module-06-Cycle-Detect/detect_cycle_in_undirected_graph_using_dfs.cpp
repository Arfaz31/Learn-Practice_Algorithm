#include <bits/stdc++.h>
using namespace std;

bool vis[105];
vector<int> adj_list[105];
int parent[105];
bool cycle;
void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] && parent[src] != child) // parent er parent != child hole cycle ache. suppose src = 1, 1 er parent 0, and 0 theke both 1,2 te jaoa jai, first time ei as a first src hisebe both 1 and 2 visited. ekhon parent[1] == 0 hole cycle nei(karon 1 er parent holo 0 so 0 == 0) but parent[1] != 2 hole cycle ache(bcz 0 != 2)
        {
            cycle = true;
        }
        if (!vis[child])
        {
            parent[child] = src; // child er parent hobe src
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
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<" parent: "<<parent[i]<<endl;
    // }

    if (cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "NO Cycle" << endl;
    return 0;
}
