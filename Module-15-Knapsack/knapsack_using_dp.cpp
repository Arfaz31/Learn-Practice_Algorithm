#include <bits/stdc++.h>
using namespace std;
int val[1005], wt[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weight)
{
    // base case: no items or no capacity left
    if (i < 0 || mx_weight <= 0)
    {
        return 0;
    }

    // if already calculated, return from dp
    if (dp[i][mx_weight] != -1)
    {
        return dp[i][mx_weight];
    }

    // if current item can fit into remaining capacity
    if (wt[i] <= mx_weight)
    {
        // option 1: take this item
        int op1 = knapsack(i - 1, mx_weight - wt[i]) + val[i];
        // option 2: skip this item
        int op2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(op1, op2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = knapsack(i - 1, mx_weight);
        return dp[i][mx_weight];
    }
};

// Time complexity O(NW);

int main()
{
    int n, mx_weight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cin >> mx_weight;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= mx_weight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n - 1, mx_weight) << endl;

    return 0;
}