#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
struct CHT {
    struct Line {
        long long m, b;
        long long eval(long long x) { return m * x + b; }
    };
    deque<Line> hull;

    bool bad(Line l1, Line l2, Line l3) {
        return (__int128)(l3.b - l1.b) * (l1.m - l2.m)
             <= (__int128)(l2.b - l1.b) * (l1.m - l3.m);
    }
    void add(long long m, long long b) {
        Line l = {m, b};
        while (hull.size() >= 2 && bad(hull[hull.size()-2], hull.back(), l))
            hull.pop_back();
        hull.push_back(l);
    }
    long long query(long long x) {
        while (hull.size() >= 2 && hull[0].eval(x) >= hull[1].eval(x))
            hull.pop_front();
        return hull.front().eval(x);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> queries(n), p(n);
    CHT cht;
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](int v1,int v2) {
        return queries[v1] < queries[v2];
    });
    vector<pair<int,int>> lines(m);
    for (int i = 0; i < m; i++) cin >> lines[i].first >> lines[i].second;
    sort(lines.begin(), lines.end());
    for (auto [m, b]: lines) {
        cht.add(-m, -b);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = -cht.query(queries[p[i]]);
    }
    ll v = 0;
    for (int x: ans) (v += x) %= (1000000007);
    cout << v << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}