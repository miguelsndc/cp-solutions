#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

const ld EPS = 1e-9;
bool eq(ld a, ld b) { return abs(a - b) < EPS; }  // ==
bool lt(ld a, ld b) { return a + EPS < b; }       // <
bool gt(ld a, ld b) { return a > b + EPS; }       // >
bool le(ld a, ld b) { return a < b + EPS; }       // <=
bool ge(ld a, ld b) { return a + EPS > b; }       // >=

struct Point {
    ld x, y;
    Point(ld x = 0, ld y = 0) : x(x), y(y) {}
    Point operator+(const Point& a) const { return Point(x + a.x, y + a.y); }
    Point operator-(const Point& a) const { return Point(x - a.x, y - a.y); }
    ld operator*(const Point& a) const { return (x * a.x + y * a.y); }  // DOT product  // norm // lenght^2 // inner
    ld operator%(const Point& a) const { return (x * a.y - y * a.x); }  // Cross // Vector product
    Point operator*(ll c) const { return Point(x * c, y * c); }
    Point operator/(ll c) const { return Point(x / c, y / c); }

    bool operator==(const Point& a) const { return eq(x, a.x) && eq(y, a.y); }             // for double point
    bool operator<(const Point& a) const { return eq(x, a.x) ? lt(y, a.y) : lt(x, a.x); }  // for double point
    bool operator<<(Point& a) {
        Point& p = *this;
        return eq(p % a, 0) ? lt(p * p, a * a) : lt(p % a, 0);
    }  // angle(this) < angle(a)

    // bool operator==(const Point& a) const { return x == a.x && y == a.y; }
    // bool operator<(const Point& a) const { return x != a.x ? x < a.x : y < a.y; }
    // bool operator<<(const Point& a) const {
    //     Point p = *this;
    //     return (p % a == 0) ? (p * p < a * a) : (p % a < 0);
    // }  // angle(p) < angle(a)
};

vector<Point> ch(vector<Point> pts, bool sorted = false) {
    if (!sorted) sort(begin(pts), end(pts));
    pts.resize(unique(begin(pts), end(pts)) - begin(pts));
    if (pts.size() <= 1) return pts;
    int s = 0, n = pts.size();
    vector<Point> h(2 * n + 1);
    for (int i = 0; i < n; h[s++] = pts[i++])
        while (s > 1 && (pts[i] - h[s - 2]) % (h[s - 1] - h[s - 2]) > 0)
            s--;
    for (int i = n - 2, t = s; ~i; h[s++] = pts[i--])
        while (s > t && (pts[i] - h[s - 2]) % (h[s - 1] - h[s - 2]) > 0)
            s--;
    h.resize(s - 1);
    return h;
}

/* Checks if a point is inside the convex hull: O(log(n))*/

bool inside_triangle(Point a, Point b, Point c, Point point) {
    ld s1 = abs((b - a) % (c - b));
    ld area1 = abs((point - a) % (point - b));
    ld area2 = abs((point - b) % (point - c));
    ld area3 = abs((point - c) % (point - a));
    ld s2 = area1 + area2 + area3;
    return s1 == s2;
}
bool strictly_inside_triangle(Point a, Point b, Point c, Point point) {
    ld area = abs((b - a) % (c - a));
    ld area1 = abs((point - a) % (point - b));
    ld area2 = abs((point - b) % (point - c));
    ld area3 = abs((point - c) % (point - a));
    return gt(area1, 0) && gt(area2, 0) && gt(area3, 0) && eq(area1 + area2 + area3, area);
}

bool is_inside(vector<Point>& hull, Point p) {
    int n = hull.size();
    if (n == 1) return (hull.front() == p);

    int l = 1, r = n - 1;
    while (abs(r - l) > 1) {
        int mid = (r + l) / 2;
        Point to_mid = hull[mid] - hull[0];
        Point to_p = p - hull[0];
        if ((to_p % (to_mid)) < 0)
            r = mid;
        else
            l = mid;
    }
    return strictly_inside_triangle(hull[0], hull[l], hull[r], p);
}

void solve() {
    int n;
    ld h;
    cin >> n;
    cin >> h;
    vector<array<ld, 3>> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i][0] >> pts[i][1] >> pts[i][2];
    ld ptx, pty;
    cin >> ptx >> pty;
    ld lo = 0, hi = 1e10, ans = -1;
    while (hi - lo > EPS) {
        ld m = lo + (hi - lo) / 2.0;
        ld nh = h - m;

        vector<Point> new_pts;
        for (auto [x, y, height] : pts) {
            if (height >= nh) {
                new_pts.push_back({x, y});
            }
        }

        vector<Point> hull = ch(new_pts);
        reverse(all(hull));

        Point pt = {ptx, pty};
        if (is_inside(hull, pt)) {
            hi = m;
            ans = m;
        } else {
            lo = m;
        }
    }
    if (eq(ans, -1)) {
        cout << "-1\n";
    } else {
        cout << setprecision(20) << fixed << ans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}