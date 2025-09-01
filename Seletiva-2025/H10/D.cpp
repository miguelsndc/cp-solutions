#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using f64 = double;

constexpr i64 inf = 1E18;
struct Point {
	i64 x, y;
	Point(i64 x = 0, i64 y = 0) : x(x), y(y) {}
	Point operator- (const Point&a) const{ return Point(x-a.x, y-a.y); }
	i64 operator% (const Point&a) const{ return  (x*a.y - y*a.x); }	
	bool operator==(const Point&a) const{ return x == a.x && y == a.y; }
	bool operator< (const Point&a) const{ return x != a.x ? x < a.x : y < a.y; }
};

vector<Point> ch(vector<Point> pts, bool sorted=false) {
	if(!sorted) sort(begin(pts), end(pts));
	pts.resize(unique(begin(pts), end(pts)) - begin(pts));
	if(pts.size() <= 1) return pts;
	int s = 0, n = pts.size();
	vector<Point> h (2 * n + 1);
	for(int i=0; i<n; h[s++] = pts[i++])
		while(s > 1 && (pts[i] - h[s-2]) % (h[s-1] - h[s-2]) > 0 )
			s--;
	for(int i=n-2, t=s; ~i; h[s++] = pts[i--])
		while(s > t && (pts[i] - h[s-2]) % (h[s-1] - h[s-2]) > 0 )
			s--;
	h.resize(s - 1);
	return h;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i].x = x;
        a[i].y = y;
    }
    auto v = ch(a);
    cout << v.size() << '\n';
    for(const auto &[x, y]: v) {
        cout << x << ' ' << y << '\n';
    }
}