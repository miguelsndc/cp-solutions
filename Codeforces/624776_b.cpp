#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define M_PI acos(-1.0)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, r;
    cin >> n >> r;
    vector<array<int, 3>> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i][0] >> lines[i][1] >> lines[i][2];
    }
    ld bestdiff = 1e18, bestratio = 1, target = 0.5;
    for (int i = 0; i < n; i++) {
        ld A = lines[i][0], B = lines[i][1], C = lines[i][2];
        ld denom = A * A + B * B;
        ld dist = fabsl(C) / sqrtl(denom);
        ld theta = 2 * acosl(dist / r);
        ld a1 = 0.5 * r * r * (theta - sinl(theta));
        ld cur = a1 / (M_PI * r * r);
        ld diff = fabsl(cur - target);
        if (diff < bestdiff) {
            bestdiff = diff;
            bestratio = cur;
        }
    }
    cout << setprecision(15) << fixed << bestratio << " " << 1 - bestratio << "\n";
    return 0;
}