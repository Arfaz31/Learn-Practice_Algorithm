#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long dis[1005];
vector<Edge> edge_list;
int n, e;

bool bellman_ford(int src)
{
    // Initialize distances
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[src] = 0;

    // Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            long long c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    // Check for negative weight cycle
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        long long c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;

    bool iscyclefound = bellman_ford(src);
    if (iscyclefound)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int dest;
        cin >> dest;
        if (dis[dest] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dis[dest] << endl;
    }

    return 0;
}
