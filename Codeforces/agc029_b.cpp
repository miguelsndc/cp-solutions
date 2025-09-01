#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void solve() {
    int N; cin >> N;
    vector<ll> A(N);
    vector<int> marked(N, 0);
    for (ll &i: A) cin >> i;
    sort(all(A));

    map<ll, set<int>> mp;
    for (int i = 0; i < N; i++) mp[A[i]].insert(i);

    for (int i = N - 1; i >= 0; i--) {
        if (marked[i]) continue;
        int partner_idx = -1;
        ll partner_val = -1;
        for (ll pw = 1LL; pw <= (1LL << 32); pw <<= 1) {
            ll need = pw - A[i];
            if (mp.count(need)) {
                auto &s = mp[need];
                while (!s.empty() && marked[*s.begin()])
                    s.erase(s.begin());
                if (!s.empty() && (need != A[i] || *s.begin() != i)) {
                    partner_idx = *s.begin();
                    partner_val = need;
                    break; 
                }
            }
        }

        if (partner_idx != -1) {
            marked[i] = marked[partner_idx] = 1;
            mp[partner_val].erase(partner_idx);
        }
    }

    int ans = accumulate(all(marked), 0);
    cout << ans / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
