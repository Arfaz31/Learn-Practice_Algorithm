#include <bits/stdc++.h>
using namespace std;
int val[1005], wt[1005];

int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
    {
        return 0;
    }

    if (wt[i] <= mx_weight)
    {
        int op1 = knapsack(i - 1, mx_weight - wt[i]) + val[i];
        int op2 = knapsack(i - 1, mx_weight);
        return max(op1, op2);
    }
    else
    {
        return knapsack(i - 1, mx_weight);
    }
};

// Time complexity O(2^N);

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

    knapsack(n - 1, mx_weight);

    return 0;
}