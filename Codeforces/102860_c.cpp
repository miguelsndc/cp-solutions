#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int k, n; 
    cin >> k >> n;
    vector<int> a(k);
    for (int &i: a) cin >> i;
    ll cnt = 0, cur = n;
    for (int x : a) {
        if (x <= cur) {
            cur -= x;
            if (cur == 0) {
                cnt++; cur = n;
            }
        }
    }
    if (cur == n) cur = 0;
    cout << cnt << '\n' << cur << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
