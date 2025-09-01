#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int srcx, srcy, tx, ty; cin >> srcx >> srcy >> tx >> ty;
        tx -= srcx;
        ty -= srcy;
        tx = abs(tx);
        ty = abs(ty);
    }
}
