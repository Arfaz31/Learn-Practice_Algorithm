#include <bits/stdc++.h>
using namespace std;

int par[100005];
int group_size[100005]; // প্রতিটা component এর size রাখবে

// parent খোঁজার function (path compression সহ)
int find(int node)
{
    if (par[node] == -1)
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
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    vector<pair<int, int>> rmv;    // কোন কোন edge বাদ দিতে হবে
    vector<pair<int, int>> create; // কোন নতুন edge যোগ করতে হবে

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB)
        {
            rmv.push_back({a, b}); // একই component এ হলে cycle → বাদ দিতে হবে
        }
        else
        {
            dsu_union(a, b); // আলাদা হলে একসাথে connect
        }
    }

    // এখন সব node কে 1 নাম্বার node এর সাথে connect করবো
    for (int i = 2; i <= n; i++)
    {
        int leader1 = find(1);
        int leader2 = find(i);
        if (leader1 != leader2)
        {
            create.push_back({1, i}); // নতুন edge add করতে হবে
            dsu_union(1, i);          // connect করে দেওয়া
        }
    }

    cout << rmv.size() << endl;

    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;
    }

    return 0;
}