#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{

    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m; // row and col input

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

// solutin 2- bfs
//  #include <bits/stdc++.h>
//  using namespace std;

// char grid[1005][1005];
// bool vis[1005][1005];

// vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// int n, m;

// bool valid(int i, int j) {
//     return (i >= 0 && i < n && j >= 0 && j < m);
// }

// void bfs(int si, int sj) {
//     queue<pair<int, int>> q;
//     q.push({si, sj});
//     vis[si][sj] = true;

//     while (!q.empty()) {
//         auto current = q.front();
//         q.pop();
//         int i = current.first;
//         int j = current.second;

//         for (auto &dir : directions) {
//             int ci = i + dir.first;
//             int cj = j + dir.second;
//             if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.') {
//                 vis[ci][cj] = true;
//                 q.push({ci, cj});
//             }
//         }
//     }
// }

// int main() {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> grid[i][j];
//         }
//     }

//     memset(vis, false, sizeof(vis));
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (!vis[i][j] && grid[i][j] == '.') {
//                 cnt++;
//                 bfs(i, j);
//             }
//         }
//     }
//     cout << cnt << endl;
//     return 0;
// }