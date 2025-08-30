#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
int level[105][105];
int n, m;
vector<pair<int, int>> d = {{2, -1}, {1, -2}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
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
            if (valid(i, j) && !vis[i][j])
            {
                q.push({i, j});
                vis[i][j] = true;
                level[i][j] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(si, sj);
        cout << level[di][dj] << endl;
    }
    return 0;
}