#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

struct pt {
    i64 x, y;
};

i64 cross(pt A, pt B, pt P) {
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

bool inside(array<pt, 4>& rect, pt &P) {
    bool sign = cross(rect[0], rect[1], P) >= 0;
    for (int i = 1; i < 4; ++i) {
        if ((cross(rect[i], rect[(i + 1) % 4], P) >= 0) != sign)
            return false;
    }
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d; cin >> n >> d;
    array<pt, 4> r = {
        pt{0, d}, 
        pt{d, 0}, 
        pt{n, n - d}, 
        pt{n - d, n}  
    };
    int m; cin >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        pt p = {x, y};
        if (inside(r, p)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}