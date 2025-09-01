#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0; // diagnolal
            }
            else
            {
                adj_mat[i][j] = INT_MAX;
            }
        }
    }

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj_mat[a][b] = w;
        // adj_mat[b][a] = w; // for undirected graph
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    bool cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[i][i] < 0) // if the value of the diagnol is negative then there is a negative cycle
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Weighted cycle present" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << adj_mat[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}