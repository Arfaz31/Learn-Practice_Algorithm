#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[1005];
vector<Edge> edge_list;
int n, e;

void bellman_ford()
{
    for (int i = 0; i < n - 1; i++) // O(V)  //bellman-ford n-1 projonto loop chalai tai cycle thakleu infite loopa jaina. n - 1 neoar reason holo protibar ekbar sob node traverse korle ekta node er shortest distance paoa jabei. ar src er distance 0 tai n-1

    {
        for (auto ed : edge_list) // edge relaxation  //O(E)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool cycle = false;

    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        int c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative Weighted Cycle Found" << endl;
    else
        cout << "Cycle Not Found" << endl;
}
// Time Complexity: O(VE)

int main()
{

    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b,a,c)); //for undirected
    }
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;
    dis[0] = 0; // src

    bellman_ford();

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> " << dis[i] << endl;
    // }

    return 0;
}