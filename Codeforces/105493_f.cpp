#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, s, f; cin >> n >> s >> f;
    ll st, ed;
    vector<pair<ll,ll>> v;
    for(int i=0; i<n;i++) {
        cin >> st >> ed;
        if (ed < s || st > f) continue;
        v.push_back({max(st,s), 1});
        v.push_back({min(ed,f), 0});
    }
    sort(v.begin(),v.end());
    ll lt = s, ops = 0;
    vector<ll> c(1000005);
    for (auto [T, open]: v) {
        c[ops] += T - lt;
        ops += (open == 1 ? 1: -1);
        lt = T;
    }
    if (lt < f) {
        c[ops] += f - lt;
    }
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = (ll)a[i - 1] + c[i - 1];
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}