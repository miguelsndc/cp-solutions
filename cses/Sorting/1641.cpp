#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first; a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t = x - (a[i].first + a[j].first);
            if (t < 0) continue;
            int lb = lower_bound(a.begin(), a.end(), make_pair(t, INT_MIN)) - a.begin();
            int ub = upper_bound(a.begin(), a.end(), make_pair(t, INT_MAX)) - a.begin() - 1;
            if (lb == n) continue;
            for (int x = lb; x <= ub; x++) {
                if (x != i and x != j) {
                    cout << a[x].second << ' ' << a[i].second << ' ' << a[j].second << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}