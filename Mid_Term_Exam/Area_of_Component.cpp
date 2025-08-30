#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int n, m, cnt, mn;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (auto d : dir)
    {
        int i = si + d.first;
        int j = sj + d.second;
        if (valid(i, j) && grid[i][j] == '.' && !vis[i][j])
        {
            dfs(i, j);
        }
    }
}

int main()
{
    cin >> n >> m;
    mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                cnt = 0;
                dfs(i, j);
                mn = min(cnt, mn);
            }
        }
    }
    if (mn == INT_MAX)
        cout << -1 << endl;
    else
        cout << mn << endl;

    return 0;
}