#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> build_sa(vector<ll> &s) {
    s.push_back(0);
    ll n = s.size();
    const ll ALPHA = *max_element(s.begin(), s.end()) + 1;
    vector<ll> p(n), c(n), cnt(max(ALPHA, n));
    for (ll i = 0; i < n; i++) cnt[s[i]]++;
    for (ll i = 1; i < ALPHA; i++) cnt[i] += cnt[i - 1];
    for (ll i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0; ll classes = 1;
    for (ll i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }
    vector<ll> pn(n), cn(n);
    for (ll h = 0; (1LL << h) < n; h++) {
        for (ll i = 0; i < n; i++) {
            pn[i] = p[i] - (1LL << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (ll i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (ll i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for (ll i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0; 
        ll new_classes = 1;
        for (ll i = 1; i < n; i++) {
            pair<ll, ll> cur = {c[p[i]], c[(p[i] + (1LL << h)) % n]};
            pair<ll, ll> prev = {c[p[i-1]], c[(p[i-1] + (1LL << h)) % n]};
            if (cur != prev) ++new_classes;
            cn[p[i]] = new_classes - 1;
        }
        c.swap(cn);
        swap(classes, new_classes);
    }
    return p;
}

vector<ll> build_lcp(vector<ll> &s, vector<ll> &sa) {
    ll n = s.size();
    vector<ll> rank(n, 0);
    for (ll i = 0; i < n; i++) rank[sa[i]] = i;
    ll k = 0;
    vector<ll> lcp(n - 1, 0);
    for (ll i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0; continue;
        }
        ll j = sa[rank[i] + 1];
        while (i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if(k) k--;
    }
    return lcp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    vector<ll> sa = build_sa(a);
    vector<ll> lcp = build_lcp(a, sa);

    ll m = lcp.size();
    vector<ll> left(m), right(m);
    vector<pair<ll,ll>> s1, s2;
    for (ll i = 0; i < m; i++) {
        ll cnt = 1;
        while (!s1.empty() and s1.back().first > lcp[i]) {
            cnt += s1.back().second;
            s1.pop_back();
        }
        s1.push_back({lcp[i], cnt});
        left[i] = cnt;
    }
    for (ll i = m - 1; i >= 0; --i) {
        ll cnt = 1;
        while (!s2.empty() && s2.back().first >= lcp[i]) {
            cnt += s2.back().second;
            s2.pop_back();
        }
        s2.push_back({lcp[i], cnt});
        right[i] = cnt;
    }
    ll minsum = 0;
    for (ll i = 0; i < m; i++) {
        minsum += 1LL * lcp[i] * left[i] * right[i];
    }
    ll total = minsum * 2 +  n * (n+1) / 2;
    ll pares = 1LL * n * n;
    ll g = __gcd(total, pares);
    cout << (total/g) << '/' << (pares/g) << '\n';
    return 0;
}