#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
#define PI acos(-1.0)

array<double, 2> rotate(double x, double y, double theta) {
    return {x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)};
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r; cin >> n >> r;
    double step = 2*PI*r / n;
    double l = 1e-9, h = 10000;
    const double eps = 1e-9;
    const double angle = 2* PI / n;
    while(h - l > eps) {
        double mid = (l + h) / 2;
        typedef array<double, 3> circle; // (x, y, radius)
        vector<circle> v(n);
        array<double, 2> normal = {0, 1};
        for (int i = 0; i < n; i++) {
            v[i] = {normal[0] * (mid + r), normal[1] * (mid + r), mid};
            normal = rotate(normal[0], normal[1], angle);
        }
        bool can = true;
        for (int i = 0; i < n ; i++) {
            if ((hypot(v[i][0] - v[(i + 1) % n][0], v[i][1] - v[(i + 1) % n][1])) < (v[i][2] + v[(i + 1) % n][2])) {
                can = false;
                break;
            }
        }
        if (can) {
            l = mid;
        } else {
            h = mid;
        }
    }
    cout << setprecision(12) << fixed << l << '\n';
}