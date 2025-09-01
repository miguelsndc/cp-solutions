#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, d; cin >> r >> d;
    int n; cin >> n;
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i++) {
        int x, y, r; cin >> x >> y >> r;
        v[i] = {x, y, r};
    }
    /*
        pizza has radius r crust has d with
        so radius of actual pizza is r - d
        if distance between sausage with center (x,y) and center of pizza (0,0)
        is greater than sum of their radii then it is contained
    */
    int pr =  r - d, cnt = 0;
    for (auto [x, y, sr]: v) {
        double dc = hypot(1.0 * x, 1.0 * y);
        if (dc + sr <= r  and dc - sr >= r - d) {
            cnt++;
        }
    }
    cout << cnt;
}