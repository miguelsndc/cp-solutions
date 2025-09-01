#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    // keep sorted
    // keep taking the smallest out
    // priority queue!
    priority_queue<int, vector<int>, greater<int>> pqueue;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pqueue.push(t);
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int a = pqueue.top();
        pqueue.pop();
        int b = pqueue.top();
        pqueue.pop();
        pqueue.push(a + b);
        ans += a + b;
    }

    cout << ans;

    return 0;
}
