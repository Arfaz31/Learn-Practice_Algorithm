#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e, q;
    cin >> n >> e >> q;
    long long int adj_mat[n + 5][n + 5]; // ei matrix ei input nicchi abar eta kei distance matrix hisebe use korchi. 5 bariye neoa hoise karon 1 based index use korechi

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0; // diagnolal
            }
            else
            {
                adj_mat[i][j] = LLONG_MAX;
            }
        }
    }

    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        adj_mat[a][b] = min(adj_mat[a][b], w); // minimum weight nite hobe.
        adj_mat[b][a] = min(adj_mat[b][a], w); // for undirected graph
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    while (q--)
    {
        int a, b; // protibar src change hocche tai Floyd Warshall Algorithm use korchi
        cin >> a >> b;
        if (adj_mat[a][b] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj_mat[a][b] << endl;
        }
    }
    return 0;
}