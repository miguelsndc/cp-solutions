#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
    Point operator-(const Point& a) const { return Point(x - a.x, y - a.y); }
    ll operator%(const Point& a) const { return x * a.y - y * a.x; } 
    bool operator<(const Point& a) const { return x != a.x ? x < a.x : y < a.y; }
    bool operator==(const Point& a) const { return x == a.x && y == a.y; }
};
vector<Point> ch(vector<Point> pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() <= 1) return pts;
    int n = pts.size(), k = 0;
    vector<Point> h(2 * n);
    for (int i = 0; i < n; i++) {
        while (k >= 2 && (h[k-1] - h[k-2]) % (pts[i] - h[k-2]) > 0) k--;
        h[k++] = pts[i];
    }
    for (int i = n-2, t = k; i >= 0; i--) {
        while (k > t && (h[k-1] - h[k-2]) % (pts[i] - h[k-2]) > 0) k--;
        h[k++] = pts[i];
    }
    h.resize(k-1);
    return h;
}

void solve() {
    int n, l;
    cin >> n >> l;
    vector<Point> a;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({x + l, y});
        a.push_back({x - l, y});
        a.push_back({x, y + l});
        a.push_back({x, y - l});
    }
    vector<Point> hull = ch(a);
    long double ans = 0;
    int m = hull.size();
    for (int i = 0; i < m; i++) {
        int j = (i + 1) % m;
        ans += hypotl(hull[j].x - hull[i].x, hull[j].y - hull[i].y);
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while (T--) solve();
}
