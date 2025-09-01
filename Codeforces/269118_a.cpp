#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> build_sa(string &s) {
    s += '$';
    int n = s.size();
    const int ALPHA = 256;
    vector<int> p(n), c(n), cnt(max(ALPHA, n));
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < ALPHA; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0; int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0; 
        int new_classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev) ++new_classes;
            cn[p[i]] = new_classes - 1;
        }
        c.swap(cn);
        swap(classes, new_classes);
    }
    return p;
}

void solve() {	
    string t; cin >> t;
    vector<int> sa = build_sa(t);
    int n = t.size();
    int q; cin >> q;
    while(q--) {
        string si; cin >> si;
        int l = 0, r = sa.size() - 1; bool ok = false;
        while(l <= r) {
            int m = (l + r) / 2;
            int order = 0;
            int i = 0;
            // basicamente achar lcp entre as duas
            int lim = min((int)si.size(), n - sa[m]);
            while (i < lim and t[i + sa[m]] == si[i]) {
                i++;
            }
            if (i < lim and t[i + sa[m]] > si[i]) order = -1; 
            else if (i < lim and t[i + sa[m]] < si[i]) order = 1; 

            if (order == -1) {
                r = m - 1;
            } else if (order == 1) {
                l = m + 1;
            } else if (!ok) {
                ok = true;
                cout << "Yes\n";
                break;
            }
        }

        if(!ok) {
            cout << "No\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}