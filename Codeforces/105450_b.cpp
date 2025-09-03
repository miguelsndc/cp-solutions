#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

void solve() {
    ll x1, y1, s1;
    cin >> x1 >> y1 >> s1;
    ll x2, y2, s2;
    cin >> x2 >> y2 >> s2;
    ll x1_min = x1;
    ll x1_max = x1 + s1;
    ll y1_min = y1;
    ll y1_max = y1 + s1;
    ll x2_min = x2;
    ll x2_max = x2 + s2;
    ll y2_min = y2;
    ll y2_max = y2 + s2;
    bool c1 = (x1_max < x2_min) || (x2_max < x1_min) || (y1_max < y2_min) || (y2_max < y1_min);
    bool c2 = (x2_min <= x1_min) && (x1_max <= x2_max) && (y2_min <= y1_min) && (y1_max <= y2_max);
    bool c3 = (x1_min <= x2_min) && (x2_max <= x1_max) && (y1_min <= y2_min) && (y2_max <= y1_max);
    bool c4 = c2 ^ c3;
    if (c1 || c4) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while(T--) solve();
}