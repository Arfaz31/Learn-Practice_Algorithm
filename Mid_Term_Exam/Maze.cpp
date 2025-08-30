#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Right, Left, Up, Down
int row, col;

bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        for (auto c : d)
        {
            int i = par_i + c.first;
            int j = par_j + c.second;
            if (valid(i, j) && !vis[i][j] && grid[i][j] != '#')
            {
                q.push({i, j});
                vis[i][j] = true;
                level[i][j] = level[par_i][par_j] + 1;
                parent[i][j] = {par_i, par_j};
            }
        }
    }
}

int main()
{
    cin >> row >> col;

    int si = -1, sj = -1, di = -1, dj = -1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            else if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(si, sj);

    if (vis[di][dj] == true)
    {
        int node_i = di, node_j = dj;
        while (1)
        {
            pair<int, int> par = parent[node_i][node_j];
            node_i = par.first;
            node_j = par.second;
            if (grid[node_i][node_j] == 'R')
            {
                break;
            }
            grid[node_i][node_j] = 'X';
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}