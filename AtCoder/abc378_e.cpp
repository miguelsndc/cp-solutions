#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int maxn = 1e6 + 5;
vector<ll> bit(maxn);
void add(int pos, int val) {
	++pos; 
	while (pos < maxn) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

ll query(int pos) {
	++pos;
	ll sum = 0;
	while(pos > 0) {
		sum += bit[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}
void solve() {
    ll N, M; cin >> N >> M;
    vector<int> A(N);
    for (int & i: A) cin >> i;
    vector<ll> ps(N + 1);
    for (int i = 0; i < N; i++) ps[i + 1] = ps[i] + A[i];
    for (int i = 0; i <= N; i++) ps[i] %= M;
    ll ans = 0, left = 0;
    for (int r = 0; r <= N; r++) {
        (ans += r * ps[r] - left + (query(M + 1) - query(ps[r])) * M);
        left += ps[r];
        add(ps[r], 1);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}