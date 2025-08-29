#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({10, 2});
    pq.push({5, 1});
    pq.push({15, 3});
    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}