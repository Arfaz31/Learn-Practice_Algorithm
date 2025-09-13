#include <bits/stdc++.h>
using namespace std;
long long int dp[100005];

bool canReach(int current, int n)
{
    // Base case: If current value is equal to n, we reached it.
    if (current == n)
        return true;
    // Base case: If current value exceeds n, we cannot reach n from this path.
    if (current > n)
        return false;

    // Memoization: If result for 'current' is already computed, return it.
    // dp[current] == 1 means true, dp[current] == 0 means false
    if (dp[current] != -1)
        return dp[current];

    // Recursive calls for both possible operations: add 3 or multiply by 2
    // If either path leads to n, then it's possible.
    bool res = canReach(current + 3, n) || canReach(current * 2, n);

    // Store the result in dp array and return it
    dp[current] = res; // Store 1 for true, 0 for false
    return res;
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }

        if (canReach(1, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}