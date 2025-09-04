#include <bits/stdc++.h>
using namespace std;
int par[1005];

int find(int node) // O(logN)
{
    cout << node << endl;
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader; // keep track of the leader of each node so that it does not go to the same path again.
    return leader;
};

int main()
{
    memset(par, -1, sizeof(par));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    find(4);

    return 0;
}