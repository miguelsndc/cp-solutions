#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
#define int ll
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    if (n == 1) {
        cout << "YES\n";
        cout << "1 0\n";
        cout << "0 1\n";
        return 0;
    } else if (n == 2) {
        pair<int,int> v = {pts[1].x - pts[0].x, pts[1].y - pts[0].y};
        if (v.x == 0 and v.y == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << v.x << ' ' << v.y << '\n'; 
            cout << -v.y << ' ' << v.x << '\n';
        }
        return 0;
    }
    vector<pair<int,int>> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
        d[i].x = pts[i + 1].x - pts[i].x;
        d[i].y = pts[i + 1].y - pts[i].y;
    }
    pair<int,int> dm = d[0];
    for (int i = 1; i < n - 1; i++) {
        ll cross = dm.x * d[i].y - dm.y * d[i].x;
        if (cross > 0) {
            dm = d[i];
        }
    }
    pair<int,int> oy = dm;
    pair<int,int> ox = {oy.y, -oy.x};
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        ll dot = ox.x * d[i].x + ox.y * d[i].y;
        ok &= (dot >= 0);
        if (dot == 0) {
            ll dot2 = oy.x * d[i].x + oy.y * d[i].y;
            ok &= (dot2 > 0);
        }
    }
    if (ok) {
        cout << "YES\n" << ox.x << ' ' << ox.y << '\n' << oy.x << ' ' << oy.y << '\n';
    } else {
        cout << "NO\n";
    }
}