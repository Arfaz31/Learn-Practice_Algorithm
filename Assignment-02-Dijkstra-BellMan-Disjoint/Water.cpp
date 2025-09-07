#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        int height1 = INT_MIN, height2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (h[i] > height1)
            {
                height2 = height1;
                height1 = h[i];
            }
            else if (h[i] > height2) // for second largest value. jodi if condtion false hoy means h[i] er value height1 er beshi na then jodi h[i] er value height2 er beshi hoy tahole height2 update hobe.
            {
                height2 = h[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (h[i] == height1)
            {
                cout << i << " ";
            }
            else if (h[i] == height2)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
