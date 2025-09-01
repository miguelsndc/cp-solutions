#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int maxn = 1e6;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> v(n);
    vector<int> a, queries(q);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        a.push_back(v[i].first);
        a.push_back(v[i].second);
    }
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        a.push_back(t);
        queries[i] = t;
    }
    vector<int> ps(maxn);
    sort(begin(a), end(a));
    a.resize(unique(begin(a), end(a)) - begin(a));
    for (int i = 0; i < n; i++) {
        int left = lower_bound(begin(a), end(a), v[i].first) - begin(a);
        int right = lower_bound(begin(a), end(a), v[i].second) - begin(a);
        ps[left]++;
        ps[right + 1]--;
    }
    for (int i = 0; i < maxn; i++) {
        ps[i + 1] += ps[i];
    }
    for (int qu: queries) {
        cout << ps[lower_bound(begin(a), end(a), qu) - begin(a)] << '\n';
    }
}