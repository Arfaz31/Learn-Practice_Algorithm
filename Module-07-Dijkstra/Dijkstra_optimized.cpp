#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[105];
int dis[105];

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // src er distance 0;
    dis[src] = 0;
    while (!pq.empty()) // O(V)
    {
        pair<int, int> par = pq.top();
        pq.pop(); // O(Vlogv)
        int par_node = par.second;
        int par_dis = par.first;
        for (auto child : adj_list[par_node]) // O(E)
        {
            int child_node = child.first;
            int child_dis = child.second;
            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node}); // O(ElogV)
            }
        }
    }
}

// Time Complexity: O(Vlogv+ElogV) = O((V+E)logV) = O(ElogV)

int main()
{
    int n, e; // n = no. of nodes, e = no. of edges
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}