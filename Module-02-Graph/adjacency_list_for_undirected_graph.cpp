#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n]; // array of vectors
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // for undirected graph
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int x : adj_list[i]) // here x is iterator and adj_list[i] is vector
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}