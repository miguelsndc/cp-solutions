#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, D; cin >> n >> D;
    vector<int> a(n + 1);
    for (int i = 1; i <= D; i++) {
        int x, y; cin >> x >> y;
        a[x]++; a[y]++;
    } 
    int m = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(a[i]);
        m = max(m, a[i]);
    }
    while(pq.top() < m) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        x++, y++;
        m = max({m, x, y});
        pq.push(x);
        pq.push(y);
    }

    cout << m << '\n';
}