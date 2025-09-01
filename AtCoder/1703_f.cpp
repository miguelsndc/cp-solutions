#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    vector<int> ps(N + 1);
    ll r = 0;
    for (int j = 1; j <= N; j++) {
        if (A[j] < j) {
            if (A[j] - 1 >= 0) {
                r += ps[A[j] - 1];
            }
            ps[j]++;
        }
        ps[j] += ps[j - 1];
    }
    cout << r << '\n';
}
int main() {
    int T = 1; scanf("%d", &T);
    while(T--) solve();
}