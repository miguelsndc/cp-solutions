#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = long double;
constexpr i64 inf = 1E18;

typedef pair<f64, f64> pt;
#define x first 
#define y second

f64 dist(pt p1, pt p2) {
    return sqrtl((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    i64 n, k; cin >> n >> k;
    vector<pt> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    f64 walked = 0, high_y = p[0].y;
    for (int i = 0; i < n - 1; i++) {
        f64 d = dist(p[i], p[i + 1]);
        if (walked + d > k) {
            // pegar o vetor pi -> pi + 1
            pt to = {p[i + 1].x - p[i].x, p[i + 1].y - p[i].y}; 
            double norm = hypot(to.x, to.y);
            to.x /= norm;
            to.y /= norm;
            to.x *= (k - walked);
            to.y *= (k - walked);
            high_y = max(high_y, p[i].y + to.y);
            break;
        } else {
            walked += d;
            high_y = max(high_y, max(p[i].y, p[i + 1].y));
        }
    }
    cout << setprecision(20) << fixed <<  high_y;
}