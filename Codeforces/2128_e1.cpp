#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
array<int,3> f(vector<int> &a, int k) {
    const int n = a.size();
    int lo = 1, hi = n;
    vector<int> pre(n + 1);
    int L = 0, R = n;
    while(lo < hi) {
        int x = (lo + hi + 1) / 2;
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + (a[i] >= x ? 1 : -1);
        }
        int min = 0, ok = false;
        int L0 = 0, R0 = 0;
        for (int i = k; i <= n; i++) {
            if (pre[i-k] < min) {
                min = pre[i-k];
                L0 = i - k;
            }
            if (pre[i] >= min) {
                ok = true;
                R0 = i;
                break;
            }
        }
        if (ok){
            lo = x;
            L = L0;
            R = R0;
        } else  {
            hi = x - 1;
        }
    }
    return {lo, L ,R};
}
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int&x:a)cin>>x;
    auto [mx, l, r] = f(a, k);
    cout << mx << ' ' << l + 1 << ' ' << r << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}