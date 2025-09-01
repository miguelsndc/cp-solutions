#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<ll> coords(n);
    for (int i = 0; i < n; i++) cin >> coords[i];
    sort(all(coords));
    priority_queue<ll> pq;
    for (int i = 1; i < n; i++) {
        pq.push(coords[i] - coords[i - 1]);
    }
    ll ans = coords[n - 1] - coords[0];
    for (int x = 0; x < m - 1; x++) {
        if (pq.size() > 0) {
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}