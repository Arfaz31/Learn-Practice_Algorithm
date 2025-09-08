#include <bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005]; // প্রতিটা component এর size রাখবে
int cmp, mx;          // cmp = কতগুলো component আছে, mx = সবচেয়ে বড় component এর size

// parent খোঁজার function (path compression সহ)
int find(int node)
{
    if (par[node] == -1) // যদি কোনো parent না থাকে, সে নিজেই leader
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

// দুটি নোডকে একই group এ merge করার function
void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (leader1 == leader2) // একই leader মানে আগে থেকেই same component
        return;
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx, group_size[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }
    cmp--; // দুইটা component merge হলো → মোট component সংখ্যা ১টা কমলো
}

int main()
{
    int n, e;
    cin >> n >> e;
    cmp = n;
    mx = 1;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b); // নতুন edge যোগ হলে দুটি city merge করবো
        cout << cmp << " " << mx << endl;
    }

    return 0;
}