#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    int draws = 0;
    priority_queue<int> pq;
    pq.push(p1);
    pq.push(p2);
    pq.push(p3);
    while(pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        if (x == 0 or y == 0) {
            pq.push(x);
            pq.push(y);
            break;
        }
        pq.push(--x);
        pq.push(--y);
        draws++;
    }
    int s = 0;
    while(!pq.empty()) { s += pq.top(); pq.pop(); }

    if (s & 1) {
        cout << -1 << '\n';
        return;
    }

    cout << draws << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}