#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T>
class SparseTable {
private:
    int n, k;
    std::vector<std::vector<T>> st;
    std::function<T(const T&, const T&)> func;

public:
    SparseTable(const std::vector<T>& v, std::function<T(const T&, const T&)> f) : func(f) {
        n = v.size();
        k = 32 - __builtin_clz(n);
        st.resize(k);
        st[0] = v;
        for (int i = 1; i < k; ++i) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; ++j)
                st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    T query(int l, int r) const {
        int p = 31 - __builtin_clz(r - l + 1);
        return func(st[p][l], st[p][r - (1 << p) + 1]);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 3) {
        cout << -1 << '\n';
        return;
    }

    auto cmin = [](int a, int b) { return min(a, b); };
    auto cmax = [](int a, int b) { return max(a, b); };

    SparseTable<int> rminq(a, cmin);
    SparseTable<int> rmaxq(a, cmax);

    int l = 0, r = n - 1;

    while (l < r) {
        int minq = rminq.query(l, r);
        int maxq = rmaxq.query(l, r);

        bool changed = false;
        if (a[l] == minq or a[l] == maxq) {
            l++;
            changed = true;
        }
        if (a[r] == minq or a[r] == maxq) {
            r--;
            changed = true;
        }

        if (!changed) {
            cout << l + 1 << ' ' << r + 1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}