#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool visited[105][105];
int level[105][105]; // distance ber korar jonno level track rakha hoy
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
};

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0; // src er level 0 hobe
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par_i = p.first;
        int par_j = p.second;
        // cout << par_i << " " << par_j << endl; //bfs print
        for (int i = 0; i < 4; i++)
        {
            int child_i = par_i + d[i].first;
            int child_j = par_j + d[i].second;
            if (valid(child_i, child_j) && !visited[child_i][child_j] && grid[child_i][child_j] == '.')
            {
                q.push({child_i, child_j});
                visited[child_i][child_j] = true;
                level[child_i][child_j] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    bfs(si, sj);
    cout << level[di][dj] << endl;

    return 0;
}