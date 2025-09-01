#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
const int mxn = 6e5;
const int inf = 1e9 + 1;
void solve() {
    int N, k;
    scanf("%d", &N);
    scanf("%d", &k);
    vector<int> f(mxn,inf), a(k);
    for (int i = 0; i < k; i++) scanf("%d", &a[i]);
    f[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int x : a) {
            if (i - x >= 0) {
                f[i] = min(f[i], f[i - x] + 1);
            }
        }
    }
    if (f[N] == inf) {
        printf("Roberta acknowledges defeat.");
    } else {
        printf("Roberta wins in %d strokes.", f[N]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}