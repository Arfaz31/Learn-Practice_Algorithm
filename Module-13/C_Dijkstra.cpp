#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll, ll>> adj_list[100005];
ll dist[100005];
ll parent[100005];

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        pair<ll, ll> par = pq.top();
        pq.pop();
        ll par_node = par.second;
        ll par_dis = par.first;
        for (auto child : adj_list[par_node])
        {
            ll child_node = child.first;
            ll child_dis = child.second;
            if (dist[child_node] > par_dis + child_dis)
            {
                dist[child_node] = par_dis + child_dis;
                pq.push({dist[child_node], child_node}); // priority queue te pair rakhle priority queue sob somoy first er value k priority dei and sei onujai sort kore rakhe. tai ekhane distance first a rakha hoise.
                parent[child_node] = par_node;           // path printing er jonno parent store korte hobe
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;

    while (e--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    for (ll i = 1; i <= n; i++)
    {
        dist[i] = LLONG_MAX;
        parent[i] = -1;
    }

    dijkstra(1);
    if (dist[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        ll node = n;
        vector<ll> path;
        while (node != -1) // src er parent -1 thake
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        for (auto it : path)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}