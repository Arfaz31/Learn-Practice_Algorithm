#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_matrix[n][n];
    memset(adj_matrix, 0, sizeof(adj_matrix));
    for (int i = 0; i < n; i++)
        adj_matrix[i][i] = 1;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_matrix[a][b] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (adj_matrix[a][b] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     // adjacency list
//     vector<vector<int>> adj(n);

//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v); // directed edge
//     }

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int a, b;
//         cin >> a >> b;

//         if (a == b)
//         {
//             cout << "YES\n";
//             continue;
//         }

//         bool found = false;
//         for (int v : adj[a])
//         {
//             if (v == b)
//             {
//                 found = true;
//                 break;
//             }
//         }

//         if (found)
//             cout << "YES\n";
//         else
//             cout << "NO\n";
//     }

//     return 0;
// }
