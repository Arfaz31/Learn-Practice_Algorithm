#include <bits/stdc++.h>
using namespace std;

bool vis[105];
vector<int> adj_list[105];
bool pathvisit[105];
bool cycle;
void dfs(int src)
{
    vis[src] = true;
    pathvisit[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] && pathvisit[child])
        {
            cycle = true;
        }
        if (!vis[child])
        {

            dfs(child);
        }
    }
    pathvisit[src] = false; // recursion stack এ উপরের nodes গুলোর জন্যও backtrack হবে, সব node এর pathvisit false হয়ে যাবে।
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
    }
    memset(vis, false, sizeof(vis));
    memset(pathvisit, false, sizeof(pathvisit));
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
