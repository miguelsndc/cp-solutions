#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int maxn = 3e5 + 5;
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
    int N; cin >> N;
    vector<int> A(N);
    for (int &i: A) cin >> i;
    ll ans = 0;
    for (int a: A) {
        ans += query(N) - query(a);
        add(a, 1);
    }
    for (int a: A) {
        cout << ans << '\n';
        ans += N - 1 - 2 * a;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}