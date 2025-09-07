#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];

int find(int node) // O(logN)
{

    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader; // পাথ কমপ্রেশন: নোডের প্যারেন্টকে সরাসরি লিডারের সাথে যুক্ত করে দেয়, যাতে পরেরবার এই নোড বা এর চাইল্ড নোডগুলো খুঁজতে গেলে দ্রুত লিডার পাওয়া যায়।
    return leader;
};

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1; // ছোট সেটের লিডারকে বড় সেটের লিডারের চাইল্ড বানিয়ে দেয়।
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
    memset(par, -1, sizeof(par));              // সব নোডের প্যারেন্টকে -1 দিয়ে ইনিশিয়ালাইজ করে, মানে প্রাথমিকভাবে প্রতিটি নোড নিজেই একটি সেটের লিডার।
    memset(group_size, 1, sizeof(group_size)); // প্রাথমিকভাবে প্রতিটি সেটের সাইজ 1, কারণ প্রতিটি নোড একটি একক সেটের অংশ।

    int n, e;
    cin >> n >> e;
    bool cycle = false;
    while (e--)
    {
        int a, b; // edge
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB) // যদি দুটি নোডের লিডার একই হয়, তাহলে এই এজটি যোগ করলে একটি সাইকেল তৈরি হবে।
            cycle = true;
        else
            dsu_union(a, b);
    }

    if (cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle Detected" << endl;

    return 0;
}